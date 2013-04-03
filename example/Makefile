all:
	g++ -shared libtest.cpp -o libtest.so
	g++ test.cpp -o test -L. -ldlc
debug:
	g++ -shared libtest.cpp -o libtest.so -g
	g++ test.cpp -o test -L. -ldlc -g
