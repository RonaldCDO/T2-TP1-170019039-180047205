#pragma once

#include "interfaces.hpp"

using namespace std;


class CntrAutServ : public IAutServ
{
    public:
        bool autenticar(Email * email, Senha senha);
};

