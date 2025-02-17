# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -I/usr/include/SDL2 -Isrc -Isrc/ECS -Isrc/ECS/Components

# Linker flags
LDFLAGS = `sdl2-config --libs` -lSDL2_image

# Source files
SOURCES = $(shell find src -name "*.cpp")

# Object files
OBJECTS = $(patsubst src/%, build/obj/%, $(SOURCES:.cpp=.o))

# Executable name
TARGET = build/bin/game

# Default target
all: $(TARGET)@echo "fin"


# Build the executable
$(TARGET): $(OBJECTS)
	@ $(CXX) -o $@ $^ $(LDFLAGS)
	@ echo "fin"

# Compile source files
build/obj/%.o: src/%.cpp
	@ mkdir -p $(dir $@)
	@ $(CXX) $(CXXFLAGS) -c $< -o $@
	@ echo "$<"

# Clean up
clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)