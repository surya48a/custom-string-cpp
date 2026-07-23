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

	STRING STRING::operator = (const STRING &t)
	{
		if(ptr != nullptr) {
			delete [] ptr;
			ptr = nullptr;
		}

		ptr = new char[strlen(t.ptr) + 1];
		strcpy(ptr , t.ptr);
		return *this;
	}

	STRING::~STRING()  
	{
		delete [] ptr;
		ptr = nullptr;
	}

	// Relational and logical operator overloading 
	STRING& STRING::operator +=(const STRING &t)  
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

	STRING STRING::operator +(const STRING& t) const  
	{
		STRING s;

		s.ptr = new char[strlen(t.ptr) + strlen(ptr) + 1];

		strcpy(s.ptr , ptr);
		strcat(s.ptr , t.ptr);

		return s;
	}

	STRING STRING::operator +(const char *s) const  
	{
		STRING t;

		t.ptr = new char[strlen(s) + strlen(ptr) + 1];
		strcpy(t.ptr , ptr);
		strcat(t.ptr , s);

		return t;
	}

	STRING operator +(const char *s , const STRING& t)  
	{
		STRING s1;

		s1.ptr = new char[strlen(t.ptr) + strlen(s) + 1];
		strcpy(s1.ptr , s);
		strcat(s1.ptr , t.ptr);

		return s1;
	}

	char& STRING::operator [](const int i) const  
	{
		return ptr[i];
	}

	bool STRING::operator > (const STRING &t) const  
	{
		return strcmp(*this , t) > 0 ? true : false;
	}

	bool STRING::operator < (const STRING &t) const  
	{
		return strcmp(t , *this) > 0 ? true : false;
	}

	bool STRING::operator >= (const STRING &t) const 
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++) {
			if(ptr[i] == t.ptr[i]) continue;
			else if(ptr[i] > t.ptr[i]) return true;
			else if(ptr[i] < t.ptr[i]) return false;
		}
		if(ptr[i] > t.ptr[i]) return true;
		else if(ptr[i] < t.ptr[i]) return false;
		else if(ptr[i] == t.ptr[i]) return true;
		return true;
	}

	bool STRING::operator <= (const STRING &t) const  
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

	bool STRING::operator != (const STRING &t) const 
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] != t.ptr[i]) return true;

		if(ptr[i] != t.ptr[i]) return true;

		return false;
	}

	bool STRING::operator == (const STRING &t) const
	{
		int i;

		for(i = 0 ; ptr[i] && t.ptr[i] ; i++)
			if(ptr[i] != t.ptr[i]) return false;

		if(ptr[i] != t.ptr[i]) return false; 

		return true;
	}





	// insertion and extraction operator overloading 
	std::istream& operator >> (std::istream& in , STRING &t)  
	{
		if(t.ptr != nullptr)
			delete [] t.ptr;

		char s[1000];

		in.getline(s , 1000);

		t.ptr = new char[strlen(s) + 1];
		strcpy(t.ptr ,s );
		return in;
	}

	std::ostream& operator << (std::ostream& out , STRING &t) 
	{
		if(t.ptr != nullptr)
			out << t.ptr;
		return out;
	}



	// Basic functions of c++ class 
	char& STRING::at(const int i) const  
	{
		try
		{
			if(i > strlen(ptr))
				throw "terminate called after throwing an instance 'Out of range'" ;
		}
		catch(const char *s) {
			std::cout << s << std::endl;
			std::cout << "Aborted (core dumped)" << std::endl;
			exit(0);
		} 
		return ptr[i];
	}

	char& STRING::front() const 
	{
		return ptr[0];
	}

	char& STRING::back() const 
	{
		return ptr[strlen(ptr)-1];
	}

	unsigned int STRING::length() const 
	{
		unsigned int len = 0;

		while(ptr[len])
			len++;

		return len;
	}

	unsigned int STRING::size() const  
	{
		unsigned int len = 0;

		while(ptr[len])
			len++;

		return len;
	}

	bool STRING::empty() const 
	{
		if(ptr == nullptr) return true;

		return false;
	}

	const char * STRING::c_str() const 
	{
		return ptr;
	}

	void STRING::clear()  
	{
		if(ptr != nullptr)
			STRING::~STRING();  // explicitly calling destructor
	}


	void STRING::push_back(const char ch)
	{
		if(!ptr) {
			ptr = new char[2];
			ptr[0] = ch;
			return;
		}

		int len = 0;

		while(ptr[len]) len++;

		char *p = new char[len+2];

		strcpy(p , ptr);

		p[len] = ch;
		p[len + 1] = '\0';

		delete [] ptr;

		ptr = new char[len+2];

		strcpy(ptr , p);

		delete [] p;
	}

	void STRING::pop_back() 
	{
		if(!ptr) return;

		int len = 0;

		while(ptr[len]) len++;

		char *p = new char[len];

		strncpy(p , ptr , len - 1);

		p[len] = '\0';

		delete [] ptr;

		ptr = new char[len];

		strcpy(ptr , p);

		delete [] p;

	}

	int STRING::find(const char *s) const
	{
		if(!ptr) return -1;

		for(int i = 0 ; ptr[i] ; i++) {
			int j = 0;
			for(int k = i ; s[j] && ptr[k] ; k++,j++)
				if(s[j] != ptr[k]) break;

			if(s[j] == '\0') return i;
		}

		return -1;
	}

	void STRING::swap(STRING &s)
	{
		STRING t = *this;
		*this = s;
		s = t;
	}

	int STRING::compare(const STRING &s) const
	{
		if(!ptr || !s.ptr) return -1;

		int i;
		for(i = 0 ; ptr[i] && s.ptr[i] ; i++)
			if(ptr[i] != s.ptr[i]) return ptr[i] - s.ptr[i];

		if(ptr[i] == s.ptr[i]) return 0;

		return ptr[i] - s.ptr[i];
	}

	void STRING::append(const STRING &s1)
	{
		char *s = new char[strlen(s1.ptr) + strlen(ptr) + 1];

		int i = 0;

		while(ptr[i])
		{
			s[i] = ptr[i];
			i++;
		}

		int j = 0;

		while(s1.ptr[j])
		{
			s[i] = s1.ptr[j];
			j++,i++;
		}
		s[i] = '\0';

		delete [] ptr;

		ptr = new char[strlen(s)];

		i = 0;

		while(s[i]) {
			ptr[i] = s[i];
			i++;
		}

		ptr[i] = '\0';

		delete [] s;
	}






	// C string functions 
	char * strcpy(STRING &s1 ,const STRING &s2)  
	{
		if(!s2.ptr) return s1.ptr;

		if(s1.ptr != nullptr)
			delete [] s1.ptr;

		s1.ptr = new char[strlen(s2.ptr)+1];

		int i = 0;

		while(s2.ptr[i]) {
			s1.ptr[i] = s2.ptr[i];
			i++;
		}
		s1.ptr[i] = s2.ptr[i];

		return s1.ptr;
	}

	char * strncpy(STRING& s1 , const STRING & s2, const int n)  
	{

		if(!s2.ptr || !n) return s1.ptr;

		if(s1.ptr != nullptr)
			delete [] s1.ptr;

		s1.ptr = new char[n + 1];

		int i = 0;

		while(i < n) {
			s1.ptr[i] = s2.ptr[i];
			i++;
		}

		s1.ptr[i] = '\0';

		return s1.ptr;
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


	char * strcat(STRING &s1 , const STRING &s2)  
	{
		if(s2.ptr == nullptr) return 0;

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
		return s1.ptr;
	}


	char * strncat(STRING &s1 , const STRING & s2,const int n) 
	{
		if(s2.ptr == nullptr || !n) return s1.ptr;

		int len1 = 0;
		while(s1.ptr[len1]) len1++;

		int len2 = 0;
		while(s2.ptr[len2]) len2++;

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

		return s1.ptr;
	}

	char * strrev(STRING &s)  
	{
		if(!s.ptr) return 0;

		int len = 0;

		while(s.ptr[len])
			len++;

		for(int i = 0, j = len - 1 ; i < j ; i++, j--) {
			int t = s.ptr[i];
			s.ptr[i] = s.ptr[j];
			s.ptr[j] = t;
		}
		return s.ptr;
	}

	char * strupper(STRING &s)  
	{
		if(!s.ptr) return 0;

		for(int i = 0 ; s.ptr[i] ; i++)
			if(s.ptr[i] >= 'a' && s.ptr[i] <= 'z') s.ptr[i] -= 32;
		return s.ptr;
	}


	char * strlower(STRING &s)  
	{
		if(!s.ptr) return 0;

		for(int i = 0 ; s.ptr[i] ; i++)
			if(s.ptr[i] >= 'A' && s.ptr[i] <= 'Z') s.ptr[i] += 32;

		return s.ptr;
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

		while(s.ptr[len]) len++;

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

		return len - 1;

	}

	char * strstr(const STRING& s1 , const STRING & s2)   
	{
		if(!s1.ptr || !s2.ptr) return 0;

		for(int i = 0 ; s1.ptr[i] ; i++) {
			int j = 0;

			for(int k = i ; s1.ptr[k] && s2.ptr[j] ; j++,k++)
				if(s1.ptr[k] != s2.ptr[j]) break;

			if(s2.ptr[j] == 0) return s1.ptr + i;
		}

		return 0;
	}

}
