# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC_DIR = src
BUILD_DIR = build

# Sources
SOURCES = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)  # Inclut tout fichier .cpp dans src
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))
MAIN = main.cpp  # Mise à jour pour indiquer que main.cpp est au niveau du projet

# Exécutable
TARGET = PieceOutGame

all: $(TARGET)

$(TARGET): $(OBJECTS) $(MAIN)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(MAIN) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
