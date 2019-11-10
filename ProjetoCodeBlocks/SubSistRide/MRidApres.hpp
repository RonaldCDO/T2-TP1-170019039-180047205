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

        void reservarCarona() throw(runtime_error);
};



class TelaDadosCarona
{
    private:
        const static int MAX_TENTATIVAS = 3;

    public:
        bool run(Carona * carona);
};



class TelaDadosReserva
{
    private:
        const static int MAX_TENTATIVAS = 3;

    public:
        bool run(CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag);
};
