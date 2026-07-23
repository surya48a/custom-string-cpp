CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = main.o string.o

exe: $(TARGET)
	$(CXX) $(TARGET) -o my_string
main.o: main.cpp String.h
	$(CXX) $(CXXFLAGS) -c $<
string.o: string.cpp String.h
	$(CXX) $(CXXFLAGS) -c $<
clean:
	@echo "Clearing please wait ..."
	@rm -rv *.o
