#include "MRidApres.hpp"

using namespace std;


bool TelaDadosCarona::run(Carona * carona)
{
    CodigoDeCarona codigoDeCarona;
    Cidade cidadeDeOrigem;
    Estado estadoDeOrigem;
    Cidade cidadeDeDestino;
    Estado estadoDeDestino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;

    string valor;
    int qtdTentativas = 0;

    cout << endl << "Informacoes para Cadastro de Carona." << endl << endl;

    // Obtenção do Nome do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Codigo de Carona: ";
            cin >> valor;
            codigoDeCarona.setValor(valor);

            carona->setCodigoDeCarona(codigoDeCarona);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do Telefone do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Cidade de Origem: ";
            cin >> valor;
            cidadeDeOrigem.setValor(valor);

            carona->setCidadeDeOrigem(cidadeDeOrigem);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do Email do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Estado de Orogem: ";
            cin >> valor;
            estadoDeOrigem.setValor(valor);

            carona->setEstadoDeOrigem(estadoDeOrigem);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;

    // Obtenção da Senha do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Cidade de Destino: ";
            cin >> valor;
            cidadeDeDestino.setValor(valor);

            carona->setCidadeDeDestino(cidadeDeDestino);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    qtdTentativas = 0;

    // Obtenção do CPF do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Estado de Destino: ";
            cin >> valor;
            estadoDeDestino.setValor(valor);

            carona->setEstadoDeDestino(estadoDeDestino);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    return true;


    qtdTentativas = 0;

    // Obtenção do CPF do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Data de Partida: ";
            cin >> valor;
            data.setValor(valor);

            carona->setData(data);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    return true;


    qtdTentativas = 0;

    // Obtenção do CPF do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Vagas: ";
            cin >> valor;
            vagas.setValor(valor);

            carona->setVagas(vagas);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    return true;


    qtdTentativas = 0;

    // Obtenção do CPF do Usuário
    while(qtdTentativas++ < MAX_TENTATIVAS)
    {
        try
        {
            cout << "Preco: ";
            cin >> valor;
            preco.setValor(valor);

            carona->setPreco(preco);
            break;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;

            if (qtdTentativas != MAX_TENTATIVAS)
            {
                cout << "Preencha o dado novamente." << endl;
            }
        }
    }

    if (qtdTentativas > MAX_TENTATIVAS)
    {
        cout << "Quantidade maxima de tentativas excedida." << endl;
        return false;
    }

    return true;
}


void CntrRidApres::cadastrarCarona()throw(runtime_error)
{
    // Dados de Carona.
    Carona * carona;
    carona = new Carona();

    TelaDadosCarona telaRide;

    if (!(telaRide.run(carona)))
    {
        return;
    }

    // Após validar os valores.
    bool cadastrado;

    cadastrado = cntrRidServ->cadastrarCarona(carona);

    if (cadastrado)
    {
        cout << endl << "Carona cadastrada com sucesso" << endl;
    }

    else
    {
        cout << endl << "Carona ja existente no banco de dados." << endl;
    }

    return;
}
