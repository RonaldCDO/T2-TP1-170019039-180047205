#pragma once

#include "interfaces.hpp"

using namespace std;

class CntrAutApres : public IAutApres
{
    private:
        IAutServ * cntrAutServ;


    public:
        void setCntrAutServ (IAutServ * cntrAutServ)
        {
            this->cntrAutServ = cntrAutServ;
        }

        bool autenticar (Email * email) throw(runtime_error);    
};