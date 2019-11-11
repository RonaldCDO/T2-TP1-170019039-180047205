#pragma once

#include <iostream>

#include <string>
#include <string.h>
#include <curses.h>

#include "dominios.hpp"
#include "entidades.hpp"

#include "MAutApres.hpp"
#include "MUserApres.hpp"
#include "MRidApres.hpp"
#include "MUserServ.hpp"
#include "MAutServ.hpp"
#include "MRidServ.hpp"

#include "containers.hpp"
#include "stubs.hpp"

using namespace std;


class CntrInicializacao
{
    private:
        IAutApres * cntrAutApres;
        IUserApres * cntrUserApres;
        IRidApres * cntrRidApres;

        Email * email;

    public:
        void setCntrAutApres (IAutApres * cntrAutApres)
        {
            this->cntrAutApres = cntrAutApres;
        }

        void setCntrUserApres (IUserApres * cntrUserApres)
        {
            this->cntrUserApres = cntrUserApres;
        }

        void setCntrRidApres (IRidApres * cntrRidApres)
        {
            this->cntrRidApres = cntrRidApres;
        }  

        void IniciarSistema();
};


class TelaSemLogin
{
    private:
        const int AUTENTICAR = 1;
        const int CADASTRAR = 2;
        const int LISTAR_CARONAS = 3;
        const int ENCERRAR = 9;
    
    public:
        int run();
};


class TelaLogado
{
    private:
        const int CADASTRAR_CARONA = 1;
        const int DESCADASTRAR_CARONA = 2;
        const int RESERVAR = 3;
        const int CANCELAR_RESERVA = 4;
        const int EXCLUIR_CONTA = 5;
        const int LOGOUT = 6;

    public:
        int run();
};