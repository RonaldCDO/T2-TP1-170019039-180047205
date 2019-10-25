#include <iostream>
#include <string>

#include "dominios.hpp"
#include "entidades.hpp"
#include "MAutApres.hpp"
#include "MAutServ.hpp"

using namespace std;

int main()
{
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

    cout << "O e-mail cadastrado foi " << email->getValor() << endl;

    return 0;
}
