#include "pch.h"

#include "pick_peaks.h"

namespace CodewarsKatas::PickPeaksLib
{
	PeakData pick_peaks(const std::vector<int>& v)
	{
		PeakData result;
		for (auto i = 1; i < v.size() - 1; ++i)
		{
			const auto prev = v[i - 1];
			const auto next = v[i + 1];
			if (v[i] > prev and v[i] > next)
			{
				result.peaks.push_back(v[i]);
				result.pos.push_back(i);
			}
		}

		return result;
	}
}

