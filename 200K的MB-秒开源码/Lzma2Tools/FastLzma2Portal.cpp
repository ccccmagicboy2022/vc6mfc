#include <stdio.h>
#include "../fast-lzma2/include/fast-lzma2.h"
#include "FastLzma2Portal.h"
#pragma comment(lib ,"../fast-lzma2/fast-lzma2.lib")

unsigned char in_buffer[4 * 1024];
unsigned char out_buffer[8 * 4 * 1024];
void DecompressFile(const char* inFileName, const char* outFileName) {
	auto fin = fopen(inFileName, "rb");
	auto fout = fopen(outFileName, "w+b");
	auto fds = FL2_createDStreamMt(2);

    FL2_inBuffer in_buf = { in_buffer, sizeof(in_buffer), sizeof(in_buffer) };
    FL2_outBuffer out_buf = { out_buffer, sizeof(out_buffer), 0 };
    size_t res= FL2_initDStream(fds);
    size_t in_size = 0;
    size_t out_size = 0;
    do {
        if (in_buf.pos == in_buf.size) {
            in_buf.size = fread(in_buffer, 1, sizeof(in_buffer), fin);
            in_size += in_buf.size;
            in_buf.pos = 0;
        }
        res = FL2_decompressStream(fds, &out_buf, &in_buf);
        fwrite(out_buf.dst, 1, out_buf.pos, fout);
        /* Discard the output. XXhash will verify the integrity. */
        out_size += out_buf.pos;
        out_buf.pos = 0;
    } while (res && in_buf.size);

cleanup:
    fclose(fout);
    fclose(fin);
    FL2_freeDStream(fds);
}
void CompressFile(const char* inFileName, const char* outFileName)
{
    auto fin = fopen(inFileName, "rb");
    auto fout = fopen(outFileName, "w+b");
    FL2_CStream* fcs = FL2_createCStreamMt(2, 0);

    unsigned char in_buffer[8 * 1024];
    unsigned char out_buffer[4 * 1024];
    FL2_inBuffer in_buf = { in_buffer, sizeof(in_buffer), sizeof(in_buffer) };
    FL2_outBuffer out_buf = { out_buffer, sizeof(out_buffer), 0 };
    size_t res = FL2_initCStream(fcs, 6);;
    size_t in_size = 0;
    size_t out_size = 0;
    do {
        if (in_buf.pos == in_buf.size) {
            in_buf.size = fread(in_buffer, 1, sizeof(in_buffer), fin);
            in_size += in_buf.size;
            in_buf.pos = 0;
        }
        res = FL2_compressStream(fcs, &out_buf, &in_buf);
        if (FL2_isError(res))
            goto error_out;

        fwrite(out_buf.dst, 1, out_buf.pos, fout);
        out_size += out_buf.pos;
        out_buf.pos = 0;

    } while (in_buf.size == sizeof(in_buffer));
    do {
        res = FL2_endStream(fcs, &out_buf);
        if (FL2_isError(res))
            goto error_out;

        fwrite(out_buf.dst, 1, out_buf.pos, fout);
        out_size += out_buf.pos;
        out_buf.pos = 0;
    } while (res);
    fprintf(stdout, "\t%ld -> %ld\n", in_size, out_size);

    return;

error_out:
    fprintf(stderr, "Error: %s\n", FL2_getErrorName(res));
cleanup:
    fclose(fout);
    fclose(fin);
    FL2_freeCStream(fcs);
}