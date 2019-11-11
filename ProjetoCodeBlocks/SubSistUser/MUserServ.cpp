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


bool CntrUserServ::excluir (Email email) throw(runtime_error)
{
    return true;
}