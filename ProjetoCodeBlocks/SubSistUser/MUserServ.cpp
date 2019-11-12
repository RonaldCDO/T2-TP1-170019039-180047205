#include "MUserServ.hpp"
#include "containers.hpp"

using namespace std;


bool CntrUserServ::cadastrarUsuario (Usuario * usuario) throw(runtime_error)
{
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();
/*
    if (userRepo->obterUsuario(usuario->getEmail())->getEmail().getValor() == usuario->getEmail().getValor())
    {
        return false;
    }
*/
    userRepo->inserir(*usuario);

    return true;
}


void CntrUserServ::cadastrarConta (Conta * conta) throw(runtime_error)
{
    ContainerContas * contaRepo;
    contaRepo = ContainerContas::instanciar();

    contaRepo->inserir(*conta);

    return;
}

bool CntrUserServ::verificarUsuario(Email email, Usuario * usuario) throw(runtime_error)
{
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    if(userRepo->obterUsuario(email, usuario))
       {
           return true;
       }
    else
        {
            return false;
        }
}

void CntrUserServ::listarReservas(Email email, Carona * carona, CodigoDeCarona * codigoDeCarona,
                                  Usuario * usuario, Reserva * reserva) throw(runtime_error)
{
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    ContainerReservas * reserveRepo;
    reserveRepo = ContainerReservas::instanciar();

    if (CntrUserServ::verificarUsuario(email, usuario) == true &&
       (carona->getCodigoDeCarona().getValor() == rideRepo->buscarCarona(codigoDeCarona)))
    {
        reserveRepo->obterReservas(reserva->getCodigoDeReserva().getValor());
    }


}
*/

bool CntrUserServ::excluir (Email email) throw(runtime_error)
{
    return true;
}
