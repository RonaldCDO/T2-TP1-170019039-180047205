#pragma once

#include <iostream>
#include <curses.h>
#include <string.h>
#include <string>
#include <vector>

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
        virtual void cadastrarConta(Conta * conta) throw(runtime_error) = 0;
        virtual bool excluir(Email email) throw(runtime_error) = 0;

        virtual ~IUserServ(){}
};



class IRidApres
{
    public:
        virtual void cadastrarCarona(Email * email) throw(runtime_error) = 0;
        virtual void descadastrarCarona(Email * email) throw(runtime_error) = 0;
        virtual void reservarCarona(Email * email) throw(runtime_error) = 0;
        virtual void obterDadosCarona() = 0;
        virtual void listarReservas(Email * email) = 0;
        virtual void cancelarReserva(Email * email) = 0; 

        virtual ~IRidApres(){}
};



class IRidServ
{
    public:
        virtual bool cadastrarCarona (Carona * carona, Email * email) throw(runtime_error) = 0;
        virtual int descadastrarCarona (Email * email, CodigoDeCarona * codigo) throw(runtime_error) = 0;
        virtual bool efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, vector<Conta> * vetorDeContas, Email * email) throw(runtime_error) = 0;
        virtual vector<Carona> pesquisarCaronas(Carona * dominiosSolicitados) = 0;
        virtual bool listarReservas(Email * email, CodigoDeCarona * rideCode, vector<Reserva> * vetorDeReservas) = 0;
        virtual bool cancelarReserva(CodigoDeReserva * reservaCode) = 0;

        virtual ~IRidServ(){}
};
