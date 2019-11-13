#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "dominios.hpp"
#include "entidades.hpp"

using namespace std;


class ContainerUsuarios
{
    private:
        static ContainerUsuarios * refContUser;
        static bool RepositorioCriado;

        ContainerUsuarios(){}

        vector<Usuario> repositorioUsuarios;


    public:
        static ContainerUsuarios * instanciar();

        void inserir(Usuario usuario);
        bool obterUsuario (Email email, Usuario * user);
};



class ContainerContas
{
    private:
        static ContainerContas * refContConta;
        static bool RepositorioCriado;

        ContainerContas(){}

        vector<Conta> repositorioContas;

    public:
        static ContainerContas * instanciar();

        void inserir(Conta conta);
        bool obterConta (Usuario usuario, Conta * conta1, Conta * conta2); //Se true, possui duas contas.
};


class ContainerCaronas
{
    private:
        static ContainerCaronas * refContCarona;
        static bool RepositorioCriado;

        ContainerCaronas(){}

        vector<Carona> repositorioCaronas;

    public:
        static ContainerCaronas * instanciar();

        void inserir(Carona carona);
        bool verificarConflitoDeData (Usuario * usuario, Carona * carona);
        Carona * buscarCarona (CodigoDeCarona * rideCode);
        vector<Carona> pesquisarCaronas (Carona * fonte);
        void excluir(CodigoDeCarona rideCode);
};


class ContainerReservas
{
    private:
        static ContainerReservas * refContReserva;
        static bool RepositorioCriado;

        ContainerReservas(){}

        vector<Reserva> repositorioReservas;

    public:
        static int ultimaReservaCriada;

        static ContainerReservas * instanciar();

        void inserir(Reserva reserva);
        Reserva obterReservas(CodigoDeReserva * reserveCode);
        vector<Reserva> listarReservasDeCarona(CodigoDeCarona * rideCode);
        bool excluirReserva(CodigoDeReserva * reserveCode, CodigoDeCarona * rideCode);
};
