#include "MRidServ.hpp"
#include "containers.hpp"

using namespace std;


bool CntrRidServ::cadastrarCarona (Carona * carona) throw(runtime_error)
{
    ContainerCaronas * caronaRepo;
    caronaRepo = ContainerCaronas::instanciar();

    caronaRepo->inserir(*carona);
}