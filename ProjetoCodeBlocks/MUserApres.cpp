#include "MUserApres.hpp"

using namespace std;


bool CntrUserApres::obterDadosUsuario(Usuario * usuario)
{
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    string valor;
    int qtdTentativas = 0;

    cout << endl << "Informacoes para Cadastro de Usuario." << endl << endl;

    // Obtenção do Nome do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            cout << "Nome: ";
            cin >> valor;
            nome.setValor(valor);

            usuario->setNome(nome);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;
    
    // Obtenção do Telefone do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {    
        try
        {
            cout << "Telefone: ";
            cin >> valor;
            telefone.setValor(valor);

            usuario->setTelefone(telefone);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;
    
    // Obtenção do Email do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            cout << "Email: ";
            cin >> valor;
            email.setValor(valor);

            usuario->setEmail(email);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;
    
    // Obtenção da Senha do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            cout << "Senha: ";
            cin >> valor;
            senha.setValor(valor);

            usuario->setSenha(senha);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;
    
    // Obtenção do CPF do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            cout << "CPF: ";
            cin >> valor;
            cpf.setValor(valor);

            usuario->setCPF(cpf);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    return true;
}



bool CntrUserApres::obterContaCorrente(Conta * conta)
{   
    conta = new Conta();

    CodigoDeBanco codigoDeBanco;
    NumeroDeAgencia numeroDeAgencia;
    NumeroDeConta numeroDeConta;

    string valor;
    int qtdTentativas = 0;

    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            cout << "Codigo de Banco: ";
            cin >> valor;
            codigoDeBanco.setValor(valor);

            conta->setCodigoDeBanco(codigoDeBanco);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;


    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            cout << "Numero de Agencia: ";
            cin >> valor;
            numeroDeAgencia.setValor(valor);

            conta->setNumeroDeAgencia(numeroDeAgencia);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;


    while(qtdTentativas++ < MAX_TENTATIVAS)
    {      
        try
        {
            cout << "Numero de Conta: ";
            cin >> valor;
            numeroDeConta.setValor(valor);

            conta->setNumeroDeConta(numeroDeConta);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }


    return true;
}

void CntrUserApres::cadastrar() throw(runtime_error)
{
    Usuario * usuario;
    usuario = new Usuario();

    if (!(CntrUserApres::obterDadosUsuario(usuario)))
    {
        return;
    }

    Conta * conta1;

    cout << endl << "Dados de Conta Corrente." << endl << endl;

    if (!(CntrUserApres::obterContaCorrente(conta1)))
    {
        return;
    }

    string segundaConta;
    cout << endl << "Gostaria de cadastrar uma segunda conta?" << endl << "Caso positivo, escreva 'sim'." << endl;

    cin >> segundaConta;

    Conta * conta2;

    if (segundaConta == "sim")
    {
        cout << endl << "Dados da segunda Conta Corrente." << endl << endl;

        if (!(CntrUserApres::obterContaCorrente(conta2)))
        {
            cout << "Não foi possível cadastar a segunda Conta Corrente" << endl;
        }
    }

    bool cadastrado;

    cadastrado = cntrUserServ->cadastrar(usuario, conta1, conta2);

    if (cadastrado)
    {    
        cout << endl << "Usuario cadastrado com sucesso" << endl;
    }

    else
    {
        cout << endl << "Usuario ja existente no banco de dados." << endl;
    }

    return;
}