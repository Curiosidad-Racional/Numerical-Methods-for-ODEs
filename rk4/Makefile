bin=bin
build=build
src=src

lorenz: ${src}/rk4.h ${src}/lorenz.cpp
	g++ -o ${bin}/lorenz ${src}/lorenz.cpp -std=c++11
rabinovich: ${src}/rk4.h ${src}/rabinovich.cpp
	g++ -o ${bin}/rabinovich ${src}/rabinovich.cpp -std=c++11
clean:
	rm -f ${build}/*.o ${bin}/*
eclean:
	rm -f ${src}/*~
