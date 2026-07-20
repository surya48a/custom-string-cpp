#ifndef STRING_H_
#define STRING_H_

#include<cstring>
#include<iostream>
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
			STRING operator +(STRING &);
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

	};
}

#include "string.cpp"

#endif
