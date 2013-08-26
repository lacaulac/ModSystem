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