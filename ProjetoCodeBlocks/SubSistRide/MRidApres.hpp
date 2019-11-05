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

        bool cadastrarCarona (Email * email) throw(runtime_error);
        
};
