#include "pch.h"

class CareAboutMemberPointer {
public:
	CareAboutMemberPointer(const char* name)
		: m_Name(_strdup(name))	{}
	~CareAboutMemberPointer() { delete m_Name; }

	CareAboutMemberPointer(const CareAboutMemberPointer& rOther)
	{
		if (this == &rOther)
			return;

		m_Name = _strdup(rOther.m_Name);
	}

	CareAboutMemberPointer& operator=(const CareAboutMemberPointer& rOther)
	{
		if (this != &rOther)
			m_Name = _strdup(rOther.m_Name);

		return *this;
	}

	const char* getName() { return m_Name; }

private:
	char* m_Name = nullptr;
};

void Process()
{
	CareAboutMemberPointer a("Foo");
	CareAboutMemberPointer b("Bar");

	CareAboutMemberPointer tmp(nullptr);
	tmp = a;
	a = b;
	b = tmp;
}

TEST(CareAboutMemberPointer, CareAboutMemberPointer) {
  EXPECT_NO_FATAL_FAILURE(Process());
}