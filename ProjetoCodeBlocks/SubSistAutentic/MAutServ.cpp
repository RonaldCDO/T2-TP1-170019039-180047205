#include "MAutServ.hpp"
#include "containers.hpp"

using namespace std;


bool CntrAutServ::autenticar(Email * email, Senha senha)
{
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    Usuario * userAutenticado;
    userAutenticado = new Usuario();

    bool userEncontrado = userRepo->obterUsuario(*email, userAutenticado);

    if (userEncontrado)
    {
        if (userAutenticado->getSenha().getValor() == senha.getValor())
        {
            return true;
        }
    }
    
    return false;
}
