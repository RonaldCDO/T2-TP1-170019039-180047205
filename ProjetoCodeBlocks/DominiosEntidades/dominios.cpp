#include "dominios.hpp"
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//Definicao dos metodos da Classe Abstrata utilizada na Heranca.
void Dominio::setValor(string valor)
{
    validar(valor);
    this->valor = valor;
}


bool Dominio::CaracterLetra(char ch)
{
    if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))
    {
        return true;
    }
    else
        return false;
}


bool Dominio::StringNumerica(string valor)
{
    for (unsigned int i = 0; i < valor.size(); i++)
    {
        if (!((valor[i] >= '0') && (valor[i] <= '9')))
        {
            return false;
        }
    }
    return true;
}


bool Dominio::AlgoritmoDeLuhn(string valor)
{
    const int ultimaPos = valor.size() - 2;  //O ultimo digito a ser verificado e o penultimo da string
    const int teto = 10;                     //Nao podem conter 2 algarismos
    int numero, numeroDobrado;
    int soma = 0;

    for (int i = ultimaPos; i >= 0; i--)
    {
        numero = (int)(valor[i] - '0');

        if ((valor.size() - i) % 2 == 0) //O processo de duplicar acontece a cada dois digitos
        {
            numeroDobrado = 2 * numero;

            if (numeroDobrado >= teto)
            {
                numero = numeroDobrado - 9;
            }
            else
            {
                numero = numeroDobrado;
            }
        }

        soma += numero;
    }

    int unidade = (soma % teto);
    int verificador = (int)(valor[valor.size() - 1] - '0');

    if ((teto - unidade) == verificador)
    {
        return true;
    }
    else {
        return false;
    }
}

//Definicao dos metodos validar especificos de cada Classe
void Assento::validar(string valor)
{
    if((valor != "D") && (valor != "T"))
    {
        throw invalid_argument("Opcao de assento inadequada.");
    }

}


void Bagagem::validar(string valor)
{
    int qtdDeBagagens = stoi(valor);

    if ((qtdDeBagagens < 0) || (qtdDeBagagens > 4) || (valor.size() != TAMANHO))
    {
        throw invalid_argument("Quantidade inadequada de bagagens.");
    }
}


void CodigoDeBanco::validar(string valor)
{
    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Tamanho inadequado para Codigo de Banco.");
    }

    if (!(CodigoDeBanco::StringNumerica(valor)))
    {
        throw invalid_argument("Codigo de banco invalido.");
    }
}


void CodigoDeCarona::validar(string valor)
{
    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Tamanho inadequado para Codigo de Carona.");
    }

    if (!(CodigoDeCarona::StringNumerica(valor)))
    {
        throw invalid_argument("Codigo de carona invalido.");
    }
}


void CodigoDeReserva::validar(string valor)
{
    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Tamanho inadequado para Codigo de Reserva.");
    }

    if (!(CodigoDeReserva::StringNumerica(valor)))
    {
        throw invalid_argument("Codigo de reserva invalido.");
    }
}


void Cidade::validar(string valor)
{
    if (!Cidade::CaracterLetra(valor[0]) && (valor[0] != ' '))
        throw invalid_argument("Nome de cidade invalido.");

    for (unsigned int i = 1 ; i < valor.size(); i++)
    {
        if (valor[i] == '.'){
            if (!Cidade::CaracterLetra(valor[i-1]))
            {
                throw invalid_argument("Nome de cidade invalido.");
            }
        }
        else if (valor[i] == ' '){
            if (valor[i-1] == ' ')
            {
                throw invalid_argument("Nome de cidade invalido.");
            }
        }
        else if (!Cidade::CaracterLetra(valor[i]))
        {
            throw invalid_argument("Nome de cidade invalido.");
        }
    }
}


void CPF::validar(string valor)
{
    int POS_HIFEN;
    int POS_PONTO[2];

    POS_PONTO[0] = 3; //Posicionamento dos pontos e dos hífens para um CPF correto.
    POS_PONTO[1] = 7;
    POS_HIFEN = 11;

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Numero de CPF invalido.");
    }

    if ((valor[POS_PONTO[0]] != '.') || (valor[POS_PONTO[1]] != '.') || (valor[POS_HIFEN] != '-'))
    {
        throw invalid_argument("Numero de CPF invalido.");
    }

    for (int i = 3; i > 0; i--)
    {
        valor.erase(valor.begin() + ((4*i) - 1)); //Remove os '.' e '-' da string;
    }

    int TamanhoVetorDig = valor.size(); //Agora o tamanho do CPF é 11;
    int DigitosVerificadores[TamanhoVetorDig], Verificador[2];
    int DigitoInt;
    int Soma = 0;
    bool TesteDigitos[2];

    if (!(Data::StringNumerica(valor))) //Verifica se os caracteres restantes são números;
    {
        throw invalid_argument("Numero de CPF invalido.");
    }

    for (int i = 0; i < (TamanhoVetorDig - 2); i++) //Executa o algoritmo de vericação para o primeiro dígito.
    {
        DigitoInt = (int)(valor[i] - '0');
        DigitosVerificadores[i] = DigitoInt * (10 - i);
        Soma += DigitosVerificadores[i];
    }

    if ((Soma % 11) < 2)
    {
        DigitosVerificadores[TamanhoVetorDig-2] = 0;
        Verificador[0] = 0;
    }
    else{
        DigitosVerificadores[TamanhoVetorDig-2] = 11 - (Soma % 11);
        Verificador[0] = 11 - (Soma % 11);
    }

    Soma = 0;

    for (int i = 0; i < (TamanhoVetorDig - 1); i++) //Executa a verificação para o segundo dígito
    {
        DigitoInt = (int)(valor[i] - '0');
        DigitosVerificadores[i] = DigitoInt * (11 - i);
        Soma += DigitosVerificadores[i];
    }

    if ((Soma % 11) < 2)
    {
        Verificador[1] = 0;
    }
    else Verificador[1] = 11 - (Soma % 11);

    TesteDigitos[0] = ((int)(valor[valor.size()-2] - '0') != Verificador[0]); //Compara os digitos verificadores digitados pelo usuário
    TesteDigitos[1] = ((int)(valor[valor.size()-1] - '0') != Verificador[1]); // com os obtidos pelo algoritmo.

    if (TesteDigitos[0] || TesteDigitos[1])
    {
        throw invalid_argument("Combinacao numerica invalida para CPF.");
    }
}


void Data::validar(string valor)
{
    int POS_BARRA[2];
    POS_BARRA[0] = 2;
    POS_BARRA[1] = 5;

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Formato de data inadequado.");
    }

    if ((valor[POS_BARRA[0]] != '/') || (valor[POS_BARRA[1]] != '/'))
    {
        throw invalid_argument("Formato de data inadequado.");
    }

    valor.erase(valor.begin() + POS_BARRA[1]); //Remove as barras da string data
    valor.erase(valor.begin() + POS_BARRA[0]);

    if (!(Data::StringNumerica(valor))) //Verifica se os caracteres restantes são numeros
    {
        throw invalid_argument("Formato de data inadequado.");
    }

    const int POS_DIA = 0, POS_MES = 2, POS_ANO = 4;
    const int TAMANHO_DIA = 2, TAMANHO_MES = 2, TAMANHO_ANO = 4;
    const int ANO_MAX = 2099;
    const int ANO_MIN = 2000;
    const int DIA_MES_MIN = 1;
    const int MES_MAX = 12;
    const int FEVEREIRO = 2;
    int dia = stoi(valor.substr(POS_DIA,TAMANHO_DIA)); //Obtencao dos valores para dia, mes e ano
    int mes = stoi(valor.substr(POS_MES,TAMANHO_MES));
    int ano = stoi(valor.substr(POS_ANO,TAMANHO_ANO));
    bool bissexto = (ano % 4 == 0);

    if ((ano < ANO_MIN) || (ano > ANO_MAX))
    {
        throw invalid_argument("Ano invalido: deve ser entre " + to_string(ANO_MIN) + " e " + to_string(ANO_MAX));
    }

    if ((mes < DIA_MES_MIN) || (mes > MES_MAX))
    {
        throw invalid_argument("Mes invalido: deve ser entre " + to_string(DIA_MES_MIN) + " e " + to_string(MES_MAX));
    }

    vector<int> meses31 = {1,3,5,7,8,10,12};
    vector<int> meses30 = {4,6,9,11};
    string errorMessage;

    if (count(meses31.begin(),meses31.end(),mes))
    {
        if ((dia < DIA_MES_MIN) || (dia > 31))
        {
            errorMessage = "O mes " + to_string(mes) + " tem dias de 1 a 31";
            throw invalid_argument(errorMessage);
        }
    }

    else {
        if (count(meses30.begin(),meses30.end(),mes))
        {
            if ((dia < DIA_MES_MIN) || (dia > 30))
            {
                throw invalid_argument("O mes " + to_string(mes) + " tem dias de 1 a 30");
            }
        }
        else {
            if (mes == FEVEREIRO)
                {
                if (bissexto){
                    if ((dia < DIA_MES_MIN) || (dia > 29))
                    {
                        throw invalid_argument("O ano " + to_string(ano) + " é bissexto. O mes " + to_string(FEVEREIRO)
                                               + " comtempla dias de 1 a 29.");
                    }
                }
                else {
                    if ((dia < DIA_MES_MIN) || (dia > 28))
                    {
                        throw invalid_argument("O ano " + to_string(ano) +
                                               " não é bissexto. Portanto,"
                                               " o mes 2 so comtempla dias de 1 a 28.");
                    }
                }
            }
        }
    }
}


void Duracao::validar(string valor)
{
    int duracao = stoi(valor);
    const int LIMITE_SUP = 48;
    const int LIMITE_INF = 1;

    if ((duracao < LIMITE_INF) || (duracao > LIMITE_SUP))
    {
        throw invalid_argument("Duracao invalida. Deve ser de " + to_string(LIMITE_INF) +
                                " a " + to_string(LIMITE_SUP) + " horas");
    }

    bool horaInteira = (stof(valor) - stoi(valor) == 0);

    if (!horaInteira)
    {
        throw invalid_argument("A duracao deve ser um valor inteiro em horas.");
    }
}


void Estado::validar(string valor)
{
    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("A sigla para o estado deve ser duas letras maiusculas.");
    }

    vector<string> estados = {"AC", "AL", "AP", "AM", "BA", "CE", "DF",
                              "ES", "GO", "MA", "MT", "MS", "MG", "PA",
                              "PB", "PR", "PE", "PI", "RJ", "RN", "RS",
                              "RO", "RR", "SC", "SP", "SE", "TO"};

    if (!(count(estados.begin(),estados.end(),valor)))
    {
        throw invalid_argument("Sigla para estado invalida.");
    }
}


void Email::validar(string valor)
{
    const int TAMANHO_MAX_EMAIL = 41;

    if (valor.size() > TAMANHO_MAX_EMAIL)
    {
        throw invalid_argument("Tamanho de e-mail excedido.");
    }

    char arroba = '@';
    size_t posArroba = valor.find(arroba);

    if (posArroba == string::npos)
    {
        throw invalid_argument("O e-mail deve ter local e dominio separados por " + string(1,arroba) + ".");
    }

    stringstream email(valor);
    string elementoEmail;
    vector<string> localEDominio;
    const int TAMANHO_MAX_ELEMENTO = 20;
    char ponto = '.';
    string doisPontos = "..";
    size_t posDoisPontos = valor.find(doisPontos);

    if (posDoisPontos != string::npos)
    {
        throw invalid_argument("Nao e permitido dois pontos em sequencia.");
    }

    while(getline(email, elementoEmail, arroba))
    {
        localEDominio.push_back(elementoEmail);
    }

    if ((localEDominio[0].size() > TAMANHO_MAX_ELEMENTO) || (localEDominio[1].size() > TAMANHO_MAX_ELEMENTO))
    {
        throw invalid_argument("O local e o dominio so podem conter ate " + to_string(TAMANHO_MAX_ELEMENTO) + " caracteres.");
    }

    if ((localEDominio[0].front() == ponto) || (localEDominio[0].back() == ponto))
    {
        throw invalid_argument("A parte 'local' do e-mail nao pode iniciar e nem terminar com ponto.");
    }

    if (localEDominio[1].front() == ponto)
    {
        throw invalid_argument("Nao e permitido que o dominio se inicie com ponto.");
    }

    for(int i = 0; i < 2; i++)
    {
        for(string::iterator it = localEDominio[i].begin(); it < localEDominio[i].end(); it++)
        {
            if (!(((*it >= 'a') && (*it <= 'z')) || (*it == ponto)))
            {
                throw invalid_argument("Caracter invalido. E permitido apenas o ponto final e letras de a-z.");
            }
        }
    }
}


void Nome::validar(string valor)
{
    const int TAMANHO_MAX = 20;

    if (valor.size() > TAMANHO_MAX)
    {
        throw invalid_argument("O nome só pode ter até " + to_string(TAMANHO_MAX) + " caracteres.");
    }

    char ponto = '.';
    char espaco = ' ';

    if (valor == string(1,espaco))
    {
        throw invalid_argument("O nome deve conter letras.");
    }

    for (string::iterator it = valor.begin(); it < valor.end(); it++)
    {

        if (!(Nome::CaracterLetra(*it) || (*it == ponto) || (*it == espaco)))
        {
            throw invalid_argument("O nome so deve conter letras, ponto ou espaço.");
        }

        // Ao encontrar um ponto, verificar se este e precedido por letra ou inicia o nome.
        if ((*it == ponto) && (!(Nome::CaracterLetra(*(it-1))) || (it == valor.begin())))
        {
            throw invalid_argument("Os pontos devem estar precedidos de letras.");
        }

    string doisEspacos = "  ";
    size_t posDoisEspacos = valor.find(doisEspacos);

        if (posDoisEspacos != string::npos)
        {
            throw invalid_argument("Nao deve haver espaços em sequencia.");
        }
    }
}


void NumeroDeAgencia::validar(string valor)
{
    const int POS_HIFEN = TAMANHO - 2;

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Tamanho inadequado para Numero de Agencia.");
    }

    if (valor[POS_HIFEN] != '-')
    {
        throw invalid_argument("O Numero de Agencia deve conter o formato NNNN-N, no qual N vai de 0 a 9.");
    }

    valor.erase(valor.begin() + POS_HIFEN);

    if (!(NumeroDeAgencia::StringNumerica(valor)))
    {
        throw invalid_argument("Os dados do Numero de Agencia devem ser somente numericos");
    }

    if (!(NumeroDeAgencia::AlgoritmoDeLuhn(valor)))
    {
        throw invalid_argument("O digito verificador nao confere com o Algoritmo de Luhn.");
    }
}


void NumeroDeConta::validar(string valor){
    const int POS_HIFEN = TAMANHO - 2;

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Tamanho inadequado para Numero de Conta.");
    }

    if (valor[POS_HIFEN] != '-')
    {
        throw invalid_argument("O Numero de Conta deve conter o formato NNNNNN-N, no qual N vai de 0 a 9.");
    }

    valor.erase(valor.begin() + POS_HIFEN);

    if (!(NumeroDeAgencia::StringNumerica(valor)))
    {
        throw invalid_argument("Os dados do Numero de Conta devem ser somente numericos");
    }

    if (!(NumeroDeAgencia::AlgoritmoDeLuhn(valor)))
    {
        throw invalid_argument("O digito verificador nao confere com o Algoritmo de Luhn.");
    }
}


void Preco::validar(string valor){

    const float PRECO_MIN = 1;
    const float PRECO_MAX = 5000;
    float preco;
    string::size_type sz;

    try {
        preco = stof(valor, &sz);
    }
    catch(exception& exp){
        throw invalid_argument("O preco deve ser um valor numerico.");
    }

    if ((preco < PRECO_MIN) || (preco > PRECO_MAX))
    {
        throw invalid_argument("Preco deve estar entre 1 e 5000.");
    }
}


void Telefone::validar(string valor){

    vector<int> posHifen {2, 5};
    char hifen = '-';

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("Tamanho inadequado para telefone.");
    }

    if ((valor[posHifen[0]] != hifen) || (valor[posHifen[1]] != hifen))
    {
        throw invalid_argument("Codigo de pais, DDD e telefone combinam 13 digitos e devem estar separados por hifen.");
    }

    for (int i = (posHifen.size() - 1); i >= 0; i--) //Apagar os hífens da string
        valor.erase(valor.begin() + posHifen[i]);

    if (!(Telefone::StringNumerica(valor)))
    {
        throw invalid_argument("Os codigos de telefone so aceitam digitos numericos de 0 a 9.");
    }

    int paisInit = 0;
    int tamanhoPais = 2;
    int dddInit = 2;
    int tamanhoDdd = 2;
    int telefoneInit = 4;
    int tamanhoTelefone = 9;
    string codigoPais = valor.substr(paisInit, tamanhoPais);
    string ddd = valor.substr(dddInit, tamanhoDdd);
    string telefone = valor.substr(telefoneInit, tamanhoTelefone);
    string doisZeros = "00";
    string noveZeros = "000000000";

    if ((codigoPais == doisZeros) || (ddd == doisZeros) || (telefone == noveZeros))
    {
        throw invalid_argument("O codigo de pais, o DDD e o numero de telefone nao podem ser compostos somente por '0's.");
    }
}


void Senha::validar(string valor){

    bool caracterLetra;
    int caracterNumero;
    int caracterEspecial;
    bool existeLetra = false;
    bool existeNumero = false;

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("A senha deve conter 5 caracteres distintos.");
    }

    vector<char> caracteres {'#','$','%','&'};
    vector<char> numeros {'0','1','2','3','4','5','6','7','8','9'};
    size_t posCaracter;

    for (string::iterator it = valor.begin(); it < valor.end(); it++){
        caracterLetra = Senha::CaracterLetra(*it);
        caracterEspecial = count(caracteres.begin(),caracteres.end(),*it);
        caracterNumero = count(numeros.begin(),numeros.end(),*it);

        if (!(caracterLetra) && !(caracterNumero) && !(caracterEspecial))
        {
            throw invalid_argument("Os caracteres devem ser letras, numeros ou os especiais '#', '$', '%' e '&'.");
        }

        if (caracterLetra)
        {
            existeLetra = true;
        }

        if (caracterNumero)
        {
            existeNumero = true;
        }

        posCaracter = valor.find(*it);
        posCaracter = valor.find(*it, posCaracter+1);

        if (posCaracter != string::npos)
        {
            throw invalid_argument("Nao deve haver caracteres repetidos na senha.");
        }
    }

    if (!(existeLetra && existeNumero))
    {
        throw invalid_argument("A senha deve conter pelo menos uma letra e um numero.");
    }
}


void Vagas::validar(string valor){

    const int VAGAS_MIN = 0;
    const int VAGAS_MAX = 4;

    if (valor.size() != TAMANHO)
    {
        throw invalid_argument("A vaga deve ser um digito numerico inteiro de 0 a 4.");
    }

    int vagas = (int)(valor[0] - '0');

    if ((vagas < VAGAS_MIN) || (vagas > VAGAS_MAX))
    {
        throw invalid_argument("A vaga deve ser um valor numerico inteiro de 0 a 4.");
    }
}
