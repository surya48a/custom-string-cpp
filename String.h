#ifndef STRING_H_
#define STRING_H_

#include<iostream>
#include<cstring>

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
			STRING operator = (const STRING &);
			~STRING();

			// Relational and logical operator overloading declarations
			STRING& operator +=(const STRING &);
			STRING operator +(const STRING&) const;
			STRING operator +(const char *) const;
			friend STRING operator +(const char *s , const STRING& t);

			char& operator [](const int) const;
			bool operator > (const STRING &) const;
			bool operator < (const STRING &) const;
			bool operator >= (const STRING &) const;
			bool operator <= (const STRING &) const;
			bool operator != (const STRING &) const;
			bool operator == (const STRING &) const;

			// insertion and extraction operator overloading declarations
			friend std::istream& operator >> (std::istream& , STRING &);
			friend std::ostream& operator << (std::ostream& , STRING &);

			// Basic functions in c++ string class
			char& at(const int) const;
			char& front() const;
			char& back() const;
			unsigned int length() const;
			unsigned int size() const;
			bool empty() const;
			const char * c_str() const;
			void clear();
			void push_back(const char);
			void pop_back();
			int find(const char *) const;
			void swap(STRING &);
			int compare(const STRING &) const;
			void append(const STRING &);



			// friend functions declarations
			friend char * strcpy(STRING & , const STRING &);
			friend char * strncpy(STRING& , const STRING &, const int);
			friend int strcmp(const STRING& , const STRING&);
			friend int strncmp(const STRING& ,const STRING& , const int);
			friend char * strcat(STRING & , const STRING &);
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
