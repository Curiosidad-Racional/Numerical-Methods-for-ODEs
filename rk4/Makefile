proj=rk4
bin=bin
build=build
src=src

main: ${src}/rk4.h ${src}/main.cpp
	g++ -o ${bin}/${proj} ${src}/main.cpp -std=c++11
clean:
	rm -f ${build}/*.o
eclean:
	rm -f ${src}/*~
run: ${bin}/${proj}
	${bin}/${proj}
