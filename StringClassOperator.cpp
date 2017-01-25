#include <iostream>
#include "StringClass.h"

std::ostream& operator<<(std::ostream& os, const myStr& s)
{
    if (s.strLen == 0)
      return os;
    if (s.dataLen > s.strLen && s.data != 0 && s.data[s.strLen] == 0)
	{
      os << s.data;
      return os;
    }
    else if (s.data != 0)
	{
      for (int i = 0; i < s.strLen; ++i)
	  {
        os << s.data[i];
      }
      return os;
    }
    else
	{
      std::cerr << "Error: Attempted to output string when _data is NULL";
      return os;
    }
}
