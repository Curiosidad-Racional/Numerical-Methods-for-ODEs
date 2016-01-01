bin=bin
src=src
test=test

bulirsch: ${src}/runge_kutta_dopri5.cpp
	g++ -o ${bin}/lorenz ${src}/runge_kutta_dopri5.cpp -I ~/Prog/c/lib -std=c++11
clean:
	rm -f ${bin}/lorenz
eclean:
	rm -f *~ ${src}/*~ ${test}/*~
test: ${bin}/lorenz
	${bin}/lorenz
	${test}/data2avi.sh ${test}/test
data2avi:
	${test}/data2avi.sh ${test}/test
view: ${test}/test.mp4
	totem ${test}/test.mp4
