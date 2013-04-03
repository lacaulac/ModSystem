all:
	g++ libdlc.cpp -shared -o libdlc.so
	cp libdlc.so libdlc.dylib
	mv libdlc.so ../bin
	mv libdlc.dylib ../bin
	cp libdlc.h ../bin
configure:
	mkdir ../bin
clean:
	rm -rf ../bin
prep:
	rm -rf ../bin/*
