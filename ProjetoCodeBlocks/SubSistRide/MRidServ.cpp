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


int CntrRidServ::descadastrarCarona (Email * email, CodigoDeCarona * codigo) throw(runtime_error)
{
    const int CARONA_DESCADASTRADA = 0;
    const int NAO_CADASTRADOR = 1;
    const int POSSUI_RESERVAS = 2;


    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    Carona * carona = new Carona();

    carona = rideRepo->buscarCarona(codigo);

    if (carona->getProvedorDaCarona()->getEmail().getValor() != email->getValor())
    {
        return NAO_CADASTRADOR;
    }

    ContainerReservas * reservaRepo;
    reservaRepo = ContainerReservas::instanciar();

    vector<Reserva> reservasAssociadas;

    reservasAssociadas = reservaRepo->listarReservasDeCarona(codigo);

    if (reservasAssociadas.size() != 0)
    {
        return POSSUI_RESERVAS;
    }

    rideRepo->excluir(*codigo);

    return CARONA_DESCADASTRADA;
}


bool CntrRidServ::efetuarReserva (CodigoDeCarona * rideCode, Assento * seat, Bagagem * bag, CodigoDeReserva * reservaCode, vector<Conta> * vetorDeContas, Email * email) throw(runtime_error)
{
        //Obtenção da carona solicitada
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    Carona * caronaSolicitada;
    caronaSolicitada = new Carona();

    caronaSolicitada = rideRepo->buscarCarona(rideCode);

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

    Conta * conta1;
    conta1 = new Conta();

    Conta * conta2 = 0;
    conta2 = new Conta();

    bool DuasContas = contaRepo->obterConta(*(caronaSolicitada->getProvedorDaCarona()), conta1, conta2);
    
    vetorDeContas->push_back(*conta1);

    if (DuasContas)
    {
        vetorDeContas->push_back(*conta2);
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



vector<Carona> CntrRidServ::pesquisarCaronas(Carona * dominiosSolicitados)
{
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    vector<Carona> caronasCompativeis;

    caronasCompativeis = rideRepo->pesquisarCaronas(dominiosSolicitados);

    return caronasCompativeis;
}


bool CntrRidServ::listarReservas(Email * email, CodigoDeCarona * rideCode, vector<Reserva> * vetorDeReservas)
{
    ContainerCaronas * rideRepo;
    rideRepo = ContainerCaronas::instanciar();

    Carona * caronaSolicitada;
    caronaSolicitada = new Carona();

    caronaSolicitada = rideRepo->buscarCarona(rideCode);

    if (!(caronaSolicitada->getProvedorDaCarona()->getEmail().getValor() == email->getValor()))
    {
        return false;
    }

    ContainerReservas * reservaRepo;
    reservaRepo = ContainerReservas::instanciar();

    *vetorDeReservas = reservaRepo->listarReservasDeCarona(rideCode);

    cout << to_string(vetorDeReservas->size()) << endl;

    return true;
}


bool CntrRidServ::cancelarReserva(CodigoDeReserva * reservaCode)
{
    ContainerReservas * reservaRepo;
    reservaRepo = ContainerReservas::instanciar();

    CodigoDeCarona * rideCode;
    rideCode = new CodigoDeCarona();

    bool reservaCancelada = reservaRepo->excluirReserva(reservaCode, rideCode);

    if (reservaCancelada)
    {
        ContainerCaronas * rideRepo;
        rideRepo = ContainerCaronas::instanciar();

        Carona * carona = new Carona();

        carona = rideRepo->buscarCarona(rideCode);

        int qtdVagas = (int)(carona->getVagas().getValor()[0] - '0');
        qtdVagas += 1;
        string vagas_str = to_string(qtdVagas);
        carona->getVagas().setValor(vagas_str);
    }

    return reservaCancelada;
}
