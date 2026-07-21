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
			//bool operator > (STRING &) const;
			//bool operator < (STRING &) const;
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

// friend functions
friend void strcpy(STRING & , const STRING &);
friend void strncpy(STRING& , const STRING &, const int);
friend int strcmp(const STRING& , const STRING&);
friend int strncmp(const STRING& ,const STRING& , const int);
friend void strcat(STRING & , const STRING &);
friend void strncat(STRING & , const STRING & ,const int);
friend void strrev(STRING &);
friend void strupper(STRING &);
friend void strlower(STRING &);
friend char * strchr(const STRING& , const char);
friend char * strrchr(const STRING& , const char);
friend char * strstr(const STRING& , const char *);
friend unsigned int strlen(const STRING&);


	};
}


#endif
