#include <iostream>
#include <dlfcn.h>
#include "libdlc.h"
#include "libtest.h"

using namespace std;

DLCLibrary test("libtest.so");
bool outTestLoad;
Func testf;

int main()
{
	//*cout << "Programme de test de LibDLC, par lacaulac" << endl;
	cout << "Debut du programme" << endl;
	cout << "$	Chargement de la librairie" << endl;
	outTestLoad = test.isLoaded();
	if(outTestLoad)
	{
		cout << "$	Chargement reussi" << endl;
	}
	else
	{
		cout << "$	Chargement echoue" << endl;
	}
	testf = test.getFunction("testFunc");
	testf();
	cout << "$	Liberation de la memoire" << endl;
	test.freeMemory();
	cout << "Fin du programme" << endl;//*/
	/*void *handle = dlopen("./libtest.so", RTLD_LAZY);
	typedef void (*test)();
	test hello = (test) dlsym(handle, "testFunc");
	if(!hello)
	{
		cout << "Verifiez si vous avez bien mis extern \" << endl;
	}
	hello();//*/
	return 0;
}