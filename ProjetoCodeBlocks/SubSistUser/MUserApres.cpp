#include "MUserApres.hpp"

using namespace std;


bool TelaDadosUsuario::run(Usuario * usuario)
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



bool TelaDadosConta::run(Conta * conta)
{  
    CodigoDeBanco codigoDeBanco;
    NumeroDeAgencia numeroDeAgencia;
    NumeroDeConta numeroDeConta;

    string valor;
    int qtdTentativas = 0;

    cout << endl << "Dados de Conta Corrente." << endl << endl;

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



bool TelaDadosConta::novaConta(Conta * conta)
{
    string segundaConta;
    cout << endl << "Gostaria de cadastrar uma segunda conta?" << endl << "Caso positivo, escreva 'sim'." << endl;
    cin >> segundaConta;

    if (segundaConta == "sim")
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
    // Dados do usuário.
    Usuario * usuario;
    usuario = new Usuario();

    TelaDadosUsuario telaUser;

    if (!(telaUser.run(usuario)))
    {
        return;
    }

    // Dados da conta corrente
    Conta * conta1;
    conta1 = new Conta();

    TelaDadosConta telaConta;

    if (!(telaConta.run(conta1)))
    {
        return;
    }

    //Verificação da segunda conta corrente.
    Conta * conta2;
    conta2 = new Conta();

    if (!telaConta.novaConta(conta2))
    {
        delete conta2;
        conta2 = NULL;
    }

    // Após validar os valores.
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


/*
void CntrUserApres::excluir(Email * email) throw(runtime_error)
{
    
}
*/