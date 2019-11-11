#pragma once

#include <iostream>
#include <string>
//#include <list>
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
        Usuario obterUsuario (Email email);
        bool compararEmailSenha (Email email, Senha senha);
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
        //bool obterConta (Conta conta);
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
        //bool verifConflitoData(Carona carona);
};