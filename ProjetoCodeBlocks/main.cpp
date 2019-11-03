#include <iostream>
#include <string>

#include "dominios.hpp"
#include "entidades.hpp"
#include "MAutApres.hpp"
#include "MUserApres.hpp"
#include "stubs.hpp"

using namespace std;

int main()
{
    //////// Teste da Controladora de Apresentação da Autenticação ////////
    
    IAutServ * stubAut;
    stubAut = new StubCntrAutServ();

    CntrAutApres caa;

    Email * email;
    email = new Email();

    bool autenticado;

    caa.setCntrAutServ(stubAut);

    try
    {
        autenticado = caa.autenticar(email);

        if (autenticado)
        {
            cout << "Autenticação com sucesso!" << endl;
        }
        else
            cout << "Autenticação com falha!" << endl;
    }
    catch (const runtime_error& exp)
    {
        cout << exp.what() << endl;
    }


    //////// Teste da Controladora de Apresentação de Usuário ////////
/*
    IUserServ * stubServ;
    stubServ = new StubCntrUserServ;

    CntrUserApres controladoraU;

    controladoraU.setCntrUserServ(stubServ);

    try
    {   
        controladoraU.cadastrar();
    }
    catch (const runtime_error& exp)
    {
        cout << exp.what() << endl;
    }
*/

    //////// Teste Make File ////////
/*
    Usuario user;
    Nome nome;

    nome.setValor("Matheus");
    user.setNome(nome);

    cout << user.getNome().getValor() << endl;
*/
    return 0;
}
