#include "MAutServ.hpp"
#include "containers.hpp"

using namespace std;


bool CntrAutServ::autenticar(Email * email, Senha senha) throw(runtime_error)
{
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    bool autenticado = userRepo->compararEmailSenha (*email, senha);

    return autenticado;
}
