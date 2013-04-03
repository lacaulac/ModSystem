#include <iostream>
#include "libtest.h"

using namespace std;

extern "C" void testFunc()
{
	cout << "Ceci est un test" << endl;
}