CXX = clang++

CXXFLAGS = -g -W -Wall -std=c++11 -Weffc++ -Wextra -pedantic -O0

OBJS =  main.o bigInt.o

EXEC = run

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
