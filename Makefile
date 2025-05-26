CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./
BUILD_DIR = build

# Include all cpp files from relevant subdirectories
SRC := $(wildcard main.cpp memory/*.cpp scheduling/*.cpp syscalls/*.cpp threads/*.cpp virtual_memory/*.cpp)
OBJ := $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC))
TARGET := $(BUILD_DIR)/main.exe

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp to .o inside build/
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build directory
clean:
	rm -rf $(BUILD_DIR)
