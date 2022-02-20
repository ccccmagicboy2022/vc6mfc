-----------------------------------------------------------------------
                SourceStyler Release Notes

Copyright (c) 2003, Ochre Software Pty. Ltd. All Rights Reserved

-----------------------------------------------------------------------

This file contains important information about this release of SourceStyler C++.

Release Name:   1.4.4
Release Date:   19 December 2005

--------
Contents
--------
I.      What is SourceStyler C++
II.     What's new in this release
III.    What's fixed in this release   
IV.     List of artifacts contained in this release
V.      Usage notes for this release
VI.     Platforms supported in this release
VII.    Contacting Ochre Software


---------------------------
I. What is SourceStyler C++
---------------------------
SourceStyler C++ is a sophisticated source code beautifier that
will give your C/C++ code a polished and professional look in seconds.

SourceStyler C++ offers three different interfaces for use:

1. A standalone Win32 GUI application: SourceStyler.exe.
2. A Microsoft Visual Studio Add-In: SourceStylerAddIn.dll, SourceStylerDotNetAddIn.dll.
3. A Win32 command line application: SourceStylerCmd.exe.

------------------------------
II. What's new in this release
------------------------------
1. Visual Studio .NET Add-in. SourceStyler C++ is now available to users of both
   Visual Studio 6.0 and Visual Studio .NET as an add-in.
2. A completely new line wrapping algorithm. This new line wrapping implementation
   offers much better results when wrapping expressions, better wrapping of method calls,
   and is stricter about wrapping within the right margin.
3. More line wrapping options. You can now enjoy finer control over line wrapping behaviour
   for individual syntax elements.

---------------------------------
III. What's fixed in this release
---------------------------------
1. CR/LF sequences incorrectly converted to LF.
2. Parser crashes on legal code sequences.
3. Parser crash on hexadecimal constants.
4. Comparison statements of form "(a < b && c > d)" cause d to be removed.
5. Unwanted extra space inserted in statements of form "a[0].something = anything;".
6. CR/LF sequences incorrectly converted to CR/CR/LF by command line client.
7. Unwanted whitespace inserted after '*' in expressions like "vector<foo*>".
8. Switch case statements not formatted.
9. Some control statement bodies (e.g. in "if" statements) not formatted.
10. Interface declarations (Microsoft syntax extension) not parsed correctly.

-------------------------------
IV. Usage notes for this release
-------------------------------
Please see the online help for information describing how
to use the different user interfaces to SourceStyler C++.

---------------------------------------
V. Platforms supported in this release
---------------------------------------
Microsoft Windows 98
Microsoft Windows ME
Microsoft Windows NT 4.0 with Service Pack 6 or greater        
Microsoft Windows 2000
Microsoft Windows XP

For the SourceStyler C++ Visual Studio Add-In:
Microsoft Visual Studio 6 with Service Pack 3 or greater.
or
Microsoft Visual Studio .NET 2003

------------------------------
VII. Contacting Ochre Software
------------------------------
Ochre Software's website is located at http://www.ochre.com/
Support e-mail should be directed to support@ochre.com
Sales or information enquiries should be directed to sales@ochre.com
