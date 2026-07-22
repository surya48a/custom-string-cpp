#ifndef STRING_H_
#define STRING_H_

#include<iostream>
#include<cstring>
using namespace std;

namespace surya
{
	class STRING
	{
		private:
			char * ptr;
		public:

			// Constructors and destructors declarations
			STRING();
			STRING(const char*);
			STRING(STRING &);
			STRING operator = (STRING &);
			~STRING();

			// Relational and logical operator overloading declarations
			STRING& operator +(STRING &);
			char& operator [](const int) const;
			bool operator > (STRING &) const;
			bool operator < (STRING &) const;
			bool operator >= (STRING &) const;
			bool operator <= (STRING &) const;
			bool operator != (STRING &) const;
			bool operator == (STRING &) const;

			// insertion and extraction operator overloading declarations
			friend istream& operator >> (istream& , STRING &);
			friend ostream& operator << (ostream& , STRING &);

			// Extra features
			char& at(const int) const;
			char& front() const;
			char& back() const;
			unsigned int length() const;
			unsigned int size() const;
			bool empty() const;
			const char * c_str() const;
			void clear();
bool compare(const STRING &) const;
void push_back(const char);
void pop_back();


			// friend functions
			friend char * strcpy(STRING & , const STRING &);
			friend char * strncpy(STRING& , const STRING &, const int);
			friend int strcmp(const STRING& , const STRING&);
			friend int strncmp(const STRING& ,const STRING& , const int);
			friend char *strcat(STRING & , const STRING &);
			friend char * strncat(STRING & , const STRING & ,const int);
			friend char * strrev(STRING &);
			friend char * strupper(STRING &);
			friend char * strlower(STRING &);
			friend char * strchr(const STRING& , const char);
			friend char * strrchr(const STRING& , const char);
			friend char * strstr(const STRING& , const char *);
			friend unsigned int strlen(const STRING&);
                        friend char * strstr(const STRING& , const STRING &);

	};
}


#endif
