#include "StringClass.h"
// #include <iostream>

// using namespace std;

	int myStr::length() const
	{
		// Does not include the null terminator
		return strLen;
	}
	
	int myStr::strCmp(const myStr& compareMe) const
	{
		return strCmp(compareMe.data);
	}
	
	int myStr::strCmp(const char* compareMe) const
	{
		// Finding the length of the parameter
		int compareMeLen = 0;
		
		for (int i = 0; compareMe[i] != 0; i++)
			compareMeLen++;
		
		// Comparing strs that are of different lengths but are otherwise same
		// If the first str is less than the second str
		if (strLen < compareMeLen)
		{
			for (int j = 0; j < strLen; j++){
			
			// If a character in the first str is ahead of the corresponding
			// character in the second str		
			if (data[j] < compareMe[j])
				return 1;
			
			// If a character in the first str is behind the corresponding
			// character in the second str
			else if (data[j] > compareMe[j])
				return -1;
			}
			
			return 1;
		}

		// Comparing strs that are of different lengths but are otherwise same	
		// If the first str is greater than the first str
		if (strLen > compareMeLen)
		{
			for (int j = 0; j < compareMeLen; j++){
			
			// If a character in the first str is ahead of the corresponding
			// character in the second str		
			if (data[j] < compareMe[j])
				return 1;
			
			// If a character in the first str is behind the corresponding
			// character in the second str
			else if (data[j] > compareMe[j])
				return -1;
			}
			
			return -1;
		}
		
		// If both strs have the same length
		for (int j = 0; j < compareMeLen; j++){
			
			// If a character in the first str is ahead of the corresponding
			// character in the second str		
			if (data[j] < compareMe[j])
				return 1;
			
			// If a character in the first str is behind the corresponding
			// character in the second str
			else if (data[j] > compareMe[j])
				return -1;
		}
		
		// If both strs are exactly equal
		return 0;
	}
	
	bool myStr::strCpy(const myStr& copyMe)
	{
		if (strCpy(copyMe.data))
			return true;
		return false;
	}
	
	bool myStr::strCpy(const char* copyMe)
	{		
		int length = 0;
		while (copyMe[length] != 0)
		{
			length++;
		}
		// Including the length of the null pointer
		strLen = length;
		dataLen = strLen + 1;
		
		data = new char[dataLen];
		// delete(data);
		
		int i = 0;
		while (copyMe[i] != 0)
		{
			data[i] = copyMe[i];
			i++;
		}
		data[i] = 0;
		
		return true;		
	}
	
	int myStr::subStr(const char* findMe) const
	{
		return subStr(findMe, 0);
	}
	
	int myStr::subStr(const myStr& findMe) const
	{
		return subStr(findMe.data);
	}
	
	int myStr::subStr(const char* findMe, int startingAt) const
	{		
		// cout << "starting at: " << startingAt << endl;
		int i = startingAt;
		int occurrences = 0;
		while(data[i] != 0)
		{
			int j = 0;
			int m = 1;
			
			while ((findMe[j]!= 0) && (m == 1))
			{
				if (data[i+j] != findMe[j])
				{
					m = 0;
				}
				j++;
			}
			if (m == 1)
			{
				// cout << "i: " << i << endl;
				return i;
			}
			++i;
		}
		
		return -1;
	}
	
	int myStr::subStr(const myStr& findMe, int startingAt) const
	{
		return subStr(findMe.data, startingAt);
	}
	
	char myStr::at(const unsigned int index) const
	{
		if (index >= 0 && (index < strLen))
			return data[index];
		// Accessing past the length of data (including the null terminator)
		return 0;
	}
	
	myStr::myStr()
	{
		strLen = 0;
		dataLen = 1;
		data = new char[dataLen];
		data[0] = 0;
		//myStr(0);
	}
	
	myStr::myStr(const myStr& copyMe)
	{
		myStr(copyMe.data);
	}
	
	myStr::myStr(const char* copyMe)
	{
		int length = 0;
		while (copyMe[length] != 0)
		{
			length++;
		}
		// Including the length of the null pointer
		strLen = length;
		dataLen = strLen + 1;
		
		// delete(data);
		data = new char[dataLen];
		
		length = 0;
		while (copyMe[length] != 0)
		{
			data[length] = copyMe[length];
			length++;
		}
		data[length] = 0;
		
		/*
		for (length = 0; length < dataLen; length++)
			data[length] = copyMe[length];
		data[length] = 0; */
		
	}
	
	myStr::~myStr()
	{
		strLen = -1;
		dataLen = -1;
		// delete(data);
		data = new char[1];
		data[0] = 0;
	}