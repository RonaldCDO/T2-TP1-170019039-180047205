#include "containers.hpp"

using namespace std;


bool ContainerUsuarios::RepositorioCriado = false;
ContainerUsuarios * ContainerUsuarios::refContUser = 0;

ContainerUsuarios * ContainerUsuarios::instanciar()
{
    if (!RepositorioCriado)
    {
        refContUser = new ContainerUsuarios();
        RepositorioCriado = true;
    }

    return refContUser;
}


void ContainerUsuarios::inserir (Usuario usuario)
{
    repositorioUsuarios.push_back(usuario);
}


bool ContainerUsuarios::obterUsuario (Email email)
{
    for (vector<Usuario>::iterator user = repositorioUsuarios.begin(); user != repositorioUsuarios.end(); user++)
    {
        if (user->getEmail().getValor() == email.getValor())
        {
            return true;
        }
    }

    return false;
}


bool ContainerUsuarios::compararEmailSenha (Email email, Senha senha)
{
    for (vector<Usuario>::iterator user = repositorioUsuarios.begin(); user != repositorioUsuarios.end(); user++)
    {
        if ((user->getEmail().getValor() == email.getValor()) && (user->getSenha().getValor() == senha.getValor()))
        {
            return true;
        }
    }
    return false;
}

bool ContainerContas::RepositorioCriado = false;
ContainerContas * ContainerContas::refContConta = 0;


ContainerContas * ContainerContas::instanciar()
{
    if (!RepositorioCriado)
    {
        refContConta = new ContainerContas();
        RepositorioCriado = true;
    }

    return refContConta;
}


void ContainerContas::inserir (Conta conta)
{
    repositorioContas.push_back(conta);
}

/*
void ContainerContas::obterConta (Conta conta)
{
    for (vector<Usuario>::iterator user = repositorioUsuarios.begin(); user != repositorioUsuarios.end(); user++)
    {
        if (user->getEmail().getValor() == email.getValor())
        {
            return true;
        }
    }

    return false;
}
*/