#include "pch.h"

#include "pick_peaks_api.h"

/*
typedef struct
{
	int  capacity;
	int  size;
	int* peacks;
	int* pos;
} Peaks;
*/

int init_peaks(Peaks* peacks, int capacity)
{
	peacks->capacity = capacity;
	peacks->size = 0;

	peacks->pos = new int[capacity]{ -1 };
	peacks->peak = new int[capacity]{ 0 };

	return 0;
}

int free_peaks(Peaks* peacks)
{
	delete[peacks->capacity] peacks->pos;
	delete[peacks->capacity] peacks->peak;

	peacks->capacity = 0;
	peacks->size = 0;

	return 0;
}

int get_peaks(const int* const sequence, int seq_size, Peaks* peacks)
{
	return 0;
}

