#pragma once

#if defined Q_OS_WIN
  #ifdef NULL_LOG_LIBRARY_BUILD
    #define NULL_LOG_UTIL __declspec(dllexport)
  #else
    #define NULL_LOG_UTIL __declspec(dllimport)
  #endif

#else
  #ifdef NULL_LOG_LIBRARY_BUILD
    #define NULL_LOG_UTIL __attribute__ ((visibility ("default")))
  #else
    #define NULL_LOG_UTIL
  #endif
#endif