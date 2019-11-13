#include "MRidApres.hpp"

using namespace std;


bool TelaDadosCarona::run(Carona * carona)
{
    CodigoDeCarona codigoDeCarona;
    Cidade cidadeDeOrigem;
    Estado estadoDeOrigem;
    Cidade cidadeDeDestino;
    Estado estadoDeDestino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;

    string valor;
    int qtdTentativas = 0;

    char rideInfo[] = "Informacoes para Cadastro de Carona.";
    char novaEntrada[] = "Aperte ENTER e preencha o dado novamente.";
    char tentativaExcedida[] = "Quantidade maxima de tentativas excedida.";
    int linha,coluna;   

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(rideInfo))/2,"%s",rideInfo);
    noecho();
    getch();                                                                        
    echo(); 
    clear();

    // Obtenção do Código de Carona
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Codigo de Carona: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();            

            codigoDeCarona.setValor(valor);
            carona->setCodigoDeCarona(codigoDeCarona);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da Cidade de Origem
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Cidade de Origem: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            cidadeDeOrigem.setValor(valor);

            carona->setCidadeDeOrigem(cidadeDeOrigem);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do Estado de Origem
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Estado de Origem: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            estadoDeOrigem.setValor(valor);

            carona->setEstadoDeOrigem(estadoDeOrigem);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da Cidade de Destino
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Cidade de Destino: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            cidadeDeDestino.setValor(valor);

            carona->setCidadeDeDestino(cidadeDeDestino);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do Estado de Destino
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Estado de Destino: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            estadoDeDestino.setValor(valor);

            carona->setEstadoDeDestino(estadoDeDestino);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da Data de Partida
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Data de Partida: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            data.setValor(valor);

            carona->setData(data);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da Duracao
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Duracao da viagem em horas: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            duracao.setValor(valor);

            carona->setDuracao(duracao);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da quantidade de Vagas
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Quantidade de vagas: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            vagas.setValor(valor);

            carona->setVagas(vagas);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do preço
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            char dominio[] = "Preco: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo(); 
            
            preco.setValor(valor);

            carona->setPreco(preco);
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }


    return true;
}


bool TelaDadosReserva::run(CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag)
{
    int qtdTentativas = 0;

    char reservaInfo[] = "Dados para solicitacao de reserva em carona.";
    char novaEntrada[] = "Aperte ENTER e preencha o dado novamente.";
    char tentativaExcedida[] = "Quantidade maxima de tentativas excedida.";
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(reservaInfo))/2,"%s",reservaInfo);
    getch();                                                                        
    clear();

    // Obtenção da carona solicitada
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Digite o Codigo de Carona da carona desejada: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            rideCode->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do assento de preferência
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Preferencia de assento (D out T): ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            seat->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da quantidade de bagagens
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Numero de volumes da bagagem: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            bag->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    return true;
}


bool TelaPesquisaCarona::solicitarDados(Cidade * cityOrigem, Estado * stateOrigem, Cidade * cityDestino, Estado * stateDestino, Data * partida)
{
    int qtdTentativas = 0;

    char pesquisaCaronaInfo[] = "Dados para pesquisar caronas disponiveis.";
    char novaEntrada[] = "Aperte ENTER e preencha o dado novamente.";
    char tentativaExcedida[] = "Quantidade maxima de tentativas excedida.";
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(pesquisaCaronaInfo))/2,"%s",pesquisaCaronaInfo);
    getch();                                                                        
    clear();

    // Obtenção da cidade de origem
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Digite a cidade de origem: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            cityOrigem->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do estado de origem
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Digite o Estado de origem: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            stateOrigem->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da cidade de destino
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Digite a cidade de destino: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            cityDestino->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do estado de destino
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Digite o Estado de destino: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            stateDestino->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da data
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Digite a data da partida desejada: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[10];
            getstr(valor);

            clear();
            noecho();
            echo();

            partida->setValor(valor);
            
            break;
        }

        catch(const invalid_argument& exp)
        {
            //Bloco para transformar uma 'string' em uma array de chars
            string erro = exp.what();
            char expArg[erro.length() + 1];
            strcpy(expArg, erro.c_str());
                                                                     
            getmaxyx(stdscr,linha,coluna);                                                 
            mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                mvprintw(linha/2 + 2,(coluna-strlen(novaEntrada))/2,"%s",novaEntrada);
                noecho();                                                                       
                getch();                                                                        
                echo();  
                clear();
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        mvprintw(linha/2 + 2,(coluna-strlen(tentativaExcedida))/2,"%s",tentativaExcedida);
        noecho();                                                                       
        getch();                                                                        
        echo();  
        clear();
        endwin();
        return false;
    }

    return true;
}


void TelaPesquisaCarona::exibirCaronasObtidas(vector<Carona> CaronasObtidas)
{
    char semCaronas[] = "Nao foi obtida nenhuma carona com essas especificacoes...";

    int linha,coluna;   
    initscr();
    getmaxyx(stdscr,linha,coluna);

    if (CaronasObtidas.size() == 0)
    {
        mvprintw(linha/2,(coluna-strlen(semCaronas))/2,"%s",semCaronas);
        getch();                                                                        
        clear();
        endwin();

        return;
    }

    for (vector<Carona>::iterator ride = CaronasObtidas.begin(); ride != CaronasObtidas.end(); ride++)
    {
        string codigoDeCarona_str = "Codigo de Carona: " + ride->getCodigoDeCarona().getValor() + ".";
        string nomeMotorista_str = "Nome do motorista: " + ride->getProvedorDaCarona()->getNome().getValor() + ".";
        string telefoneMotorista_str = "Telefone do motorista: " + ride->getProvedorDaCarona()->getTelefone().getValor() + ".";
        string emailMotorista_str = "E-mail do motorista: " + ride->getProvedorDaCarona()->getEmail().getValor() + ".";
        string data_str = "Data de partida: " + ride->getData().getValor() + ".";
        string duracao_str = "Duracao do trajeto: " + ride->getDuracao().getValor() + ".";
        string vagas_str = "Vagas disponíveis: " + ride->getVagas().getValor() + ".";
        string preco_str = "Preco: R$" + ride->getPreco().getValor() + ".";

        char codigoDeCarona[codigoDeCarona_str.length() + 1];
        char nomeMotorista[nomeMotorista_str.length() + 1];
        char telefoneMotorista[telefoneMotorista_str.length() + 1];
        char emailMotorista[emailMotorista_str.length() + 1];
        char data[data_str.length() + 1];
        char duracao[duracao_str.length() + 1];
        char vagas[vagas_str.length() + 1];
        char preco[preco_str.length() + 1];

        strcpy(codigoDeCarona, codigoDeCarona_str.c_str());
        strcpy(nomeMotorista, nomeMotorista_str.c_str());
        strcpy(telefoneMotorista, telefoneMotorista_str.c_str());
        strcpy(emailMotorista, emailMotorista_str.c_str());
        strcpy(data, data_str.c_str());
        strcpy(duracao, duracao_str.c_str());
        strcpy(vagas, vagas_str.c_str());
        strcpy(preco, preco_str.c_str());

        mvprintw(linha/2,(coluna-strlen(codigoDeCarona))/2,"%s",codigoDeCarona);
        mvprintw(linha/2 + 2,(coluna-strlen(nomeMotorista))/2,"%s",nomeMotorista);
        mvprintw(linha/2 + 4,(coluna-strlen(telefoneMotorista))/2,"%s",telefoneMotorista);
        mvprintw(linha/2 + 6,(coluna-strlen(emailMotorista))/2,"%s",emailMotorista);
        mvprintw(linha/2 + 8,(coluna-strlen(data))/2,"%s",data);
        mvprintw(linha/2 + 10,(coluna-strlen(duracao))/2,"%s",duracao);
        mvprintw(linha/2 + 12,(coluna-strlen(vagas))/2,"%s",vagas);
        mvprintw(linha/2 + 14,(coluna-strlen(preco))/2,"%s",preco);

        getch();                                                                        
        clear();
    }

    endwin();

    return;
}


void TelaDadosReserva::exibirReservasAssociadas(vector<Reserva> ReservasAssociadas)
{
    char semReservas[] = "A carona em questao nao possui nenhuma reserva associada.";

    int linha,coluna;   
    initscr();
    getmaxyx(stdscr,linha,coluna);

    if (ReservasAssociadas.size() == 0)
    {
        mvprintw(linha/2,(coluna-strlen(semReservas))/2,"%s",semReservas);
        getch();                                                                        
        clear();
        endwin();

        return;
    }

    for (vector<Reserva>::iterator reserva = ReservasAssociadas.begin(); reserva != ReservasAssociadas.end(); reserva++)
    {
        string codigoDeReserva_str = "Codigo de Reserva: " + reserva->getCodigoDeReserva().getValor() + ".";
        string nomePassageiro_str = "Nome do passageiro: " + reserva->getCliente()->getNome().getValor() + ".";
        string emailPassageiro_str = "E-mail do passageiro: " + reserva->getCliente()->getEmail().getValor() + ".";
        string assento_str = "Preferencia de assento: " + reserva->getAssento().getValor() + ".";
        string bagagem_str = "Quantidade de bagagens: " + reserva->getBagagem().getValor() + ".";

        char codigoDeReserva[codigoDeReserva_str.length() + 1];
        char nomePassageiro[nomePassageiro_str.length() + 1];
        char emailPassageiro[emailPassageiro_str.length() + 1];
        char assento[assento_str.length() + 1];
        char bagagem[bagagem_str.length() + 1];

        strcpy(codigoDeReserva, codigoDeReserva_str.c_str());
        strcpy(nomePassageiro, nomePassageiro_str.c_str());
        strcpy(emailPassageiro, emailPassageiro_str.c_str());
        strcpy(assento, assento_str.c_str());
        strcpy(bagagem, bagagem_str.c_str());

        mvprintw(linha/2,(coluna-strlen(codigoDeReserva))/2,"%s",codigoDeReserva);
        mvprintw(linha/2 + 2,(coluna-strlen(nomePassageiro))/2,"%s",nomePassageiro);
        mvprintw(linha/2 + 4,(coluna-strlen(emailPassageiro))/2,"%s",emailPassageiro);
        mvprintw(linha/2 + 6,(coluna-strlen(assento))/2,"%s",assento);
        mvprintw(linha/2 + 8,(coluna-strlen(bagagem))/2,"%s",bagagem);

        getch();                                                                        
        clear();
    }

    endwin();

    return;
}


void CntrRidApres::cadastrarCarona(Email * email) throw(runtime_error)
{
    // Obtenção dos dados de Carona.
    Carona * carona;
    carona = new Carona();

    TelaDadosCarona telaRide;

    if (!(telaRide.run(carona)))
    {
        return;
    }

    // Após validar os valores.
    bool cadastrado;

    cadastrado = cntrRidServ->cadastrarCarona(carona, email);

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);

    if (cadastrado)
    {
        char result[] = "Carona cadastrada com sucesso.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

    else
    {
        char result[] = "Carona com conflito de data ja disponibilizada pelo usuario.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

    getch();
    clear();
    endwin();

    return;
}


void CntrRidApres::obterDadosCarona()
{
    Cidade * cidadeOrigem;
    cidadeOrigem = new Cidade();

    Cidade * cidadeDestino;
    cidadeDestino = new Cidade();

    Estado * estadoOrigem;
    estadoOrigem = new Estado();

    Estado * estadoDestino;
    estadoDestino = new Estado();

    Data * data;
    data = new Data();

    TelaPesquisaCarona telaPesquisa;

    if (!telaPesquisa.solicitarDados(cidadeOrigem, estadoOrigem, cidadeDestino, estadoDestino, data))
    {
        return;
    }

    Carona * repositorioDominios;
    repositorioDominios = new Carona();

    repositorioDominios->setCidadeDeOrigem(*cidadeOrigem);
    repositorioDominios->setEstadoDeOrigem(*estadoOrigem);
    repositorioDominios->setCidadeDeDestino(*cidadeDestino);
    repositorioDominios->setEstadoDeDestino(*estadoDestino);
    repositorioDominios->setData(*data);

    vector<Carona> caronasObtidas;

    caronasObtidas = cntrRidServ->pesquisarCaronas(repositorioDominios);

    telaPesquisa.exibirCaronasObtidas(caronasObtidas);

    return;
}


void CntrRidApres::descadastrarCarona(Email * email) throw(runtime_error)
{
    const int CARONA_DESCADASTRADA = 0;
    const int NAO_CADASTRADOR = 1;
    const int POSSUI_RESERVAS = 2;

    char dominio[] = "Digite o codigo de carona da qual se deseja excluir: ";

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

    char valor[10];
    getstr(valor);

    clear();

    CodigoDeCarona * rideCode = new CodigoDeCarona();
    rideCode->setValor(valor);

    int resultado = cntrRidServ->descadastrarCarona(email, rideCode);


    if (resultado == 0)
    {
        char result[] = "Carona descadastrada com sucesso.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }
    if (resultado == 1)
    {
        char result[] = "Apenas o fornecedor da carona pode descadastra-la.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }
    if (resultado == 2)
    {
        char result[] = "Carona possui reservas associadas. Portando, nao pode ser descadastrada.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

/*
    switch(resultado)
    {
        case 1:
            char result[] = "Apenas o fornecedor da carona pode descadastra-la.";
            mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
            break;

        case 2:
            char result[] = "Carona possui reservas associadas. Portando, nao pode ser descadastrada.";
            mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
            break;

        case 0:
            char result[] = "Carona descadastrada com sucesso.";
            mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
            break;

        default:
            break;
    }
*/
    getch();
    clear();
    endwin();

    return;
}


void CntrRidApres::reservarCarona(Email * email) throw(runtime_error)
{
    CodigoDeCarona * rideCode;
    rideCode = new CodigoDeCarona();

    Assento * assentoPref;
    assentoPref = new Assento();

    Bagagem * qtdBagagem;
    qtdBagagem = new Bagagem();
    
    TelaDadosReserva telaReserva;

    if (!(telaReserva.run(rideCode, assentoPref, qtdBagagem)))
    {
        return;
    }

    CodigoDeReserva * reservaCode;
    reservaCode = new CodigoDeReserva();

    vector<Conta> *vetorDeContas = new vector<Conta>;

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);

    if (cntrRidServ->efetuarReserva(rideCode, assentoPref, qtdBagagem, reservaCode, vetorDeContas, email))
    {
        string valorReservaCode = reservaCode->getValor();
        string valorCodigoDeBanco = vetorDeContas->at(0).getCodigoDeBanco().getValor();
        string valorNumeroDeAgencia = vetorDeContas->at(0).getNumeroDeAgencia().getValor();
        string valorNumeroDaConta = vetorDeContas->at(0).getNumeroDeConta().getValor();

        string valorCodigoDeBanco2;
        string valorNumeroDeAgencia2;
        string valorNumeroDaConta2;

        if(vetorDeContas->size() == 2)
        {
            valorCodigoDeBanco2 = vetorDeContas->at(1).getCodigoDeBanco().getValor();
            valorNumeroDeAgencia2 = vetorDeContas->at(1).getNumeroDeAgencia().getValor();
            valorNumeroDaConta2 = vetorDeContas->at(1).getNumeroDeConta().getValor();
        }

        string result1_str = "Reserva efetuada com sucesso!";
        string result2_str = "O codigo da reserva é " + valorReservaCode + ".";
        string pay1_str = "Dados para pagamento: ";
        string pay2_str = "Codigo de Banco: " + valorCodigoDeBanco + ". Nº de Agencia: " 
                        + valorNumeroDeAgencia + ". Nº da Conta: " + valorNumeroDaConta + ".";
        string pay3_str = "Codigo de Banco: " + valorCodigoDeBanco2 + ". Nº de Agencia: " 
                        + valorNumeroDeAgencia2 + ". Nº da Conta: " + valorNumeroDaConta2 + ".";

        char result1[result1_str.length() + 1];
        char result2[result2_str.length() + 1];
        char pay1[pay1_str.length() + 1];
        char pay2[pay2_str.length() + 1];
        char pay3[pay3_str.length() + 1];

        strcpy(result1, result1_str.c_str());
        strcpy(result2, result2_str.c_str());
        strcpy(pay1, pay1_str.c_str());
        strcpy(pay2, pay2_str.c_str());
        strcpy(pay3, pay3_str.c_str());

        mvprintw(linha/2,(coluna-strlen(result1))/2,"%s",result1);
        mvprintw(linha/2 + 2,(coluna-strlen(result2))/2,"%s",result2);

        getch();
        clear();

        mvprintw(linha/2,(coluna-strlen(pay1))/2,"%s",pay1);
        mvprintw(linha/2 + 2,(coluna-strlen(pay2))/2,"%s",pay2);
        if(vetorDeContas->size() == 2)
        {
            mvprintw(linha/2 + 4,(coluna-strlen(pay3))/2,"%s",pay3);
        }

        getch();
        clear();
    }

    else
    {
        char result[] = "Nao ha vagas disponiveis na carona solicitada... Tente outra.";

        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);

        getch();
        clear();
    }

    endwin();
    
    return;
}


void CntrRidApres::listarReservas(Email * email)
{
    CodigoDeCarona * rideCode;
    rideCode = new CodigoDeCarona();

    int linha, coluna;
    char solicitacaoRideCode[] = "Digite o codigo de carona da qual se deseja listar as reservas associadas: ";
    char rideCodeLido[5];

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(solicitacaoRideCode))/2,"%s",solicitacaoRideCode);
    getstr(rideCodeLido);
    clear();

    try
    {
        rideCode->setValor(rideCodeLido);
    }
    catch(const invalid_argument& exp)
    {
        //Bloco para transformar uma 'string' em uma array de chars
        string erro = exp.what();
        char expArg[erro.length() + 1];
        strcpy(expArg, erro.c_str());
                                                                    
        getmaxyx(stdscr,linha,coluna);                                                 
        mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

        char pedidoRecusado[] = "Nao foi possivel pesquisar as reservas.";
        mvprintw(linha/2 + 2,(coluna-strlen(pedidoRecusado))/2,"%s",pedidoRecusado);

        getch();
        clear();
        endwin();

        return;
    }

    vector<Reserva> * reservasAssociadas;
    reservasAssociadas = new vector<Reserva>;

    bool donoDaCarona;
    
    donoDaCarona = cntrRidServ->listarReservas(email, rideCode, reservasAssociadas);

    if (!donoDaCarona)
    {
        char notDono[] = "Apenas o fornecedor da carona pode listar as reservas associadas.";
        mvprintw(linha/2,(coluna-strlen(notDono))/2,"%s",notDono);

        getch();
        clear();
        endwin();

        return;
    }

    TelaDadosReserva telaReservas;
    telaReservas.exibirReservasAssociadas(*reservasAssociadas);

    return;
}


void CntrRidApres::cancelarReserva(Email * email)
{
    CodigoDeReserva * reservaCode;
    reservaCode = new CodigoDeReserva();

    int linha, coluna;
    char pedidoCancelar[] = "Para cancelar a reserva, digite o codigo desta: ";
    char reservaCodeLido[6];

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(pedidoCancelar))/2,"%s",pedidoCancelar);
    getstr(reservaCodeLido);
    clear();

    try
    {
        reservaCode->setValor(reservaCodeLido);
    }
    catch(const invalid_argument& exp)
    {
        //Bloco para transformar uma 'string' em uma array de chars
        string erro = exp.what();
        char expArg[erro.length() + 1];
        strcpy(expArg, erro.c_str());
                                                                    
        getmaxyx(stdscr,linha,coluna);                                                 
        mvprintw(linha/2,(coluna-strlen(expArg))/2,"%s",expArg);

        char pedidoRecusado[] = "Nao foi possivel obter a reserva indicada.";
        mvprintw(linha/2 + 2,(coluna-strlen(pedidoRecusado))/2,"%s",pedidoRecusado);

        getch();
        clear();
        endwin();

        return;
    }

    bool reservaCancelada = cntrRidServ->cancelarReserva(reservaCode);

    if (reservaCancelada)
    {
        char reservaCancelada[] = "Reserva cancelada com sucesso.";
        mvprintw(linha/2,(coluna-strlen(reservaCancelada))/2,"%s",reservaCancelada);
    }

    else
    {
        char falhaCancelamento[] = "A reserva solicitada nao foi encontrada no sistema.";
        mvprintw(linha/2,(coluna-strlen(falhaCancelamento))/2,"%s",falhaCancelamento);
    }

    getch();
    clear();
    endwin();
    
    return;
}