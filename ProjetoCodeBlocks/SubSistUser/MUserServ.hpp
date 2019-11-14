#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrUserServ : public IUserServ
{
    public:
        bool cadastrarUsuario (Usuario * usuario);
        void cadastrarConta (Conta * conta);
        //void listarReservas (Email email, Carona * carona, CodigoDeCarona * codigoDeCarona,
        //                     Usuario * usuario, Reserva * reserva)throw(runtime_error);
        bool excluir (Email * email);
};
