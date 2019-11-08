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
        bool cadastrar (Usuario * usuario, Conta * conta1, Conta * conta2) throw(runtime_error);
};



class StubCntrRidServ : public IRidServ
{
    public:
        bool cadastrarCarona(Carona * carona) throw(runtime_error);
};
