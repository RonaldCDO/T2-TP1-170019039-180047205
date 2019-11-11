#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrRidServ : public IRidServ
{
    public:
        bool cadastrarCarona (Carona * carona, Email * email) throw(runtime_error);
        bool descadastrarCarona (CodigoDeCarona codigo) throw(runtime_error);
        bool efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, Conta * conta1, Conta * conta2, Email * email) throw(runtime_error);
};
