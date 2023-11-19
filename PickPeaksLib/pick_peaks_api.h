#pragma once

// https://www.codewars.com/kata/5279f6fe5ab7f447890006a7/train/cpp

#ifdef PICKPEAKSLIB_EXPORTS
#define PICKPEAKSLIB_API __declspec(dllexport)
#else
#define PICKPEAKSLIB_API __declspec(dllimport)
#endif

#define MIN_SEQ_SIZE 3

typedef struct
{
	int  capacity;
	int  size;
	int* peak;
	int* pos;
} Peaks;

int PICKPEAKSLIB_API init_peaks(Peaks* peaks, int capacity);

int PICKPEAKSLIB_API free_peaks(Peaks* peaks);

int PICKPEAKSLIB_API get_peaks(const int* const sequence, int seq_size, Peaks* peaks);

