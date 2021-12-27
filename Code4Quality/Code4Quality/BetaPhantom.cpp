#include "pch.h"
#include <vector>
#include <numeric>

using namespace std;

namespace BetaPhantom
{
#ifdef _BETA
	static bool LogToTempFile(const std::string& text)
	{
		std::string fname("c:\\temp\\log.txt");
		FILE* pStream = nullptr;
		if (fopen_s(&pStream, fname.c_str(), "w+") == 0)
		{
			// log into file stream here
			_fprintf_p(pStream, "log: %s", text.c_str());

			fclose(pStream);
		}
		return true;
	}
#endif

	static void Process()
	{
#ifdef _BETA
		// log into for Beta build
		LogToTempFile("BetaPhantom");
#endif
	}
}



TEST(BetaPhantom, BetaPhantom) {
  EXPECT_NO_FATAL_FAILURE(BetaPhantom::Process());
}