#pragma once

#include <iostream>
#include <curses.h>
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
        //virtual void excluir(Email * email) throw(runtime_error) = 0;
};



class IUserServ
{
    public:
        virtual bool cadastrar(Usuario * usuario, Conta * conta1, Conta * conta2) throw(runtime_error) = 0;
};