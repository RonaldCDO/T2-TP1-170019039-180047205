#include <iostream>

#include <string>
#include <string.h>

#include <curses.h>
//#include "curses.h"

#include "dominios.hpp"
#include "entidades.hpp"

#include "MAutApres.hpp"
#include "MUserApres.hpp"
#include "MRidApres.hpp"
#include "MUserServ.hpp"
#include "MAutServ.hpp"
#include "MRidServ.hpp"

#include "MInit.hpp"

#include "containers.hpp"

using namespace std;

int main()
{
    IAutServ * cntrAutServ;
    cntrAutServ = new CntrAutServ();

    IUserServ * cntrUserServ;
    cntrUserServ = new CntrUserServ();

    IRidServ * cntrRidServ;
    cntrRidServ = new CntrRidServ();

    CntrAutApres * cntrAutApres;
    cntrAutApres = new CntrAutApres();

    CntrUserApres * cntrUserApres;
    cntrUserApres = new CntrUserApres();

    CntrRidApres * cntrRidApres;
    cntrRidApres = new CntrRidApres();

    cntrAutApres->setCntrAutServ(cntrAutServ);
    cntrUserApres->setCntrUserServ(cntrUserServ);
    cntrRidApres->setCntrRidServ(cntrRidServ);

    CntrInicializacao telaInicial;

    telaInicial.setCntrAutApres(cntrAutApres);
    telaInicial.setCntrUserApres(cntrUserApres);
    telaInicial.setCntrRidApres(cntrRidApres);


    telaInicial.IniciarSistema();

    return 0;
}
