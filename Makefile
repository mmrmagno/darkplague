CXX = g++
CXXFLAGS = -std=c++11 -Wall

LIBS = -lSDL2 -lSDL2_mixer -lGLEW -lGL -lGLU

SRC = src/main.cpp src/Renderer.cpp src/Shader.cpp src/Player.cpp src/Enemy.cpp src/Physics.cpp src/Input.cpp src/Sound.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = dark_plague

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJ) $(TARGET)
