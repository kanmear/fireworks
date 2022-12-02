CXX := g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# install: fireworks-app
# 	mv fireworks 

fireworks-app: main.o FireworkRocket.o
	$(CXX) -o fireworks-app main.o FireworkRocket.o $(LIBS)

main.o: main.cpp
	$(CXX) -c "main.cpp" -o main.o

FireworkRocket.o: FireworkRocket.cpp
	$(CXX) -c "FireworkRocket.cpp" -o FireworkRocket.o
