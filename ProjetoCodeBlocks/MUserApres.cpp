#include "MUserApres.hpp"

using namespace std;

void CntrUserApres::cadastar() throw(runtime_error)
{
    Usuario * usuario;
    usuario = new Usuario();

    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    CPF cpf;

    string valor;

    try
    {
        cout << endl << "Informacoes para Cadastro de Usuario." << endl << endl;

        cout << "Nome: ";
        cin >> valor;
        usuario->setNome(valor);

        cout << "Telefone: ";
        cin >> valor;
        usuario->setTelefone(valor);

        cout << "E-mail: ";
        cin >> valor;
        usuario->setEmail(valor);

        cout << "Senha: ";
        cin >> valor;
        usuario->setSenha(valor);

        cout << "CPF: ";
        cin >> valor;
        usuario->setCPF(valor);
    }
    catch(const invalid_argument& exp)
    {
        cout << exp.what() << endl;
    }
}