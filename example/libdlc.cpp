#include <iostream>
#include <dlfcn.h>
#include "libdlc.h"

typedef void (*funcv)(void);
typedef void (*funci)(int);

DLCLibrary::DLCLibrary(std::string chemin)
{
	m_chemin = chemin;
	m_par1 = RTLD_LAZY;
	m_library = dlopen(m_chemin.c_str(), m_par1);
	m_quit = 0;
}
DLCLibrary::DLCLibrary(std::string chemin, int par1)
{
	m_chemin = chemin;
	m_par1 = par1;
	m_library = dlopen(m_chemin.c_str(), m_par1);
	m_quit = 0;
}

void DLCLibrary::freeMemory()
{
	m_quit = dlclose(m_library);
}
	

template <class Func>
Func DLCLibrary::getFunction(std::string nomFunc)
{
        void* initializer = dlsym(m_library, nomFunc.c_str());
        Func init_func = (Func)initializer;
        return init_func;
}

funcv DLCLibrary::getFunctionv(std::string nomFunc)
{
	initializer = dlsym(m_library, nomFunc.c_str());
	funcv init_func = (funcv)initializer;
	return init_func;
	//TODO Retourner la fonction
}
funci DLCLibrary::getFunctioni(std::string nomFunc)
{
	initializer = dlsym(m_library, nomFunc.c_str());
	funci init_func = (funci)initializer;
	return init_func;
	//TODO Retourner la fonction
}
funcc DLCLibrary::getFunctionc(std::string nomFunc)
{
	initializer = dlsym(m_library, nomFunc.c_str());
	funcc init_func = (funcc)initializer;
	return init_func;
	//TODO Retourner la fonction
}
funcf DLCLibrary::getFunctionf(std::string nomFunc)
{
	initializer = dlsym(m_library, nomFunc.c_str());
	funcf init_func = (funcf)initializer;
	return init_func;
	//TODO Retourner la fonction
}
funcd DLCLibrary::getFunctiond(std::string nomFunc)
{
	initializer = dlsym(m_library, nomFunc.c_str());
	funcd init_func = (funcd)initializer;
	return init_func;
	//TODO Retourner la fonction
}

bool DLCLibrary::isLoaded()
{
	if(m_library)
	{
		return true;
	}
	else
	{
		return false;
	}
}