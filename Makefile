CXX := g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# install: fireworks-app
# 	mv fireworks 

fireworks-app: main.o fireworks.o
	$(CXX) -o fireworks-app main.o fireworks.o $(LIBS)

main.o: main.cpp
	$(CXX) -c "main.cpp" -o main.o

main.o: fireworks.cpp
	$(CXX) -c "fireworks.cpp" -o fireworks.o