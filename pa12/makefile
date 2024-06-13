CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

TARGET = MyStringApp
SRC = myString.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

