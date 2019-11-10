#pragma once

#include "interfaces.hpp"

using namespace std;

class CntrRidApres : public IRidApres
{
    private:
        IRidServ * cntrRidServ;

    public:
        void setCntrRidServ (IRidServ * cntrRidServ)
        {
            this->cntrRidServ = cntrRidServ;
        }

        void cadastrarCarona() throw(runtime_error);

        void descadastrarCarona() throw(runtime_error);
};



/*class TelaDadosUsuario
{
    private:
        const static int MAX_TENTATIVAS = 3;

    public:
        bool run(Usuario * usuario);
};
*/


class TelaDadosCarona
{
    private:
        const static int MAX_TENTATIVAS = 3;

    public:
        bool run(Carona * carona);
};
