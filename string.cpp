#include "String.h"
//#include<cstring>
//#include<iostream>
//using namespace std;


namespace surya
{
	// constructors and destructors 
	STRING::STRING()  // ok 
	{
		ptr = nullptr;
	}

	STRING::STRING(const char* s) // ok
	{
		ptr = new char[strlen(s) + 1];
		strcpy(ptr , s);
	}

	STRING::STRING(STRING &t) // ok
	{
		ptr = new char[strlen(t.ptr) + 1];
		strcpy(ptr , t.ptr);
	}

	STRING STRING::operator = (STRING &t) // ok
	{
		ptr = new char[strlen(t.ptr) + 1];
		strcpy(ptr , t.ptr);
		return *this;
	}

	STRING::~STRING()  // ok
	{
		delete [] ptr;
		ptr = nullptr;
	}

	// Relational and logical operator overloading 
	STRING& STRING::operator +(STRING &t) // ok  still object + object ok    --  object + "hello" need to do it
	{
		STRING s;
		s.ptr = new char[strlen(ptr) + strlen(t.ptr) + 1];
		strcpy(s.ptr , ptr);
		strcat(s.ptr , t.ptr);
		delete [] ptr;
		ptr = new char[strlen(s.ptr) + 1];
		strcpy(ptr , s.ptr);
		return *this;
	}

	char& STRING::operator [](const int i) const  // ok
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

	bool STRING::operator >= (STRING &t) const // ok
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++) {
			//cout << (int)ptr[i] << " " << (int)t.ptr[i] << endl;
			if(ptr[i] == t.ptr[i]) continue;
			else if(ptr[i] > t.ptr[i]) return true;
			else if(ptr[i] < t.ptr[i]) return false;
		}
		if(ptr[i] > t.ptr[i]) return true;
		else if(ptr[i] < t.ptr[i]) return false;
		else if(ptr[i] == t.ptr[i]) return true;
		return true;
	}

	bool STRING::operator <= (STRING &t) const  // ok
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

	bool STRING::operator != (STRING &t) const // ok
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] != t.ptr[i]) return true;

		if(ptr[i] != t.ptr[i]) return true;

		return false;
	}

	bool STRING::operator == (STRING &t) const // ok
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] != t.ptr[i]) return false;

		if(ptr[i] != t.ptr[i]) return false; 

		return true;
	}



	// insertion and extraction operator overloading 
	istream& operator >> (istream& in , STRING &t)  // ok
	{
		if(t.ptr != nullptr)
			delete [] t.ptr;

		char s[1000];

		in.getline(s , 1000);

		t.ptr = new char[strlen(s) + 1];
		strcpy(t.ptr ,s );
		return in;
	}

	ostream& operator << (ostream& out , STRING &t)  // ok
	{
		if(t.ptr != nullptr)
			out << t.ptr;
		return out;
	}

	char& STRING::at(const int i) const  // ok
	{
		try
		{
			if(i > strlen(ptr))
				throw "terminate called after throwing an instance 'Out of range'" ;
		}
		catch(const char *s) {
			cout << s << endl;
			cout << "Aborted (core dumped)" << endl;
			exit(0);
		} 
		return ptr[i];
	}
	char& STRING::front() const // ok
	{
		return ptr[0];
	}

	char& STRING::back() const  // ok
	{
		return ptr[strlen(ptr)-1];
	}

	unsigned int STRING::length() const  // ok
	{
		unsigned int len = 0;

		while(ptr[len])
			len++;

		return len;
	}

	unsigned int STRING::size() const  // ok
	{
		unsigned int len = 0;

		while(ptr[len])
			len++;

		return len;
	}

	bool STRING::empty() const // ok
	{
		if(ptr == nullptr) return true;

		return false;
	}

	const char * STRING::c_str() const // ok
	{
		return ptr;
	}

	void STRING::clear()  // ok
	{
		if(ptr != nullptr)
			STRING::~STRING();  // explicitly calling destructor
	}

	void strcpy(STRING &s1 ,const STRING &s2)
	{
		if(s1.ptr != nullptr)
			delete [] s1.ptr;

		s1.ptr = new char[strlen(s2.ptr)+1];

		int i = 0;

		while(s2.ptr[i]) {
			s1.ptr[i] = s2.ptr[i];
			i++;
		}
		s1.ptr[i] = s2.ptr[i];
	}

	void strncpy(STRING& s1 , const STRING & s2, const int n)
	{
		if(s1.ptr != nullptr)
			delete [] s1.ptr;

		s1.ptr = new char[n + 1];

		int i = 0;

		while(i < n) {
			s1.ptr[i] = s2.ptr[i];
			i++;
		}

		s1.ptr[i] = '\0';
	}

	int strcmp(const STRING& s1 , const STRING& s2)
	{
		if(s1.ptr == nullptr)
			if(s2.ptr != nullptr) return s2.ptr[0];
			else return 0;

		if(s2.ptr == nullptr)
			if(s1.ptr != nullptr) return s1.ptr[0];
			else return 0;

		int i = 0;

		while(s1.ptr[i] && s2.ptr[i]) {
			if(s1.ptr[i] != s2.ptr[i]) return (int)(s1.ptr[i] - s2.ptr[i]); 
			i++;
		}
		if(s1.ptr[i] == s2.ptr[i]) return 0;

		return (int)(s1.ptr[i] - s2.ptr[i]);
	}

	int strncmp(const STRING& s1 ,const STRING& s2 , const int n)
	{
		if(s1.ptr == nullptr)
			if(s2.ptr != nullptr) return s2.ptr[0];
			else return 0;

		if(s2.ptr == nullptr)
			if(s1.ptr != nullptr) return s1.ptr[0];
			else return 0;

		int i = 0;

		while(i < n && s1.ptr[i] && s2.ptr[i]) {
			if(s1.ptr[i] != s2.ptr[i]) return (int)(s1.ptr[i] - s2.ptr[i]);

			i++;
		}
		if(i == n) return 0;

		if(!s1.ptr[i] || !s2.ptr[i])
			return (int)(s1.ptr[i] - s2.ptr[i]);

		return 0;
	}

	void strcat(STRING &s1 , const STRING &s2)
	{
		if(s2.ptr == nullptr) return;

		int len1 = 0;

		while(s1.ptr[len1])
			len1++;

		int len2 = 0;

		while(s2.ptr[len2])
			len2++;

		char *s = new char[len1 + len2 +1];

		int i = 0;

		if(s1.ptr)
			while(s1.ptr[i]) {
				s[i] = s1.ptr[i];
				i++;
			}

		int j = 0;

		while(s2.ptr[j])
			s[i++] = s2.ptr[j++];

		s[i] = s2.ptr[j];

		if(s1.ptr) delete [] s1.ptr;

		s1.ptr = new char[i+1];

		i = 0;

		while(s[i])
		{
			s1.ptr[i] = s[i];
			i++;
		}

		s1.ptr[i] = s[i];

		delete [] s;
	}

	void strncat(STRING &s1 , const STRING & s2,const int n)
	{
		if(s2.ptr == nullptr) return;

		int len1 = 0;
		while(s1.ptr[len1++]);

		int len2 = 0;
		while(s2.ptr[len2++]);

		char s[len1+len2+1];

		int i = 0;

		if(s1.ptr)
			while(s1.ptr[i])
			{
				s[i] = s1.ptr[i];
				i++;
			}

		int j = 0;

		while(j < n && s2.ptr[j]) 
			s[i++] = s2.ptr[j++];

		s[i] = 0;

		if(s1.ptr != nullptr) delete [] s1.ptr;

		s1.ptr = new char[i+1];

		i = 0;
		while(s[i])
		{
			s1.ptr[i] = s[i];
			i++;
		}
		s1.ptr[i] = s[i];
	}

	void strrev(STRING &s)
	{
		if(!s.ptr) return;

		int len = 0;

		while(s.ptr[len++]);

		for(int i = 0, j = len - 1 ; i < j ; i++, j--) {
			int t = s.ptr[i];
			s.ptr[i] = s.ptr[j];
			s.ptr[j] = t;
		}
	}

	void strupper(STRING &s)
	{
		if(!s.ptr) return;

		for(int i = 0 ; s.ptr[i] ; i++)
			if(s.ptr[i] >= 'a' && s.ptr[i] <= 'z') s.ptr[i] -= 32;

	}


	void strlower(STRING &s)
	{
		if(!s.ptr) return;

		for(int i = 0 ; s.ptr[i] ; i++)
			if(s.ptr[i] >= 'A' && s.ptr[i] <= 'Z') s.ptr[i] += 32;

	}

	char * strchr(const STRING& s, const char ch)
	{
		if(!s.ptr) return 0;

		for(int i = 0 ; s.ptr[i] ; i++)
			if(s.ptr[i] == ch) return &s.ptr[i];

		return 0;
	}

	char * strrchr(const STRING& s, const char ch)
	{
		if(!s.ptr) return 0;

		int len = 0;

		while(s.ptr[len++]);

		for(int i = len - 1 ; i >= 0 ; i--)
			if(s.ptr[i] == ch) return s.ptr + i;

		return 0;
	}

	char * strstr(const STRING& s, const char *p)
	{
		if(!s.ptr) return 0;

		for(int i = 0 ; s.ptr[i] ; i++) {
			int j = 0;
			for(int k = i ; s.ptr[k] && p[j] ; k++,j++)
				if(s.ptr[k] != p[j]) break;

			if(p[j] == 0) return s.ptr + i;
		}

		return 0;
	}

	unsigned int strlen(const STRING& s)
	{
		if(!s.ptr) return 0;

		unsigned int len = 0;

		while(s.ptr[len++]);

		return len;

	}

}
