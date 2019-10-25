#include "MAutApres.hpp"

using namespace std;

bool CntrAutApres::autenticar(Email * email) throw(runtime_error)
{
    string valorEmail, valorSenha;
    Senha senha;

    const int MAX_TENTATIVAS = 3;
    int i = 0;
    bool resultado;

    while (true)
    {
        try
        {
            cout << "Digite seu E-mail cadastrado: ";
            cin >> valorEmail;
            cout << "Digite sua Senha: ";
            cin >> valorSenha;

            email->setValor(valorEmail);
            senha.setValor(valorSenha);

            resultado = cntrAutServ->autenticar(email, senha);
            return resultado;
        }

        catch(const invalid_argument& exp)
        {
            cout << exp.what() << endl;
            
            if (++i == MAX_TENTATIVAS)
            {
                cout << "Quantidade de tentativas excedida." << endl;
                return false;
            }
        }
    }
}