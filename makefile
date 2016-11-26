HEADERS = linkedlist.h
OBJECTS = linkedlist.o main.o
Program1: $(OBJECTS)
	g++ $^ -o Program1
%.o: %.cpp $(HEADERS)
	g++ -c $< -o $@ 
clean:
	rm -f *.o Program1

