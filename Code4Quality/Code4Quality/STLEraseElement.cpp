#include "pch.h"
#include <vector>
#include <numeric>

using namespace std;

static void Process()
{
	vector<int> integers(10); // vector of 10 integers
	iota(integers.begin(), integers.end(), 0);  // Populate the vector with values 0-9.

	// remove any odd integers
	if (true)
	{
		integers.erase(std::remove_if(integers.begin(), integers.end(), [](int value) {return value % 2; }), integers.end());
	}
	else
	{
		// This will crash
		for (vector<int>::iterator iter = integers.begin(); iter != integers.end(); ++iter) {
			if ((*iter) % 2)
				integers.erase(iter);
		}
	}
}

TEST(STLEraseElement, STLEraseElement) {
  EXPECT_NO_FATAL_FAILURE(Process());
}