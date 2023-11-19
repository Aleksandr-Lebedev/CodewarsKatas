#pragma once

#ifdef PICKPEAKSLIB_EXPORTS
#define PICKPEAKSLIB_API __declspec(dllexport)
#else
#define PICKPEAKSLIB_API __declspec(dllimport)
#endif

typedef struct
{
	int  capacity;
	int  size;
	int* peak;
	int* pos;
} Peaks;

int PICKPEAKSLIB_API init_peaks(Peaks* peacks, int capacity);

int PICKPEAKSLIB_API free_peaks(Peaks* peacks);

int PICKPEAKSLIB_API get_peaks(const int* const sequence, int seq_size, Peaks* peacks);

