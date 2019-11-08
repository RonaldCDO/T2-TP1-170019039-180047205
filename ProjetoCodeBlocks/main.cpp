#include <iostream>
#include <string.h>

#include <string>
#include <string.h>
#include <curses.h>

#include "dominios.hpp"
#include "entidades.hpp"
#include "MAutApres.hpp"
#include "MUserApres.hpp"
#include "MRidApres.hpp"
#include "stubs.hpp"

using namespace std;

int main()
{
    //////// Teste da Controladora de Apresentação da Autenticação ////////
/*
    IAutServ * stubAut;
    stubAut = new StubCntrAutServ();
    IRidServ * stubRid;
    stubRid = new StubCntrRidServ();

    CntrAutApres caa;
    CntrRidApres raa;

    Email * email;
    email = new Email();

    bool autenticado;

    caa.setCntrAutServ(stubAut);
    raa.setCntrRidServ(stubRid);

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

    //////// Teste da Controladora de Apresentação de Usuário ////////

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
        int linha, coluna;
        initscr();
        getmaxyx(stdscr,linha,coluna);  
    
        //Bloco para transformar uma 'string' em uma array de chars 
        string erro = exp.what();
        char expArg[erro.length() + 1];
        strcpy(expArg, erro.c_str());

        mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();                                                                       
        endwin();
    }


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
