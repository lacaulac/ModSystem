all: modsystemlib
	g++ -shared libtest.cpp -o libtest.so
	g++ test.cpp -o test -L. -ldlc
debug:
	g++ -shared libtest.cpp -o libtest.so -g
	g++ test.cpp -o test -L. -ldlc -g
modsystemlib:
	cp ../src/libdlc.cpp libdlc.cpp
	cp ../src/libdlc.h libdlc.h
	g++ -shared libdlc.cpp -o libdlc.so
