#pragma once

#include "interfaces.hpp"

using namespace std;

class CntrUserApres : public IUserApres
{
    private:
        IUserServ * cntrUserServ;


    public:
        void setCntrUserServ (IUserServ * cntrUserServ)
        {
            this->cntrUserServ = cntrUserServ;
        }

        void cadastrar() throw(runtime_error);
};