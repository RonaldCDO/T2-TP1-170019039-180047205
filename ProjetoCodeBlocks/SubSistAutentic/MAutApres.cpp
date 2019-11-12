#include "MAutApres.hpp"

#include <curses.h>
#include <string.h>
#include <string>

using namespace std;

bool CntrAutApres::autenticar(Email * email) throw(runtime_error)
{
    Senha senha;

    const int MAX_TENTATIVAS = 3;
    int i = 0;
    bool resultado;

    while (true)
    {
        try
        {
            char campo1[]="Digite seu e-mail cadastrado: ";
            char campo2[]="Digite sua senha            : ";
            char valorEmail[60];
            char valorSenha[10];
            int linha,coluna;

            initscr();                                                                      
            getmaxyx(stdscr,linha,coluna);                                                  
            mvprintw(linha/2,(coluna-strlen(campo1))/2,"%s",campo1);                        
            getstr(valorEmail);                                                                  
            mvprintw(linha/2 + 2,(coluna-strlen(campo2))/2,"%s",campo2);                    
            getstr(valorSenha);                                                                  
                                                                       
            //getch();                                                                         
            clear();
            endwin();

            email->setValor(valorEmail);
            senha.setValor(valorSenha);

            resultado = cntrAutServ->autenticar(email, senha);

            initscr();                                                                      
            getmaxyx(stdscr,linha,coluna);

            if (resultado)
            {
                char autenticado[] = "Autenticacao realizada com sucesso!";
                mvprintw(linha/2,(coluna-strlen(autenticado))/2,"%s",autenticado); 
            }
            else
            {
                char naoAutenticado[] = "Falha na autenticacao.";
                mvprintw(linha/2,(coluna-strlen(naoAutenticado))/2,"%s",naoAutenticado);
            }

            getch();                                                                         
            clear();
            endwin();

            return resultado;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars 
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());

            int linha, coluna;

            initscr();                                                                      
            getmaxyx(stdscr,linha,coluna);                                                  
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);
            noecho();                                                                       
            getch();                                                                        
            echo();  
            clear();                                                                       
            endwin();

            if (++i == MAX_TENTATIVAS)
            {
                char timeOut[] = "Quantidade de tentativas excedida.";
                int linha, coluna;

                initscr();                                                                      // Inicia curses.
                getmaxyx(stdscr,linha,coluna);                                                  // Armazena quantidade de linhas e de colunas.
                mvprintw(linha/2,(coluna-strlen(timeOut))/2,"%s",timeOut);
                clear();
                noecho();                                                                       // Desabilita eco.
                getch();                                                                        // L� caracter digitado.
                echo();                                                                         // Habilita eco.
                endwin();

                return false;
            }
        }
    }
}
