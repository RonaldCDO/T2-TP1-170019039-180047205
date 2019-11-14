#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrRidServ : public IRidServ
{
    public:
        bool cadastrarCarona (Carona * carona, Email * email);
        int descadastrarCarona (Email * email, CodigoDeCarona * codigo);
        bool efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, vector<Conta> * vetorDeContas, Email * email);
        vector<Carona> pesquisarCaronas(Carona * dominiosSolicitados);
        bool listarReservas(Email * email, CodigoDeCarona * rideCode, vector<Reserva> * vetorDeReservas);
        bool cancelarReserva(CodigoDeReserva * reservaCode);
};
