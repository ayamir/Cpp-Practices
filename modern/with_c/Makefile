C = gcc
CXX = clang++

SOURCE_C = foo.c
OBJECT_C = foo.o

SOURCE_CXX = base.cpp

TARGET = base
LDFLAGS_COMMON = -std=c++2a

all:
	$(C) -c $(SOURCE_C)
	$(CXX) $(SOURCE_CXX) $(OBJECT_C) $(LDFLAGS_COMMON) -o $(TARGET)
clean:
	rm -fr *.o $(TARGET)
