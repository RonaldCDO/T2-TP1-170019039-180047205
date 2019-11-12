#include "MUserApres.hpp"

using namespace std;


bool TelaDadosUsuario::run(Usuario * usuario)
{
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    int qtdTentativas = 0;

    char userInfo[] = "Informacoes para Cadastro de Usuario.";
    char novaEntrada[] = "Aperte ENTER e preencha o dado novamente.";
    char tentativaExcedida[] = "Quantidade maxima de tentativas excedida.";
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(userInfo))/2,"%s",userInfo);
    noecho();
    getch();                                                                        
    echo(); 
    clear();

    // Obtenção do Nome do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Nome: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();

            nome.setValor(valor);
            usuario->setNome(nome);
            
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
    
    // Obtenção do Telefone do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            char dominio[] = "Telefone: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();

            telefone.setValor(valor);
            usuario->setTelefone(telefone);

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
    
    // Obtenção do Email do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            char dominio[] = "E-mail: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();

            email.setValor(valor);
            usuario->setEmail(email);

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
    
    // Obtenção da Senha do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            char dominio[] = "Senha: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();            

            senha.setValor(valor);
            usuario->setSenha(senha);
            
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
    
    // Obtenção do CPF do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            char dominio[] = "CPF: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();            

            cpf.setValor(valor);
            usuario->setCPF(cpf);
            
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

    clear();
    echo();
    endwin();

    return true;
}



bool TelaDadosConta::run(Conta * conta)
{  
    CodigoDeBanco codigoDeBanco;
    NumeroDeAgencia numeroDeAgencia;
    NumeroDeConta numeroDeConta;

    int qtdTentativas = 0;

    char contaInfo[] = "Informacao dos dados de Conta Corrente.";
    char novaEntrada[] = "Aperte ENTER e preencha o dado novamente.";
    char tentativaExcedida[] = "Quantidade maxima de tentativas excedida.";
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(contaInfo))/2,"%s",contaInfo);
    noecho();
    getch();                                                                        
    echo(); 
    clear();

    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            /*
            cout << "Codigo de Banco: ";
            cin >> valor;
            codigoDeBanco.setValor(valor);

            conta->setCodigoDeBanco(codigoDeBanco);
            break;
            */

            char dominio[] = "Codigo de Banco: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();            

            codigoDeBanco.setValor(valor);
            conta->setCodigoDeBanco(codigoDeBanco);
            
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


    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            /*
            cout << "Numero de Agencia: ";
            cin >> valor;
            numeroDeAgencia.setValor(valor);

            conta->setNumeroDeAgencia(numeroDeAgencia);
            break;

            */

            char dominio[] = "Numero de Agencia: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();            

            numeroDeAgencia.setValor(valor);
            conta->setNumeroDeAgencia(numeroDeAgencia);
            
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


    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            /*
            cout << "Numero de Conta: ";
            cin >> valor;
            numeroDeConta.setValor(valor);

            conta->setNumeroDeConta(numeroDeConta);
            break;
            */

            char dominio[] = "Numero de Conta: ";
            mvprintw(linha/2,(coluna-strlen(dominio))/2,"%s",dominio);

            char valor[50];
            getstr(valor);

            clear();
            noecho();
            echo();            

            numeroDeConta.setValor(valor);
            conta->setNumeroDeConta(numeroDeConta);
            
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

    clear();
    endwin();

    return true;
}



bool TelaDadosConta::novaConta(Conta * conta)
{
    char segConta1[] = "Gostaria de cadastrar uma segunda conta?";
    char segConta2[] = "Caso positivo, digite 1; caso negativo, digite 2: ";
    char resposta[] = "2";
    int linha,coluna;

    initscr();
    getmaxyx(stdscr,linha,coluna);
    mvprintw(linha/2,(coluna-strlen(segConta1))/2,"%s",segConta1);
    mvprintw(linha/2 + 2,(coluna-strlen(segConta2))/2,"%s",segConta2);
    getstr(resposta); 
    clear();


    if (resposta[0] == '1')
    {   
        TelaDadosConta tela;
        
        if (tela.run(conta))
        {
            return true;
        }
    }

    return false;
}



void CntrUserApres::cadastrar() throw(runtime_error)
{
    // Obtenção dos dados do usuário.
    Usuario * usuario;
    usuario = new Usuario();

    TelaDadosUsuario telaUser;

    if (!(telaUser.run(usuario)))
    {
        return;
    }


    // Dados da conta corrente principal
    Conta * conta1;
    conta1 = new Conta();

    TelaDadosConta telaConta;

    if (telaConta.run(conta1))
    {
        conta1->setDonoDaConta(usuario);
    }

    else
    {
        delete conta1;
        return;
    }


    // Verificação de resultados e exposição na tela.
    int linha, coluna;
    initscr();                                                                      
    getmaxyx(stdscr,linha,coluna);

    bool userCadastrado, contaCadastrada;

    userCadastrado = cntrUserServ->cadastrarUsuario(usuario);

    if (!userCadastrado)
    {
        char result[] = "Usuario ja existente no banco de dados.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);

        noecho();                                                                       
        getch();                                                                        
        echo(); 
        clear();
        endwin();

        return;
    }

    cntrUserServ->cadastrarConta(conta1);

    //Verificação da segunda conta corrente.
    Conta * conta2;
    conta2 = new Conta();

    bool contaSecundariaObtida = false;

    if (telaConta.novaConta(conta2))
    {
        conta2->setDonoDaConta(usuario);
        contaSecundariaObtida = true;
    }

    else
    {
        delete conta2;
    }

    if (contaSecundariaObtida)
    {
        cntrUserServ->cadastrarConta(conta2);
    }

    if (userCadastrado) 
    {
        char result[] = "Usuario cadastrado com sucesso!";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

    noecho();                                                                       
    getch();                                                                        
    echo(); 
    clear();
    endwin();


    return;
}



void CntrUserApres::excluir(Email * email) throw(runtime_error)
{
    bool userExcluido;

    userExcluido = cntrUserServ->excluir(*email);

    int linha, coluna;
    initscr();
    getmaxyx(stdscr,linha,coluna);

    if (userExcluido)
    {
        char result[] = "Usuario excluido do sistema.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
    }

    else
    {
        char result[] = "Usuario nao pode ser excluido.";
        char result2[] = "Existem reservas e/ou caronas associadas a sua conta.";
        mvprintw(linha/2,(coluna-strlen(result))/2,"%s",result);
        mvprintw(linha/2 + 2,(coluna-strlen(result2))/2,"%s",result2);
    }

    getch();
    clear();
    endwin();

    return;
}
