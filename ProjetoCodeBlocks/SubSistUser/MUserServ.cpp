#include "MUserServ.hpp"
#include "containers.hpp"

using namespace std;


bool CntrUserServ::cadastrarUsuario (Usuario * usuario)
{
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    Usuario * userTemporario;

    if (userRepo->obterUsuario(usuario->getEmail(), userTemporario))
    {
        return false;
    }

    userRepo->inserir(*usuario);

    return true;
}


void CntrUserServ::cadastrarConta (Conta * conta)
{
    ContainerContas * contaRepo;
    contaRepo = ContainerContas::instanciar();

    contaRepo->inserir(*conta);

    return;
}


bool CntrUserServ::excluir (Email * email)
{
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    vector<Carona> caronasFornecidas;

    caronasFornecidas = rideRepo->buscarCaronasDoUsuario(email);

    if (caronasFornecidas.size() != 0)
    {
        return false;
    }

    ContainerReservas * reservasRepo;
    reservasRepo = ContainerReservas::instanciar();

    vector<Reserva> reservasRealizadas;

    reservasRealizadas = reservasRepo->buscarReservasDoUsuario(email);

    if (reservasRealizadas.size() != 0)
    {
        return false;
    }

    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    userRepo->excluir(*email);

    return true;
}
