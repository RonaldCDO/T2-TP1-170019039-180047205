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
/*    
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
*/

    IUserServ * stubServ;
    stubServ = new StubCntrUserServ;

    CntrUserApres cua;

    cua.setCntrUserServ(stubServ);

    try
    {   
        cua.cadastrar();
    }
    catch (const runtime_error& exp)
    {
        cout << exp.what() << endl;
    }
    return 0;
}
