// wcerr -- initialize standard wide error stream
// This wcerr is unsigned short version of wcerr

#ifdef _NATIVE_WCHAR_T_DEFINED
#include <fstream>

#ifndef wistream
#define wistream    ushistream
#define wostream    ushostream
#define wfilebuf    ushfilebuf
#define _Init_wcerr _Init_ushcerr
#define _Init_wcout _Init_ushcout
#define _Init_wclog _Init_ushclog
#define _Init_wcin  _Init_ushcin
#define init_wcerr  init_ushcerr
#define init_wcout  init_ushcout
#define init_wclog  init_ushclog
#define init_wcin   init_ushcin
#define _Winit      _UShinit
#endif

#include <iostream>
#include "wcerr.cpp"
#endif

/*
 * Copyright (c) 1992-2005 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V4.05:0009 */
