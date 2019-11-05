#pragma once

#include "interfaces.hpp"

using namespace std;

class CntrRidApres : public IRidApres
{
    private:
        IRideServ * cntrAutServ;


    public:
        void setCntrRidServ (IRidServ * cntrRidServ)
        {
            this->cntrRidServ = cntrRidServ;
        }

        bool cadastrarCarona (CodigoDeCarona * codigoDeCarona, Cidade * cidadeDeOrigem,
                              Estado * estadoDeOrigem, Cidade * cidadeDeDestino,
                              Estado * estadoDeDestino, Data * dataDePartida,
                              Duracao * duracao, Vagas * vagas, Preco * preco) throw(runtime_error);
};
