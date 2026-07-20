#include "String.h"

namespace surya
{
	// constructors and destructors 
	STRING::STRING() 
	{
		ptr = nullptr;
	}

	STRING::STRING(const char* s)
	{
		ptr = new char[strlen(s) + 1];
		strcpy(ptr , s);
	}

	STRING::STRING(STRING &t)
	{
		ptr = new char[strlen(t.ptr) + 1];
		strcpy(ptr , t.ptr);
	}

	STRING STRING::operator = (STRING &t)
	{
		ptr = new char[strlen(t.ptr) + 1];
		strcpy(ptr , t.ptr);
		return *this;
	}

	STRING::~STRING()
	{
		delete [] ptr;
	}

	// Relational and logical operator overloading 
	STRING STRING::operator +(STRING &t)
	{
		STRING s;
		s.ptr = new char[strlen(ptr) + strlen(t.ptr) + 1];
		strcpy(s.ptr , ptr);
		strcat(s.ptr , t.ptr);
		// delete [] ptr;
		return s;
	}

	char& STRING::operator [](const int i) const
	{
		return ptr[i];
	}

	/*bool STRING::operator > (STRING &t) const
	  {
	  return strcmp(*this , t);
	  }

	  bool STRING::operator < (STRING &t) const
	  {
	  return strcmp(t , *this);
	  }*/

	bool STRING::operator >= (STRING &t) const
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] == t.ptr[i]) continue;
			else if(ptr[i] > t.ptr[i]) return true;
			else if(ptr[i] < t.ptr[i]) return false;

		if(ptr[i] > t.ptr[i]) return true;
		else if(ptr[i] < t.ptr[i]) return false;
		else if(ptr[i] == t.ptr[i]) return true;
		return true;
	}

	bool STRING::operator <= (STRING &t) const
	{
		int i;
		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] == t.ptr[i]) continue;
			else if(ptr[i] > t.ptr[i]) return false;
			else if(ptr[i] < t.ptr[i]) return true;

		if(ptr[i] > t.ptr[i]) return false;
		else if(ptr[i] < t.ptr[i]) return true;
		else if(ptr[i] == t.ptr[i]) return true;
		return true;
	}

	bool STRING::operator != (STRING &t) const
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] != t.ptr[i]) return true;

		if(ptr[i] != t.ptr[i]) return true;

		return false;
	}

	bool STRING::operator == (STRING &t) const
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] != t.ptr[i]) return false;

		if(ptr[i] != t.ptr[i]) return false; 

		return true;
	}



	// insertion and extraction operator overloading 
	istream& operator >> (istream& in , STRING &t)
	{
		if(t.ptr != 0)
			delete [] t.ptr;

		char s[1000000];

in.getline(s , 1000000);

		t.ptr = new char[strlen(s) + 1];
		strcpy(t.ptr ,s );
		return in;
	}

	ostream& operator << (ostream& out , STRING &t)
	{
		out << t.ptr;
		return out;
	}

}

