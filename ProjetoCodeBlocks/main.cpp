#include <iostream>

#include <string>
#include <string.h>
#include <curses.h>

#include "dominios.hpp"
#include "entidades.hpp"

#include "MAutApres.hpp"
#include "MUserApres.hpp"
#include "MRidApres.hpp"
#include "MUserServ.hpp"
#include "MAutServ.hpp"
#include "MRidServ.hpp"

#include "MInit.hpp"

#include "containers.hpp"
#include "stubs.hpp"

using namespace std;

int main()
{
/*
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    Usuario user;

    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    nome.setValor("Mat");
    telefone.setValor("12-32-123456789");
    email.setValor("mat@costa");
    senha.setValor("123qw");
    cpf.setValor("052.576.591-31");

    user.setNome(nome);
    user.setTelefone(telefone);
    user.setEmail(email);
    user.setSenha(senha);
    user.setCPF(cpf);

    userRepo->inserir(user);

    Usuario * user2;
    user2 = new Usuario();

    bool found;

    found = userRepo->obterUsuario (user.getEmail(), user2);

    if (found)
    {    
        cout << user2->getCPF().getValor() << endl;
    }
*/

    //////// Teste da Controladora de Apresentação de Usuário ////////
/*
    IAutServ * cntrAutServ;
    cntrAutServ = new CntrAutServ();

    IUserServ * cntrUserServ;
    cntrUserServ = new CntrUserServ();

    IRidServ * cntrRidServ;
    cntrRidServ = new CntrRidServ();

    CntrAutApres controladoraA;
    CntrUserApres controladoraU;
    CntrRidApres controladoraR;

    controladoraA.setCntrAutServ(cntrAutServ);
    controladoraU.setCntrUserServ(cntrUserServ);
    controladoraR.setCntrRidServ(cntrRidServ);

    Email * email;
    email = new Email();
    //email->setValor("mat@costa");


    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna); 

    try
    {
        controladoraU.cadastrar();

        if (controladoraA.autenticar(email))
        {
            char result[] = "Bem-vindo ao sistema!";
            mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
        }
        else
        {
            char result[] = "Nao foi possivel autenticar. Usuario nao cadastrado ou dados invalidos.";
            mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
        }
        
        getch();
        clear();

        controladoraR.cadastrarCarona(email);

        controladoraR.reservarCarona(email);
        
    }
    catch (const runtime_error& exp)
    {    
        //Bloco para transformar uma 'string' em uma array de chars 
        string erro = exp.what();
        char expArg[erro.length() + 1];
        strcpy(expArg, erro.c_str());

        mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);
    }

    getch();
    clear();                                                           
    endwin();



    //////// Teste da Controladora de Apresentação de Carona ////////
/*
    IRidServ * stubServ;
    stubServ = new StubCntrRidServ();

    CntrRidApres controladoraR;
    controladoraR.setCntrRidServ(stubServ);

    try
    {
        //controladoraR.cadastrarCarona();
        //controladoraR.descadastrarCarona();
        controladoraR.reservarCarona();
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
*/

    IAutServ * cntrAutServ;
    cntrAutServ = new CntrAutServ();

    IUserServ * cntrUserServ;
    cntrUserServ = new CntrUserServ();

    IRidServ * cntrRidServ;
    cntrRidServ = new CntrRidServ();

    CntrAutApres * cntrAutApres;
    cntrAutApres = new CntrAutApres();

    CntrUserApres * cntrUserApres;
    cntrUserApres = new CntrUserApres();

    CntrRidApres * cntrRidApres;
    cntrRidApres = new CntrRidApres();

    cntrAutApres->setCntrAutServ(cntrAutServ);
    cntrUserApres->setCntrUserServ(cntrUserServ);
    cntrRidApres->setCntrRidServ(cntrRidServ);

    CntrInicializacao telaInicial;

    telaInicial.setCntrAutApres(cntrAutApres);
    telaInicial.setCntrUserApres(cntrUserApres);
    telaInicial.setCntrRidApres(cntrRidApres);

    
    telaInicial.IniciarSistema();

    return 0;
}
