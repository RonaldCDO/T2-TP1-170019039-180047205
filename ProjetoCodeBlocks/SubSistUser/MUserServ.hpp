#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrUserServ : public IUserServ
{
    public:
        bool cadastrarUsuario (Usuario * usuario) throw(runtime_error);
        void cadastrarConta (Conta * conta) throw(runtime_error);
        //void listarReservas (Email email, Carona * carona, CodigoDeCarona * codigoDeCarona,
        //                     Usuario * usuario, Reserva * reserva)throw(runtime_error);
        bool excluir (Email email) throw(runtime_error);
};
