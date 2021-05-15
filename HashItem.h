#pragma once
template <typename T>
class HashItem
{
public:
	HashItem() { m_Key = -1; };
	void SetKey(int key) { m_Key = key; }
	int GetKey() { return m_Key; }
	void SetObj(T Obj) { m_Obj = Obj; }
	T& GetObj() { return m_Obj; }

	bool operator==(T& Obj)
	{
		if (m_Obj == Obj)
			return true;
		return false;
	}

	HashItem& operator=(const HashItem& other)
	{
		if (this != &other)
		{
			m_Key = other.m_Key;
			m_Obj = other.m_Obj;
		}
		return *this;
	}

private:
	int m_Key;
	T m_Obj;
};