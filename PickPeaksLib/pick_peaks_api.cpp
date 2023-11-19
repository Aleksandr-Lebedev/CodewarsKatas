#include "pch.h"

#include "pick_peaks_api.h"
#include "pick_peaks.h"

int init_peaks(Peaks* peaks, int capacity)
{
	peaks->capacity = capacity;
	peaks->size = 0;

	peaks->pos = new int[capacity]{ -1 };
	peaks->peak = new int[capacity]{ 0 };

	return 0;
}

int free_peaks(Peaks* peaks)
{
	delete[peaks->capacity] peaks->pos;
	delete[peaks->capacity] peaks->peak;

	peaks->capacity = 0;
	peaks->size = 0;

	return 0;
}

static int copy_peaks(const CodewarsKatas::PeakData& from, Peaks& to)
{
	if (to.capacity < from.peaks.size())
		return 1;

	std::copy(from.peaks.cbegin(), from.peaks.cend(), to.peak);
	std::copy(from.pos.cbegin(), from.pos.cend(), to.pos);
	to.size = static_cast<decltype(to.size)>(from.peaks.size());

	return 0;
}

int get_peaks(const int* const sequence, int seq_size, Peaks* peaks)
{
	using CodewarsKatas::PeakData;
	using CodewarsKatas::PickPeaksLib::pick_peaks;

	std::vector<int> v_sequence;
	std::copy_n(sequence, seq_size, std::back_inserter(v_sequence));

	auto peak_data = pick_peaks(v_sequence);

	return copy_peaks(peak_data, *peaks);
}

