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

    cadastrado = cntrRidServ->cadastrarCarona(carona);

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


void CntrRidApres::descadastrarCarona() throw(runtime_error)
{
    char dominio[] = "Digite o codigo de carona da qual se deseja excluir: ";

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

    char valor[10];
    getstr(valor);

    clear();

    CodigoDeCarona rideCode;
    rideCode.setValor(valor);

    if (cntrRidServ->descadastrarCarona(rideCode))
    {
        char result[] = "Carona descadastrada com sucesso.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

    else
    {
        char result[] = "Carona possui reservas associadas. Portando, nao pode ser descadastrada.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

    getch();
    clear();
    endwin();

    return;
}


void CntrRidApres::reservarCarona() throw(runtime_error)
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

    Conta * prestador;
    prestador = new Conta();

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);

    if (cntrRidServ->efetuarReserva(rideCode, assentoPref, qtdBagagem, reservaCode, prestador))
    {
        string valorReservaCode = reservaCode->getValor();
        string valorCodigoDeBanco = prestador->getCodigoDeBanco().getValor();
        string valorNumeroDeAgencia = prestador->getNumeroDeAgencia().getValor();
        string valorNumeroDaConta = prestador->getNumeroDeConta().getValor();

        string result1_str = "Reserva efetuada com sucesso!";
        string result2_str = "O codigo da reserva é " + valorReservaCode + ".";
        string pay1_str = "Dados para pagamento: ";
        string pay2_str = "Codigo de Banco: " + valorCodigoDeBanco + ". Nº de Agencia: " 
                        + valorNumeroDeAgencia + ". Nº da Conta: " + valorNumeroDaConta + ".";

        char result1[result1_str.length() + 1];
        char result2[result2_str.length() + 1];
        char pay1[pay1_str.length() + 1];
        char pay2[pay2_str.length() + 1];

        strcpy(result1, result1_str.c_str());
        strcpy(result2, result2_str.c_str());
        strcpy(pay1, pay1_str.c_str());
        strcpy(pay2, pay2_str.c_str());

        mvprintw(linha/2,(coluna-strlen(result1))/2,"%s",result1);
        mvprintw(linha/2 + 2,(coluna-strlen(result2))/2,"%s",result2);

        getch();
        clear();

        mvprintw(linha/2,(coluna-strlen(pay1))/2,"%s",pay1);
        mvprintw(linha/2 + 2,(coluna-strlen(pay2))/2,"%s",pay2);

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