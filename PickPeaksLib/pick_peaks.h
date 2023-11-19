#pragma once
#include <vector>

namespace CodewarsKatas
{
struct PeakData
{
	std::vector<int> pos, peaks;
};

namespace PickPeaksLib
{
	PeakData pick_peaks(const std::vector<int>& v);
}
}

