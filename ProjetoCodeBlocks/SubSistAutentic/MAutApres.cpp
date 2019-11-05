#include <string.h>
#include "MAutApres.hpp"

#include <curses.h>


using namespace std;

bool CntrAutApres::autenticar(Email * email) throw(runtime_error)
{
    //string valorEmail, valorSenha;
    Senha senha;

    const int MAX_TENTATIVAS = 3;
    int i = 0;
    bool resultado;

    while (true)
    {
        try
        {
            /*
            cout << "Digite seu E-mail cadastrado: ";
            cin >> valorEmail;
            cout << "Digite sua Senha: ";
            cin >> valorSenha;

            email->setValor(valorEmail);
            senha.setValor(valorSenha);
            */
            char campo1[]="Digite seu e-mail cadastrado: ";
            char campo2[]="Digite sua senha            : ";
            char valorEmail[60];
            char valorSenha[10];
            int linha,coluna;

            initscr();                                                                      // Inicia curses.
            getmaxyx(stdscr,linha,coluna);                                                  // Armazena quantidade de linhas e de colunas.
            mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);                        // Imprime nome do campo.
            getstr(valorEmail);                                                                  // L� dado.
            mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);                    // Imprime nome do campo.
            getstr(valorSenha);                                                                  // L� dado.
            //clear();                                                                        // Limpa janela.
            //mvprintw(linha/2,(coluna-strlen(campo1))/2,"Digitado CPF   : %s",dado1);        // Imprime dado.
            //mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"Digitada senha : %s",dado2);    // Imprime dado.
            noecho();                                                                       // Desabilita eco.
            getch();                                                                        // L� caracter digitado.
            echo();                                                                         // Habilita eco.
            endwin();

            email->setValor(valorEmail);
            senha.setValor(valorSenha);

            resultado = cntrAutServ->autenticar(email, senha);
            return resultado;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (++i == MAX_TENTATIVAS)
            {
                //cout << "Quantidade de tentativas excedida." << endl;

                char timeOut[] = "Quantidade de tentativas excedida.";
                int linha, coluna;

                initscr();                                                                      // Inicia curses.
                getmaxyx(stdscr,linha,coluna);                                                  // Armazena quantidade de linhas e de colunas.
                mvprintw(linha/2,(coluna-strlen(timeOut))/2,"%s",timeOut);
                noecho();                                                                       // Desabilita eco.
                getch();                                                                        // L� caracter digitado.
                echo();                                                                         // Habilita eco.
                endwin();

                return false;
            }
        }
    }
}
