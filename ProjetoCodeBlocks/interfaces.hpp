#pragma once

#include <iostream>
#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;

class IAutApres
{
    public:
        virtual bool autenticar(Email * email) throw(runtime_error) = 0;

        virtual ~IAutApres(){}
};



class IAutServ
{
    public:
        virtual bool autenticar(Email * email, Senha senha) throw(runtime_error) = 0;

        virtual ~IAutServ(){}
};



class IUserApres
{
    public:
        virtual void cadastrar() throw(runtime_error) = 0;
};



class IUserServ
{
    public:
        virtual bool cadastrar(Usuario * usuario) throw(runtime_error) = 0;
}