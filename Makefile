CXX := g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# install: fireworks-app
# 	mv fireworks 

clean:
	rm -f fireworks-app *.o

fireworks-app: main.o FireworkRocket.o PhysicsHandler.o DebugHandler.o Utility.o
	$(CXX) -o fireworks-app main.o FireworkRocket.o PhysicsHandler.o DebugHandler.o Utility.o $(LIBS)

main.o: main.cpp
	$(CXX) -c "main.cpp" -o main.o

FireworkRocket.o: FireworkRocket.cpp
	$(CXX) -c "FireworkRocket.cpp" -o FireworkRocket.o

PhysicsHandler.o: PhysicsHandler.cpp
	$(CXX) -c "PhysicsHandler.cpp" -o PhysicsHandler.o

DebugHandler.o: DebugHandler.cpp
	$(CXX) -c "DebugHandler.cpp" -o DebugHandler.o

Utility.o: Utility.cpp
	$(CXX) -c "Utility.cpp" -o Utility.o