all: routing.out

routing.out: main.o CommandHandler.o LSRPProtocol.o NetworkTopology.o DVRPProtocol.o
	g++  main.o CommandHandler.o LSRPProtocol.o NetworkTopology.o DVRPProtocol.o -o routing.out

main.o: main.cpp CommandHandler.hpp
	g++ -c main.cpp -o main.o

CommandHandler.o: CommandHandler.cpp CommandHandler.hpp NetworkTopology.hpp Constants.hpp
	g++ -c CommandHandler.cpp -o CommandHandler.o

LSRPProtocol.o: LSRPProtocol.cpp LSRPProtocol.hpp Constants.hpp
	g++ -c LSRPProtocol.cpp -o LSRPProtocol.o

NetworkTopology.o: NetworkTopology.cpp NetworkTopology.hpp Constants.hpp LSRPProtocol.hpp DVRPProtocol.hpp
	g++ -c NetworkTopology.cpp -o NetworkTopology.o

DVRPProtocol.o: DVRPProtocol.cpp DVRPProtocol.hpp Constants.hpp
	g++ -c DVRPProtocol.cpp -o DVRPProtocol.o	

clean:
	rm -r -f *.out
	rm -r -f *.o