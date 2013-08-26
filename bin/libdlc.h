#include <dlfcn.h>

#ifndef LIBRARY_DLC_DLFCN
#define LIBRARY_DLC_DLFCN

class DLCLibrary
{
protected:
	void *m_library; //Va recevoir la librairie
	void *initializer; //Va faire le tampon pour les fonctions provenants de la librairie
	std::string m_chemin; //Le chemin de la librairie
	int m_par1; //L'argument de chargement, par défaut RTLD_LAZY
	int m_quit; //Recupere la valeur de liberation de mémoire renvoyée par dlclose.
public:
	DLCLibrary(std::string chemin); //Constructeur avec RTLD_LAZY
	DLCLibrary(std::string chemin, int par1); //Constructeur avec choix de l'argument de chargement
	void freeMemory(); //Libération de la mémoire
	template <class Func>
	Func getFunction(std::string nomFunc) //Récupérer une fonction de n'importe quel type
	{
		void* initializer = dlsym(m_library, nomFunc.c_str());
        Func init_func = (Func)initializer;
        return init_func;
	}
	bool isLoaded(); //Verifier que la librairie est chargée
};

#endif
typedef void (*function_type)();