#include <stdio.h>
#include "engine.h"

#define BUFSIZE 1000

int main()
{
	// 1. Open MATLAB engine
	Engine *matlab = engOpen(NULL);
	if (matlab == NULL){
		printf("Can't start MATLAB engine!!!\n");
		exit(-1);
	}

	// 2. Call MATLAB engine
	{
		// 2.1. Pre-work: capture MATLAB output. Ensure the buffer is always NULL terminated.
		char buffer[BUFSIZE+1];
		buffer[BUFSIZE] = '\0';
		engOutputBuffer(matlab, buffer, BUFSIZE);
		engEvalString(matlab, "clc;clear;"); // clear all variables (optional)

		// 2.2. Setup inputs: a, b
		mxArray *a = mxCreateDoubleScalar(2); // assume a=2
		mxArray *b = mxCreateDoubleScalar(3); // assume b=3
		engPutVariable(matlab, "a", a); // put into matlab
		engPutVariable(matlab, "b", b); // put into matlab
		
		// 2.3. Call MATLAB
		engEvalString(matlab, "cd \'C:\\'");
		engEvalString(matlab, "[y, z] = myadd2(a, b);");
		printf("%s\n", buf); // get error messages or prints (optional)

		// 2.4. Get result: y, z
		mxArray *y = engGetVariable(matlab, "y");
		mxArray *z = engGetVariable(matlab, "z");
		double y_res = mxGetScalar(y);
		double z_res = mxGetScalar(z);
		printf("y=%f\nz=%f\n", y_res, z_res);

		// 2.5. Release (to all mxArray)
		mxDestroyArray(a);
		mxDestroyArray(b);
		mxDestroyArray(y);
		mxDestroyArray(z);
	}

	// 3. Close MATLAB engine
	engClose(matlab);

#ifdef SHOW_EXTEND_INFO
	// Extend for passing in and get result for different types
	{
		// 2.2-extent: setup inputs for different types
		{
			// 2.2.0 For a double (same for a int/float/...), already shown in above

			// 2.2.1 For a string: e.g. s="../data/0003.mat"
			{
				char temp[200];
				sprintf(temp, "../data/%04d.mat", 3); // path relative to 'cd' by matlab
				mxArray *s = mxCreateString(temp);

				engPutVariable(matlab, "s", s); // put into matlab
			}

			// 2.2.2 For a matrix: e.g. m=[1 2 3 4; 5 6 7 8; 9 10 11 12] in MATLAB
			{
				mwSize dims[] = {3, 4};
				mxArray *m = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL); // 2 is the dimension of dims

				double *ptr = (double *) mxGetData(m);
				double data[] = {1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12}; // as matlab is col-major!!!
				memcpy(ptr, &data[0], 12*sizeof(double));

				engPutVariable(matlab, "m", m); // put into matlab
			}

			// 2.2.3 For a gray-scale image: e.g. img = image (cv::Mat (gray-scale))
			{
				Mat image;
				int height = image.rows; 
				int width = image.cols; 

				mwSize dims[] = {height, width};
				mxArray *img = mxCreateNumericArray(2, dims, mxUINT8_CLASS, mxREAL);
				
				UINT8 *ptr = (UINT8 *) mxGetData(img);
				transpose(image, image); // remember to tranpose first because MATLAB is col-major!!!
				memcpy(ptr, image.ptr(), height*width*sizeof(UINT8));

				engPutVariable(matlab, "img", img); // put into matlab
			}

			// 2.2.4 For a BGR image: e.g. img = image (cv::Mat (BGR))
			{
				Mat image;
				int height = image.rows; 
				int width = image.cols; 

				mwSize dims[] = {height, width, 3};
				mxArray *img = mxCreateNumericArray(3, dims, mxUINT8_CLASS, mxREAL);

				UINT8 *ptr = (UINT8 *) mxGetData(img);
				vector<Mat> channels; // B, G, R channels
				split(image, channels);
				// remember to tranpose first because MATLAB is col-major!!!
				transpose(channels[0], channels[0]);
				transpose(channels[1], channels[1]);
				transpose(channels[2], channels[2]);
				memcpy(ptr, channels[2].ptr(), height*width*sizeof(UINT8));
				memcpy(ptr+height*width, channels[1].ptr(), height*width*sizeof(UINT8));
				memcpy(ptr+2*height*width, channels[0].ptr(), height*width*sizeof(UINT8));

				engPutVariable(matlab, "img", img); // put into matlab
			}
		}

		// 2.4-extent: get results for different types
		{
			// 2.4.0 For a double (same for a int/float/...), already shown in above

			// 2.4.1 For a string: e.g. saved to str (string)
			{
				mxArray *s = engGetVariable(matlab, "s");
				char temp[200];
				mxGetString(s, &temp[0], 200);
				string str(temp);
			}

			// 2.4.2 For a matrix: e.g. m=[1 2 3 4; 5 6 7 8; 9 10 11 12] in MATLAB, saved to mat (cv::Mat)
			{
				mxArray *m = engGetVariable(matlab, "m");
				double *ptr = (double *) mxGetData(m);
				Mat mat(4, 3, CV_64F); // use a tranposed matrix to get first, CV_64F <=> double
				memcpy(mat.ptr(), ptr, 4*3*sizeof(double));
				transpose(mat, mat); // remember to tranpose back, now mat(3, 4) as expected
			}

			// 2.4.3 For a gray-scale image: e.g. to get a img(height, width) from MATLAB
			{
				// assume we know the height/width first
				int height;
				int width; 

				mxArray *img = engGetVariable(matlab, "img");
				UINT8 *ptr = (UINT8 *) mxGetData(img);
				Mat image(width, height, CV_8U); // use a tranposed matrix to get first
				memcpy(image.ptr(), ptr, width*height*sizeof(UINT8));
				transpose(image, image); // remember to tranpose back, now mat(3, 4) as expected
			}

			// 2.4.4 For a BGR image: e.g. to get a RGB-img(height, width, 3) from MATLAB to store in a BGR in VC++
			{
				// assume we know the height/width first
				int height;
				int width; 

				mxArray *img = engGetVariable(matlab, "img");
				UINT8 *ptr = (UINT8 *) mxGetData(img);
				Mat image(height, width, CV_8UC3); // use a tranposed matrix to get first
				vector<Mat> channels(3);
				for (int i=0; i<3; i++)
					channels[i] = Mat(width, height, CV_8U);
				memcpy(channels[2].ptr(), ptr, height*width*sizeof(UINT8));
				memcpy(channels[1].ptr(), ptr+height*width, height*width*sizeof(UINT8));
				memcpy(channels[0].ptr(), ptr+2*height*width, height*width*sizeof(UINT8));
				// remember to tranpose first because MATLAB is col-major!!!
				transpose(channels[0], channels[0]);
				transpose(channels[1], channels[1]);
				transpose(channels[2], channels[2]);
				merge(channels, image);
			}
		}
	}
#endif

	system("pause");
	return 0;
}