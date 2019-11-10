#pragma once

#include <iostream>
#include <curses.h>
#include <string.h>
#include <string>

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
        virtual void excluir(Email * email) throw(runtime_error) = 0;

        virtual ~IUserApres(){}
};



class IUserServ
{
    public:
        virtual bool cadastrarUsuario(Usuario * usuario) throw(runtime_error) = 0;
        virtual bool cadastrarConta(Conta * conta) throw(runtime_error) = 0;
        virtual bool excluir(Email email) throw(runtime_error) = 0;

        virtual ~IUserServ(){}
};



class IRidApres
{
    public:
        virtual void cadastrarCarona() throw(runtime_error) = 0;
        virtual void descadastrarCarona() throw(runtime_error) = 0;

        virtual ~IRidApres(){}
};



class IRidServ
{
    public:
        virtual bool cadastrarCarona (Carona * carona) throw(runtime_error) = 0;
        virtual bool descadastrarCarona (CodigoDeCarona codigo) throw(runtime_error) = 0;

        virtual ~IRidServ(){}
};
