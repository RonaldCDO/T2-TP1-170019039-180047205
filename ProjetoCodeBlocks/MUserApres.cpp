#include "MUserApres.hpp"

using namespace std;

/*
int CntrUserApres::obterDadoUsuario(Usuario * usuario, Dominio * dominio, string classeDominio)
{
    string valor;
    int i = 0;

    while(true)
    {    
        try
        {
            cout << classeDominio << ": ";
            cin >> valor;
            dominio->setValor(valor);

            usuario->setNome(*dominio);
            break;
        }
        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;
            cout << "Preencha o dado novamente." << endl;
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << "Numero maxima de tentativas excedida. Nao foi possivel cadastrar o usuario." << endl;
                break;
            }
        }
    }

    return i;
}
*/

bool CntrUserApres::obterContaCorrente(Conta * conta)
{   
    conta = new Conta();

    CodigoDeBanco codigoDeBanco;
    NumeroDeAgencia numeroDeAgencia;
    NumeroDeConta numeroDeConta;

    string valor;
    int i = 0;

    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel atrelar conta ao usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return false;
    }

    i = 0;

    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel atrelar conta ao usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return false;
    }

    i = 0;

    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel atrelar conta ao usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return false;
    }

    i = 0;

    return true;
}

void CntrUserApres::cadastrar() throw(runtime_error)
{

/*
    Usuario * usuario;
    usuario = new Usuario();

    Nome * nome;
    nome = new Nome();
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    int i;

    i = CntrUserApres::obterDadoUsuario(usuario, nome, "Nome");
    if (i == MAX_TENTATIVAS)
    {
        return;
    }

    cout << usuario->getNome().getValor() << endl;
*/


    Usuario * usuario;
    usuario = new Usuario();

    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    string valor;
    int i = 0;

    cout << endl << "Informacoes para Cadastro de Usuario." << endl << endl;

    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel cadastrar o usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return;
    }

    i = 0;
    
    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel cadastrar o usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return;
    }

    i = 0;

    while(true)
    {    
        try
        {
            cout << "E-mail: ";
            cin >> valor;
            email.setValor(valor);

            usuario->setEmail(email);
            break;
        }
        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel cadastrar o usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return;
    }

    i = 0;

    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel cadastrar o usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return;
    }

    i = 0;

    while(true)
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
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << endl << "Numero maxima de tentativas excedida. Nao foi possivel cadastrar o usuario." << endl;
                break;
            }

            else
            {
                cout << "Preencha o dado novamente." << endl;
            }
            
        }
    }

    if (i == MAX_TENTATIVAS)
    {
        return;
    }


/*
    valor = usuario->getNome().getValor();
    cout << valor << endl;
    
    valor = usuario->getTelefone().getValor();
    cout << valor << endl;

    valor = usuario->getEmail().getValor();
    cout << valor << endl;

    valor = usuario->getSenha().getValor();
    cout << valor << endl;

    valor = usuario->getCPF().getValor();
    cout << valor << endl;
*/

    cout << endl << "Dados de Conta Corrente." << endl << endl;

    Conta * conta1;
    Conta * conta2;
    bool cadastroConta;

    cadastroConta = CntrUserApres::obterContaCorrente(conta1);

    if(!cadastroConta)
    {
        return;
    }

    cout << endl << "Gostaria de cadastrar uma segunda conta? (Digite 's' para responder 'sim'). ";
    cin >> valor; 

    if (valor == "s")
    {
        cout << endl << "Dados da Segunda Conta Corrente." << endl << endl;

        cadastroConta = CntrUserApres::obterContaCorrente(conta2);

        if(!cadastroConta)
        {
            return;
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