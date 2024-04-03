#pragma once

#ifdef ATHLASSOCSTATLIB_EXPORTS
#define ATHLASSOCSTATLIB_API __declspec(dllexport)
#else
#define ATHLASSOCSTATLIB_API  __declspec(dllimport)
#endif

