#include "stubs.hpp"

using namespace std;


bool StubCntrAutServ::autenticar(Email * email, Senha senha) throw(runtime_error)
{
    string valorEmail;
    string valorSenha;

    valorEmail = email->getValor();
    valorSenha = senha.getValor();

    cout << "Valor passado de Email: " << valorEmail << endl;
    cout << "Valor passado de Senha: " << valorSenha << endl;

    if (valorSenha == "mat23")
    {
        return false;
    }
    else
    {
        if (valorSenha == "mat10")
        {
            throw runtime_error("Sistema temporariamente indisponivel...");
        }
        else
        {
            return true;
        }
    }
}


bool StubCntrUserServ::cadastrarUsuario(Usuario * usuario) throw(runtime_error)
{
    if (usuario->getNome().getValor() == "Matheus")
    {
        return false;
    }

    if (usuario->getNome().getValor() == "Costa")
    {
        throw runtime_error("Sistema temporariamente indisponivel...");
    }

    return true;
}



bool StubCntrUserServ::cadastrarConta(Conta * conta) throw(runtime_error)
{
    if (conta->getCodigoDeBanco().getValor() == "123")
    {
        return false;
    }

    if (conta->getCodigoDeBanco().getValor() == "456")
    {
        throw runtime_error("Sistema temporariamente indisponivel...");
    }

    return true;
}



bool StubCntrUserServ::excluir(Email email) throw(runtime_error)
{
    // Para o serviço de exclusão, deve-se procurar a entidade usuário com o respectivo e-mail.
    if (email.getValor() == "mat@costa")
    {
        return false;
    }

    if (email.getValor() == "email@exp")
    {
        throw runtime_error("Sistema temporariamente indisponivel...");
    }

    return true;
}


bool StubCntrRidServ::cadastrarCarona(Carona * carona) throw(runtime_error)
{
    if(carona->getCidadeDeDestino().getValor() == "Brasilia")
    {
        return false;
    }

    if (carona->getCidadeDeDestino().getValor() == "Goiania")
    {
        throw runtime_error("Sistema temporariamente indisponivel...");
    }

    return true;
}


bool StubCntrRidServ::descadastrarCarona (CodigoDeCarona codigo) throw(runtime_error)
{
    if (codigo.getValor() == "1234")
    {
        return false;
    }

    if (codigo.getValor() == "9999")
    {
        throw runtime_error("Sistema temporariamente indisponivel...");
    }

    return true;
}