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

        void cadastrarCarona(Email * email) throw(runtime_error);

        void descadastrarCarona(Email * email) throw(runtime_error);

        void reservarCarona(Email * email) throw(runtime_error);

        void obterDadosCarona();

        void listarReservas(Email * email);

        void cancelarReserva(Email * email);
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
        void exibirReservasAssociadas(vector<Reserva> ReservasAssociadas);
};


class TelaPesquisaCarona
{
    private:
        const static int MAX_TENTATIVAS = 3;

    public:
        bool solicitarDados(Cidade * cityOrigem, Estado * stateOrigem, Cidade * cityDestino, Estado * stateDestino, Data * partida);
        void exibirCaronasObtidas(vector<Carona> CaronasObtidas); 
};