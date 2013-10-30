main: main.o animal.o bird.o mammal.o reptile.o eagle.o elephant.o skunk.o python.o crocodilia.o
	g++ -pedantic -o main main.o animal.o bird.o mammal.o reptile.o eagle.o elephant.o skunk.o python.o crocodilia.o

main.o: main.cpp animal.o
	g++ -pedantic -Wall -c main.cpp

eagle.o: eagle.cpp eagle.h bird.o
	g++ -pedantic -Wall -c eagle.cpp

elephant.o: elephant.cpp elephant.h mammal.o
	g++ -pedantic -Wall -c elephant.cpp

skunk.o: skunk.cpp skunk.h mammal.o
	g++ -pedantic -Wall -c skunk.cpp

python.o: python.cpp python.h reptile.o
	g++ -pedantic -Wall -c python.cpp

crocodilia.o: crocodilia.cpp crocodilia.h reptile.o
	g++ -pedantic -Wall -c crocodilia.cpp

bird.o: bird.cpp bird.h animal.o
	g++ -pedantic -Wall -c bird.cpp

mammal.o: mammal.cpp mammal.h animal.o
	g++ -pedantic -Wall -c mammal.cpp

reptile.o: reptile.cpp reptile.h animal.o
	g++ -pedantic -Wall -c reptile.cpp

clean:
	rm main main.o bird.o eagle.o reptile.o mammal.o
