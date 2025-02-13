# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -I/usr/include/SDL2

# Linker flags
LDFLAGS = `sdl2-config --libs` -lSDL2_image

# Source files
SOURCES = $(shell find src -name "*.cpp")

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
TARGET = game

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)
