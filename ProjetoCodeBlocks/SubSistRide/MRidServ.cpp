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

    carona->setProvedorDaCarona(cadastrador);

    bool caronaCadastrada;

    caronaCadastrada = caronaRepo->verificarConflitoDeData(cadastrador, carona);

    if (caronaCadastrada)
    {
        caronaRepo->inserir(*carona);
    }

    return caronaCadastrada;
}


bool CntrRidServ::descadastrarCarona (CodigoDeCarona codigo) throw(runtime_error)
{
    return true;
}


bool CntrRidServ::efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, Conta * conta1, Conta * conta2, Email * email) throw(runtime_error)
{
        //Obtenção da carona solicitada
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    Carona * caronaSolicitada;
    caronaSolicitada = new Carona();

    *caronaSolicitada = rideRepo->buscarCarona(rideCode);

        //Verificação a respeito das vagas e alteração do valor
    if (caronaSolicitada->getVagas().getValor() == "0")
    {
        return false;
    }

    int qtdVagas = (int)(caronaSolicitada->getVagas().getValor()[0] - '0');
    qtdVagas -= 1;
    string vagas_str = to_string(qtdVagas);

    Vagas vagas;

    try
    {
        vagas.setValor(vagas_str);
    }
    catch(const invalid_argument& exp)
    {
        cout << exp.what() << endl;
    }

    caronaSolicitada->setVagas(vagas);

        //Obtenção do usuário que solicita a reserva
    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    Usuario * cliente;
    cliente = new Usuario();

    userRepo->obterUsuario(*email, cliente);

        //Obtenção das contas do responsável pela carona.
    ContainerContas * contaRepo;
    contaRepo = ContainerContas::instanciar();

    bool DuasContas = contaRepo->obterConta(*(caronaSolicitada->getProvedorDaCarona()), conta1, conta2);
    if (!DuasContas)
    {
        conta2 = 0;
    }

        //Criação e alocação da reserva;
    ContainerReservas * reservaRepo;
    reservaRepo = ContainerReservas::instanciar();

    int reservaValor = reservaRepo->ultimaReservaCriada++;
    string reservaValor_str = to_string(reservaValor);
    reservaCode->setValor(reservaValor_str);

    Reserva reserva;

    reserva.setCodigoDeReserva(*reservaCode);
    reserva.setAssento(*seat);
    reserva.setBagagem(*bag);
    reserva.setCliente(cliente);
    reserva.setCaronaAssociada(caronaSolicitada);


    reservaRepo->inserir(reserva);

    return true;
}


void CntrRidServ::listarReservas(Email email, Carona * carona, CodigoDeCarona * codigoDeCarona,
                                  Usuario * usuario, Reserva * reserva) throw(runtime_error)
{
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    ContainerUsuarios * userRepo;
    userRepo = ContainerUsuarios::instanciar();

    ContainerReservas * reserveRepo;
    reserveRepo = ContainerReservas::instanciar();

    /*if (CntrUserServ::verificarUsuario(email, usuario) == true &&
       (carona->getCodigoDeCarona().getValor() == rideRepo->buscarCarona(codigoDeCarona)))
    {
        reserveRepo->obterReservas(reserva->getCodigoDeReserva().getValor());
    }
    */

}
