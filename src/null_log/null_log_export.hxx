#pragma once

#if defined(NULL_LOG_LIBRARY_BUILD)
#  define NULL_LOG_UTIL __declspec(dllexport)
#else
#  define NULL_LOG_UTIL __declspec(dllimport)
#endif
