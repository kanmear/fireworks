CXX := g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
PROFILER = -pg

# install: fireworks-app
# 	mv fireworks 

clean:
	rm -f fireworks-app *.o

profiler: main.o FireworkRocket.o FireworkParticle.o PhysicsHandler.o DebugHandler.o Utility.o
	$(CXX) $(PROFILER) -o fireworks-app main.o FireworkRocket.o FireworkParticle.o PhysicsHandler.o DebugHandler.o Utility.o $(LIBS)

fireworks-app: main.o FireworkRocket.o FireworkParticle.o PhysicsHandler.o DebugHandler.o Utility.o
	$(CXX) -o fireworks-app main.o FireworkRocket.o FireworkParticle.o PhysicsHandler.o DebugHandler.o Utility.o $(LIBS)

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