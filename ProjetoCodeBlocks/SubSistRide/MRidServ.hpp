#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrRidServ : public IRidServ
{
    public:
        bool cadastrarCarona (Carona * carona) throw(runtime_error);
        bool descadastrarCarona (CodigoDeCarona codigo) throw(runtime_error);
        bool efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, Conta * prestador) throw(runtime_error); 
};
