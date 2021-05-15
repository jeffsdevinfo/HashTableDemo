#pragma once
#include <string>
class PracticeClass
{
public:
	PracticeClass() { m_ptr = nullptr; };
	PracticeClass(std::string name, int val) : m_name(name), m_ptr(new int(val)) {}
	PracticeClass(const PracticeClass& other) { m_name = other.m_name; m_ptr = new int(*other.m_ptr); }

	PracticeClass& operator=(const PracticeClass& other)
	{
		if (this != &other)
		{
			m_name = other.m_name; m_ptr = new int(*other.m_ptr);
		}
		return *this;
	}
	~PracticeClass()
	{
		delete m_ptr;
		m_ptr = 0;
	}

	std::string m_name;
	int* m_ptr;
};