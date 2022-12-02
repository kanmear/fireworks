CXX := g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# install: fireworks-app
# 	mv fireworks 

fireworks-app: FireworkRocket.o main.o
	$(CXX) -o fireworks-app main.o fireworks.o $(LIBS)

FireworkRocket.o: FireworkRocket.cpp
	$(CXX) -c "FireworkRocket.cpp" -o FireworkRocket.o

main.o: main.cpp
	$(CXX) -c "main.cpp" -o main.o
