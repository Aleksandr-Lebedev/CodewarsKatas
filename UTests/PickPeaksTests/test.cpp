#include "pch.h"
#include "pick_peaks_api.h"

class CodewarsCasesTest : public testing::Test {

protected:
	void perform_test(const std::vector<int>& sequence,
					  const std::vector<int>& expected_peaks,
					  const std::vector<int>& expected_pos)
	{
		const auto ret_code = get_peaks(sequence.data(),
			static_cast<int>(sequence.size()), &peaks);
		EXPECT_TRUE(ret_code == 0);

		EXPECT_EQ(peaks.size, expected_peaks.size());
		EXPECT_EQ(peaks.size, expected_pos.size());
		for (int i = 0; i < peaks.size; ++i)
		{
			EXPECT_EQ(peaks.pos[i], expected_pos[i]);
			EXPECT_EQ(peaks.peak[i], expected_peaks[i]);
		}
	}

	void SetUp() override
	{
		init_peaks(&peaks, peaks_capacity);
	}

	void TearDown() override
	{
		free_peaks(&peaks);
	}

	static constexpr int peaks_capacity = 10;
	Peaks peaks;
};

TEST_F(CodewarsCasesTest, Test_1) {
	perform_test({ 3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3 }, { 6, 3 }, { 3, 7 });
}

TEST_F(CodewarsCasesTest, Test_2) {
	perform_test({ 1, 2, 2, 2, 1 }, { 2 }, { 1 });
}

