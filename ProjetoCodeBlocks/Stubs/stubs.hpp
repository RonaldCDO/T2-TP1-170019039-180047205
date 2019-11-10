#pragma once

#include "interfaces.hpp"

using namespace std;



class StubCntrAutServ : public IAutServ
{
    public:
        bool autenticar (Email * email, Senha senha) throw(runtime_error);
};



class StubCntrUserServ : public IUserServ
{
    public:
        bool cadastrarUsuario (Usuario * usuario) throw(runtime_error);
        bool cadastrarConta (Conta * conta) throw(runtime_error);
        bool excluir (Email email) throw(runtime_error);
};



class StubCntrRidServ : public IRidServ
{
    public:
        bool cadastrarCarona(Carona * carona) throw(runtime_error);
};
