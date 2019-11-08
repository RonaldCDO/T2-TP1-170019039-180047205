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


bool StubCntrUserServ::cadastrar(Usuario * usuario, Conta * conta1, Conta * conta2) throw(runtime_error)
{
    if (usuario->getNome().getValor() == "Matheus")
    {
        return false;
    }

    if (usuario->getNome().getValor() == "Costa")
    {
        throw runtime_error("Sistema temporariamente indisponivel...");
    }

    else
    {
        return true;
    }
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
