#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrRidServ : public IRidServ
{
    public:
        bool cadastrarCarona (Carona * carona, Email * email) throw(runtime_error);
        int descadastrarCarona (Email * email, CodigoDeCarona * codigo) throw(runtime_error);
        bool efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, vector<Conta> * vetorDeContas, Email * email) throw(runtime_error);
        vector<Carona> pesquisarCaronas(Carona * dominiosSolicitados);
        bool listarReservas(Email * email, CodigoDeCarona * rideCode, vector<Reserva> * vetorDeReservas);
        bool cancelarReserva(CodigoDeReserva * reservaCode);
};
