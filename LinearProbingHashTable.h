#pragma once
#include "HashItem.h"
#include "Base.h"
#include "PracticeClass.h"
#include <iostream>

template <typename T>
class LinearProbingHashTable
{
public:
	LinearProbingHashTable() {}
	LinearProbingHashTable(int size)
	{
		// size table
		m_size = GetPrime(size);
		m_table = new HashItem<T>[m_size] {};
		m_totalItems = 0;

	}

	int GetPrime(int val)
	{
		while (!isPrime(val))
		{
			val++;
		}
		return val;
	}

	bool isPrime(int val)
	{
		if (val == 0 || val == 1)
			return false;
		for (int i = 2; i <= val / 2; i++)
		{
			if (val % i == 0)
			{
				return false;
			}
		}
		return true;
	}

	bool insert(int key, const T& object)
	{
		if (m_size == m_totalItems)
			return false;

		int hashedIndex = findEmpty(key);
		if (hashedIndex == -1)
		{
			return false;
		}
		m_table[hashedIndex].SetKey(key);
		m_table[hashedIndex].SetObj(object);
		m_totalItems++;
		return true;
	}

	bool find(int key, T* obj)
	{
		int hashIndex = findKey(key);
		if (hashIndex == -1)
			return false;

		*obj = m_table[hashIndex].GetObj();
		return true;
	}

	int findEmpty(int keyToHash)
	{
		int hashIndex = keyToHash % m_size;
		int originalIndex = hashIndex;
		while (m_table[hashIndex].GetKey() != -1)
		{
			hashIndex++;
			hashIndex = HashFunction(hashIndex);
			if (hashIndex == originalIndex)
				return -1;
		}
		return hashIndex;
	}

	int findKey(int keyToFind)
	{
		int hashIndex = keyToFind % m_size;
		int originalValue = hashIndex;
		while (m_table[hashIndex].GetKey() != keyToFind)
		{
			if (m_table[hashIndex].GetKey() == -1)
			{
				return -1;
			}			
			hashIndex++;
			hashIndex = HashFunction(hashIndex);
			if (hashIndex == originalValue)
				return -1;
		}
		return hashIndex;
	}

	int HashFunction(int keyToHash)
	{
		return keyToHash % m_size;
	}

private:
	int m_size{};
	int m_totalItems{};
	HashItem<T>* m_table{};
};


class LinearProbingHashTableExecutor :public Base
{
public:
	void Run()
	{
		PracticeClass temp1("Alpha", 15);
		PracticeClass temp2("Beta", 30);

		LinearProbingHashTable<PracticeClass> hT(15);
		hT.insert(10, temp1);
		hT.insert(18, temp2);

		PracticeClass temp3;
		hT.find(18, &temp3);
		if (temp3.m_ptr != nullptr)
			std::cout << temp3.m_name << " " << *temp3.m_ptr;
	}
};