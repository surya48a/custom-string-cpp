# Custom String Class Implementation in Modern C++

A custom implementation of a dynamic string class in C++ without using the Standard Template Library (`std::string`) for string operations. This project is developed to understand dynamic memory management, operator overloading, copy semantics, move semantics, and object-oriented programming concepts.

---

## Features

### Constructors & Destructor
- Default Constructor
- Parameterized Constructor
- Deep Copy Constructor
- Destructor
- Copy Assignment Operator
- Move Constructor (In Progress)
- Move Assignment Operator (In Progress)

### Operator Overloading
- `+`
- `+=`
- `[]`
- `==`
- `!=`
- `<`
- `>`
- `<=`
- `>=`
- `<<`
- `>>`

### String Member Functions
- `length()`
- `size()`
- `empty()`
- `clear()`
- `front()`
- `back()`
- `at()`
- `push_back()`
- `pop_back()`
- `append()`
- `compare()`
- `find()`
- `swap()`
- `c_str()`

### Custom C-Style String Functions
- `strcpy()`
- `strncpy()`
- `strcmp()`
- `strncmp()`
- `strcat()`
- `strncat()`
- `strlen()`
- `strrev()`
- `strupper()`
- `strlower()`
- `strchr()`
- `strrchr()`
- `strstr()`

---

## Project Structure

```
custom-string-cpp/
│
├── include/
│ └── String.h
│
├── src/
│ └── String.cpp
│
├── tests/
│ └── main.cpp
│
├── Makefile
├── .gitignore
└── README.md
```

---

## Build

Compile using Makefile

```bash
make
```

Run

```bash
./my_string
```

Clean

```bash
make clean
```

---

## Technologies Used

- C++17
- Object-Oriented Programming
- Dynamic Memory Allocation
- Operator Overloading
- Rule of Five
- GNU Make
- Git & GitHub
- Ubuntu Linux

---

## Learning Objectives

This project was created to strengthen understanding of:

- Dynamic memory allocation
- Deep copy vs shallow copy
- Copy constructor
- Assignment operator
- Move semantics
- Friend functions
- Operator overloading
- String manipulation algorithms
- Makefile
- Git workflow

---

## Future Improvements

- Complete move constructor
- Complete move assignment operator
- insert()
- erase()
- replace()
- substr()
- starts_with()
- ends_with()
- capacity()
- reserve()
- Exception handling
- Unit testing

---

## Author

Surya

GitHub: https://github.com/surya48a
