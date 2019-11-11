#include "MRidServ.hpp"
#include "containers.hpp"

using namespace std;


bool CntrRidServ::cadastrarCarona (Carona * carona, Email * email) throw(runtime_error)
{
    ContainerCaronas * caronaRepo;
    caronaRepo = ContainerCaronas::instanciar();

    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    Usuario * cadastrador;
    cadastrador = new Usuario();

    userRepo->obterUsuario(*email, cadastrador);

    bool caronaCadastrada; 

    caronaCadastrada = caronaRepo->verificarConflitoDeData(cadastrador, carona);

    return caronaCadastrada;
}


bool CntrRidServ::descadastrarCarona (CodigoDeCarona codigo) throw(runtime_error)
{
    return true;
}


bool CntrRidServ::efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, Conta * prestador) throw(runtime_error)
{
    return true;
}