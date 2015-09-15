main: main.o
		g++ -g -fno-inline -Dprotected=public -Dprivate=public main.o -o main
main.o: main.cpp
		g++ -c -g -fno-inline -Dprotected=public -Dprivate=public main.cpp
clean:
		rm -rf *.o main
