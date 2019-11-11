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


bool ContainerUsuarios::obterUsuario (Email email, Usuario * usuario)
{
    for (vector<Usuario>::iterator user = repositorioUsuarios.begin(); user != repositorioUsuarios.end(); user++)
    {
        if (user->getEmail().getValor() == email.getValor())
        {
            *usuario = *user;
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


bool ContainerContas::obterConta (Usuario usuario, Conta * conta1, Conta * conta2)
{
    bool contaEncontrada = false;

    for (vector<Conta>::iterator conta = repositorioContas.begin(); conta != repositorioContas.end(); conta++)
    {
        if (conta->getDonoDaConta()->getEmail().getValor() == usuario.getEmail().getValor())
        {
            if (!contaEncontrada)
            {
                *conta1 = *conta;
                contaEncontrada = true;
            }
            else
            {
                *conta2 = *conta;
            }
        }
    }
    if (contaEncontrada)
    {
        return true;
    }

    return false;
}



bool ContainerCaronas::RepositorioCriado = false;
ContainerCaronas * ContainerCaronas::refContCarona = 0;


ContainerCaronas * ContainerCaronas::instanciar()
{
    if (!RepositorioCriado)
    {
        refContCarona = new ContainerCaronas();
        RepositorioCriado = true;
    }

    return refContCarona;
}


void ContainerCaronas::inserir (Carona carona)
{
    repositorioCaronas.push_back(carona);
}


bool ContainerCaronas::verificarConflitoDeData (Usuario * usuario, Carona * carona)
{
    for (vector<Carona>::iterator ride = repositorioCaronas.begin(); ride != repositorioCaronas.end(); ride++)
    {
        if (ride->getProvedorDaCarona()->getEmail().getValor() == usuario->getEmail().getValor())
        {
            if ((ride->getDuracao().getValor() == carona->getDuracao().getValor()) && (ride->getData().getValor() == carona->getData().getValor()))
            {
                return false;
            }
        }
    }
    return true;
}


Carona ContainerCaronas::buscarCarona (CodigoDeCarona * rideCode)
{
    for (vector<Carona>::iterator ride = repositorioCaronas.begin(); ride != repositorioCaronas.end(); ride++)
    {
        if (ride->getCodigoDeCarona().getValor() == rideCode->getValor())
        {
            return *ride;
        }
    }
} 



bool ContainerReservas::RepositorioCriado = false;
ContainerReservas * ContainerReservas::refContReserva = 0;
int ContainerReservas::ultimaReservaCriada = 10000;


ContainerReservas * ContainerReservas::instanciar()
{
    if (!RepositorioCriado)
    {
        refContReserva = new ContainerReservas();
        RepositorioCriado = true;
    }

    return refContReserva;
}


void ContainerReservas::inserir(Reserva reserva)
{
    repositorioReservas.push_back(reserva);
}