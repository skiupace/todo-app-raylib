all:
	g++ src/main.cpp -o bin/main -lraylib && make run && make clean

clean:
	rm bin/main

run:
	./bin/main
