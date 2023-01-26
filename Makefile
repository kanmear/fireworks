CXX := g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f fireworks-app *.o

fireworks-app: main.o FireworkRocket.o FireworkParticle.o PhysicsHandler.o DebugHandler.o Utility.o Settings.o
	$(CXX) -o fireworks-app main.o FireworkRocket.o FireworkParticle.o PhysicsHandler.o DebugHandler.o Utility.o Settings.o $(LIBS)

main.o: main.cpp
	$(CXX) -c "main.cpp" -o main.o

FireworkRocket.o: FireworkRocket.cpp
	$(CXX) -c "FireworkRocket.cpp" -o FireworkRocket.o

FireworkParticle.o: FireworkParticle.cpp
	$(CXX) -c "FireworkParticle.cpp" -o FireworkParticle.o

PhysicsHandler.o: PhysicsHandler.cpp
	$(CXX) -c "PhysicsHandler.cpp" -o PhysicsHandler.o

DebugHandler.o: DebugHandler.cpp
	$(CXX) -c "DebugHandler.cpp" -o DebugHandler.o

Utility.o: Utility.cpp
	$(CXX) -c "Utility.cpp" -o Utility.o

Settings.o: Settings.cpp
	$(CXX) -c "Settings.cpp" -o Settings.o