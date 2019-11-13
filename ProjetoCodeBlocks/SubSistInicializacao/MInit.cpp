#include "MInit.hpp"

using namespace std;


int TelaSemLogin::run()
{
    string autenticar_str = "Para se autenticar, digite " + to_string(AUTENTICAR) + ".";
    string cadastrar_str = "Para se cadastrar, digite " + to_string(CADASTRAR) + ".";
    string caronas_str = "Para listas as caronas disponiveis, digite " + to_string(LISTAR_CARONAS) + ".";
    string sair_str = "Para encerrar o programa, digite " + to_string(ENCERRAR) + ".";
    string opcao_str = "Opcao selecionada: ";

    char autenticar[autenticar_str.length() + 1];
    char cadastrar[cadastrar_str.length() + 1];
    char caronas[caronas_str.length() + 1];
    char sair[sair_str.length() + 1];
    char opcao[opcao_str.length() + 1];

    strcpy(autenticar, autenticar_str.c_str());
    strcpy(cadastrar, cadastrar_str.c_str());
    strcpy(caronas, caronas_str.c_str());
    strcpy(sair, sair_str.c_str());
    strcpy(opcao, opcao_str.c_str());

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2,(coluna-strlen(autenticar))/2,"%s",autenticar);
    mvprintw(linha/2 + 2,(coluna-strlen(cadastrar))/2,"%s",cadastrar);
    mvprintw(linha/2 + 4,(coluna-strlen(caronas))/2,"%s",caronas);
    mvprintw(linha/2 + 6,(coluna-strlen(sair))/2,"%s",sair);
    mvprintw(linha/2 + 8,(coluna-strlen(opcao))/2,"%s",opcao);

    char escolha[1];
    getstr(escolha);

    clear();
    endwin();


    int escolha_int = (int)(escolha[0] - '0');

    return escolha_int;
}


int TelaLogado::run()
{
    string cadastCarona_str = "Para cadastrar uma carona, digite " + to_string(CADASTRAR_CARONA) + ".";
    string descadCarona_str = "Para descadastrar uma carona, digite " + to_string(DESCADASTRAR_CARONA) + ".";
    string reservar_str = "Para efetuar uma reserva em uma carona, digite " + to_string(RESERVAR) + ".";
    string cancReserva_str = "Para cancelar uma reserva, digite " + to_string(CANCELAR_RESERVA) + ".";
    string listarReserva_str = "Para listar reservas associadas a suas caronas, digite " + to_string(LIST_RESERVAS) + ".";
    string excluir_str = "Para excluir sua conta, digite " + to_string(EXCLUIR_CONTA) + ".";
    string logout_str = "Para sair, digite " + to_string(LOGOUT) + ".";
    string opcao_str = "Opcao selecionada: ";

    char cadastCarona[cadastCarona_str.length() + 1];
    char descadCarona[descadCarona_str.length() + 1];
    char reservar[reservar_str.length() + 1];
    char cancReserva[cancReserva_str.length() + 1];
    char listarReserva[listarReserva_str.length() + 1];
    char excluir[excluir_str.length() + 1];
    char logout[logout_str.length() + 1];
    char opcao[opcao_str.length() + 1];

    strcpy(cadastCarona, cadastCarona_str.c_str());
    strcpy(descadCarona, descadCarona_str.c_str());
    strcpy(reservar, reservar_str.c_str());
    strcpy(cancReserva, cancReserva_str.c_str());
    strcpy(listarReserva, listarReserva_str.c_str());
    strcpy(excluir, excluir_str.c_str());
    strcpy(logout, logout_str.c_str());
    strcpy(opcao, opcao_str.c_str());

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);

    mvprintw(linha/2,(coluna-strlen(cadastCarona))/2,"%s",cadastCarona);
    mvprintw(linha/2 + 2,(coluna-strlen(descadCarona))/2,"%s",descadCarona);
    mvprintw(linha/2 + 4,(coluna-strlen(reservar))/2,"%s",reservar);
    mvprintw(linha/2 + 6,(coluna-strlen(cancReserva))/2,"%s",cancReserva);
    mvprintw(linha/2 + 8,(coluna-strlen(listarReserva))/2,"%s",listarReserva);
    mvprintw(linha/2 + 10,(coluna-strlen(excluir))/2,"%s",excluir);
    mvprintw(linha/2 + 12,(coluna-strlen(logout))/2,"%s",logout);
    mvprintw(linha/2 + 14,(coluna-strlen(opcao))/2,"%s",opcao);

    char escolha[1];
    getstr(escolha);

    clear();
    endwin();

    int escolha_int = (int)(escolha[0] - '0');

    return escolha_int;
}


void CntrInicializacao::IniciarSistema()
{
    TelaSemLogin telaInit;
    TelaLogado telaLogin;

    bool usuarioAutenticado = false;
    bool encerrarSistema = false;

    Email * email;
    email = new Email();

    while (!encerrarSistema)
    {
        switch(telaInit.run())
        {
            case 1:
                usuarioAutenticado = cntrAutApres->autenticar(email);
                break;
            
            case 2:
                cntrUserApres->cadastrar();
                break;
            
            case 3:
                cntrRidApres->obterDadosCarona();
                break;

            case 9:
                encerrarSistema = true;
                break;

            default:
                break;
        }


        while(usuarioAutenticado)
        {
            switch(telaLogin.run())
            {
                case 1:
                    cntrRidApres->cadastrarCarona(email);
                    break;
                
                case 2:
                    cntrRidApres->descadastrarCarona(email);
                    break;

                case 3:
                    cntrRidApres->reservarCarona(email);
                    break;

                case 4:
                    cntrRidApres->cancelarReserva(email);
                    break;
                
                case 5:
                    cntrRidApres->listarReservas(email);
                    break;

                case 6:
                    // Excluir usuário;
                    break;

                case 9:
                    usuarioAutenticado = false;

                default:
                    break;
            }
        }
        
    }

    return;
}