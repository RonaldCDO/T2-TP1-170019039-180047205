///@author <Matheus Costa Oliveira e Ronald Cesar Oliveira>
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

///A Classe **Dominio** � uma classe base para os dom�nios, que s�o elementos b�sicos de um sistema de caronas.
///
///Os dom�nios solicitados herdam a classe base de maneira p�blica. Portanto os m�todos p�blicos, protegidos e privados ser�o herdados nas mesmas caracter�sticas.
///@attention Todas as demais classes do arquivo *dominios* herdam da classe Dominio
///
///Os m�todos CaracterLetra(char) , StringNumerica(string) e AlgoritmoDeLuhn(string) s�o utilizados para verifica��o de algumas classes herdeiras espec�ficas.
class Dominio
{
    private:
        string valor;
        virtual void validar(string) = 0;

    public:
        ///O m�todo setValor tem a fun��o de atribuir um valor para o atributo do tipo string, denotado de maneira privada como *valor*.
        ///@param valor Atributo do tipo string pertencente a todas �s classes e que armazena o valor do dom�nio correspondente.
        ///
        ///Para cada dom�nio herdeiro, um m�todo *validar* � invocado para que se verifique se o par�metro passado segue o formato especificado para cada Classe herdeira.
        ///
        ///No caso do *valor* n�o ser v�lido, o m�todo setValor(string) lan�a uma exce��o do tipo 'invalid_argument' com a descri��o adequada.
        ///
        ///Se o par�metro do tipo string se adequar �s exig�ncias da classe, este *valor* � salvo como atributo da classe.
        void setValor(string);

        ///O m�todo serve para buscar o atributo privado *valor* do tipo string da cada classe em quest�o.
        ///
        ///Retorna o *valor* para o usu�rio da classe que a invocou.
        string getValor()
        {
            return valor;
        }

        ///M�todo utilizado para identificar se um elemento do tipo *char* representa uma letra do alfabeto.
        ///
        ///Se o caracter pertencer aos intervalos (a-z) ou (A-Z) da tabela ASCII, o m�todo retorna um boleano *True*. Caso contr�rio, retorna um *False*.
        static bool CaracterLetra(char);

        ///O m�todo avalia se todos os caracteres da string s�o n�meros, ou seja, se est�o no intervalo (0-9).
        ///
        ///Caso positivo, o m�todo retorna um boleano *True*. Caso contr�rio, retorna *False*.
        static bool StringNumerica(string);

        ///O algoritmo de Luhn � utilizado para verificar a validez de uma combina��o num�rica, cujos dois �ltimos algarismos devem respeitar os crit�rios estabelecidos.
        ///
        ///Uma descri��o detalhada do funcionamento do algoritmo por ser obtida em \link https://en.wikipedia.org/wiki/Luhn_algorithm \endlink .
        ///
        ///@attention O m�todo deve receber uma string puramente num�rica.
        ///
        ///O m�todo retorna *True* se os d�gitos verificadores respeitarem a l�gica do algoritmo. Caso contr�rio, retorna *False*.
        static bool AlgoritmoDeLuhn(string);

        ///Destrutor virtual.
        ///
        ///Utilizado para deletar um objeto de qualquer uma das classes herdeiras.
        virtual ~Dominio()
        {

        }
};


///� a posi��o do banco utilizado pelo passageiro em um ve�culo.
///
///A posi��o do assento pode ser *dianteira* ou *traseira*.
///
///Desse modo, o *valor* passado para o dom�nio pela fun��o setValor() tem de ser do formato "D" ou "T".
class Assento : public Dominio
{
    private:
        void validar(string);
};


///S�o os objetos de uso pessoal do usu�rio, os quais s�o transportados de forma empacotada em malas, mochilas, sacolas, etc.
///
///� permitido o transporte de 0 a 4 bagagens. Portanto, o m�todo validar(string) apenas aceita as string's '0', '1', '2', '3' e '4'.
class Bagagem : public Dominio
{
    private:
        const static int TAMANHO = 1;
        void validar(string);
};


///Dom�nio que identifica a entidade banc�ria cujo o usu�rio do sistema � cliente.
///
///O formato do valor esperado � "XXX", nos quais todos os d�gitos s�o puramente num�ricos (0-9).
///A t�tulo de exemplo, a string "000" configura um *valor* v�lido.
class CodigoDeBanco : public Dominio
{
    private:
        const static int TAMANHO = 3;
        void validar(string);
};


///N�mero utilizado para identificar uma carona composta por diferentes usu�rios do sistema.
///
///O formato � do tipo "XXXX", nos quais todos os d�gitos s�o puramente num�ricos (0-9).
///A t�tulo de exemplo, a string "0000" configura um *valor* v�lido.
class CodigoDeCarona : public Dominio
{
    private:
        const static int TAMANHO = 4;
        void validar(string);
};

///N�mero utilizado pelo sistema e pelos para identificar o planejamento e previs�o do evento no dom�nio de aplica��o.
///
///O formato � do tipo "XXXXX", nos quais todos os d�gitos s�o puramente num�ricos (0-9).
///A t�tulo de exemplo, a string "00000" configura um *valor* v�lido.
class CodigoDeReserva : public Dominio
{
    private:
        const static int TAMANHO = 5;
        void validar(string);
};


///� um aglomerado geogr�fico de pessoas que desempenha fun��es socioecon�micas.
///
///No contexto de um sistema de caronas, � utilizada para identificar a regi�o de in�cio e fim do trajeto.
///
///O formato para o *valor* deve ser uma string de 1 a 10 caracteres, os quais podem ser letras, ponto ou espa�o.
///Pelo menos um dos caracteres deve ser letra, antes de ponto deve haver uma letra e n�o h� espa�os em sequ�ncia.
class Cidade : public Dominio
{
    private:
        const static int TAMANHO = 10;
        void validar(string);
};


///CPF � a sigla para Cadastro de Pessoa F�sica.
///
///Tem a fun��o de identificar os contribuintes da Receita Federal do Brasil.
///Como � reservado para cada cidad�o, permite identificar exclusivamente os usu�rios.
///
///O formato para o *valor* � "XXX.XXX.XXX-YY".
///Na string, X s�o d�gitos num�ricos (0-9) e Y s�o d�gitos verificadores para os 9 primeiros algarismos de acordo com um algoritmo verificador de CPF.
///
///A l�gica do algoritmo verificador pode ser consultada em \link geradorcpf.com/algoritmo_do_cpf.htm \endlink .
class CPF : public Dominio
{
    private:
        const static int TAMANHO = 14;
        void validar(string);
};


///Indica��o do dia, m�s e ano em que determinado fato ocorreu ou dever� ocorrer.
///
///� utilizado para identificar o momento em que ocorre o evento do sistema.
///
///O formato para *valor* � "DD/MM/AAAA", na qual 'DD' representa o dia e vai de 1 a 31, a depender do m�s.
///'MM' representa o m�s e vai de 1 a 12.
///'AAAA' representa o ano.
///
///Vale observar que a verifica��o da data aborda a ocorr�ncia de anos bissextos.
class Data : public Dominio
{
    private:
        const static int TAMANHO = 10;
        void validar(string);
};


///Espa�o de tempo no qual o evento do dom�nio de aplica��o acontece.
///
///O formato de *valor* deve ser uma string num�rica de '1' a '48', que representam a grandeza tempo em horas.
class Duracao : public Dominio
{
    private:
        void validar(string);
};


///Cada um dos territ�rios aut�nomos dentro de uma federa��o.
///
///Como o sistema � desenvolvido para atuar no Brasil, o *valor* deve receber uma das siglas dos estados brasileiros.
///
///As siglas s�o "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE" e "TO".
class Estado : public Dominio
{
    private:
        const static int TAMANHO = 2;
        void validar(string);
};


///Sistema de interc�mbio de mensagens entre computadores ligados em rede utilizado para contactar os usu�rios.
///
///O formato deve ser "local@dominio", no qual as partes 'local' e 'dominio' podem conter no m�ximo 20 caracteres cada.
///
///Os caracteres permitidos s�o letras min�sculas ou ponto final. N�o podem haver dois pontos em sequ�ncia.
///
///O 'local' n�o pode iniciar e nem terminar com ponto. O 'dominio' n�o pode come�ar com ponto.
class Email : public Dominio
{
    private:
        void validar(string);
};


///Palavra dada ao usu�rio que comp�e um dos elementos b�sicos da sua individualiza��o, al�m de ser um dos identificadores no sistema.
///
///O formato deve ser uma string de 1 a 20 caracteres composta por letras, pontos ou espa�os.
///
///Pelo menos um dos caracteres deve ser letra, antes de ponto deve haver uma letra e n�o h� espa�os em sequ�ncia.
class Nome : public Dominio
{
    private:
        void validar(string);
};


///Dado o c�digo de banco que identifica a entidade banc�ria do usu�rio, o n�mero de ag�ncia identifica o local onde tal agente se estabelece e o usu�rio possui seu cadastro.
///
///O formato do *valor* deve ser "XXXX-Y", nos quais os X s�o algarismos (0-9) e Y � um d�gito verificador obtdo pelo AlgoritmoDeLuhn(string) .
class NumeroDeAgencia: public Dominio
{
    private:
        const static int TAMANHO = 6;
        void validar(string);
};


///� um n�mero que identifica a escritura��o de registro individual do usu�rio do sistema em sua institui��o financeira.
///
///O formato do *valor* deve ser "XXXXXX-Y", nos quais os X s�o algarismos (0-9) e Y � um d�gito verificador obtdo pelo AlgoritmoDeLuhn(string) .
class NumeroDeConta : public Dominio
{
    private:
        const static int TAMANHO = 8;
        void validar(string);
};


///Valor econ�mico de um servi�o ou mercadoria.
///
///O formato do *valor* deve ser uma string num�rica de '1' a '5000'. O *valor* representa uma grandeza monet�ria em reais.
class Preco : public Dominio
{
    private:
        void validar(string);
};


///N�meros por meio dos quais se estabelece uma conex�o telef�nica, que s�o utilizados para contactar o usu�rio.
///
///O formato do *valor* deve ser uma string num�rica no formato "XX-YY-ZZZZZZZZZ".
///
///As substrings 'XX', 'YY' e 'ZZZZZZZZZ' n�o podem ser individualmente compostas puramente por zeros.
class Telefone : public Dominio
{
    private:
        const static int TAMANHO = 15;
        void validar(string);
};


///Combina��o de caracteres respons�vel pela seguran�a da conta e pela identifica��o do usu�rio.
///
///O formato do *valor* deve ser uma string de 5 caracteres **distintos**.
///
///Os caracteres podem ser letras mai�sculas ou min�sculas, algarismos ou os s�mbolos '#', '$', '%' e '&'.
class Senha : public Dominio
{
    private:
        const static int TAMANHO = 5;
        void validar(string);
};


///Espa�os dispon�veis para incorpora��o de novos usu�rios.
///No contexto de um sistema de caronas, a quantidade de lugares dispon�veis no ve�culo.
///
///O formato do *valor* deve ser uma string num�rica de '0' a '4'.
///Portanto, as vagas dispon�veis s� podem ser '0', '1', '2', '3' ou '4'.
class Vagas : public Dominio
{
    private:
        const static int TAMANHO = 1;
        void validar(string);
};
