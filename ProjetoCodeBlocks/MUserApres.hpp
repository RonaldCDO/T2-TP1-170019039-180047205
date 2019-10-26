#pragma once

#include "interfaces.hpp"

using namespace std;

class CntrUserApres : public IUserApres
{
    private:
        IUserServ * cntrUserServ;
        const static int MAX_TENTATIVAS = 3;

        //static int obterDadoUsuario(Usuario * usuario, Dominio * dominio, string classeDominio);

        static bool obterContaCorrente (Conta * conta);
    public:
        void setCntrUserServ (IUserServ * cntrUserServ)
        {
            this->cntrUserServ = cntrUserServ;
        }

        void cadastrar() throw(runtime_error);
};