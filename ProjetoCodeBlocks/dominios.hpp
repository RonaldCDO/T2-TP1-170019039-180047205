///@author <Matheus Costa Oliveira e Ronald Cesar Oliveira>
#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

///A Classe **Dominio** é uma classe base para os domínios, que são elementos básicos de um sistema de caronas.
///
///Os domínios solicitados herdam a classe base de maneira pública. Portanto os métodos públicos, protegidos e privados serão herdados nas mesmas características.
///@attention Todas as demais classes do arquivo *dominios* herdam da classe Dominio
///
///Os métodos CaracterLetra(char) , StringNumerica(string) e AlgoritmoDeLuhn(string) são utilizados para verificação de algumas classes herdeiras específicas.
class Dominio
{
    private:
        string valor;
        virtual void validar(string) = 0;

    public:
        ///O método setValor tem a função de atribuir um valor para o atributo do tipo string, denotado de maneira privada como *valor*.
        ///@param valor Atributo do tipo string pertencente a todas às classes e que armazena o valor do domínio correspondente.
        ///
        ///Para cada domínio herdeiro, um método *validar* é invocado para que se verifique se o parâmetro passado segue o formato especificado para cada Classe herdeira.
        ///
        ///No caso do *valor* não ser válido, o método setValor(string) lança uma exceção do tipo 'invalid_argument' com a descrição adequada.
        ///
        ///Se o parâmetro do tipo string se adequar às exigências da classe, este *valor* é salvo como atributo da classe.
        void setValor(string);

        ///O método serve para buscar o atributo privado *valor* do tipo string da cada classe em questão.
        ///
        ///Retorna o *valor* para o usuário da classe que a invocou.
        string getValor()
        {
            return valor;
        }

        ///Método utilizado para identificar se um elemento do tipo *char* representa uma letra do alfabeto.
        ///
        ///Se o caracter pertencer aos intervalos (a-z) ou (A-Z) da tabela ASCII, o método retorna um boleano *True*. Caso contrário, retorna um *False*.
        static bool CaracterLetra(char);

        ///O método avalia se todos os caracteres da string são números, ou seja, se estão no intervalo (0-9).
        ///
        ///Caso positivo, o método retorna um boleano *True*. Caso contrário, retorna *False*.
        static bool StringNumerica(string);

        ///O algoritmo de Luhn é utilizado para verificar a validez de uma combinação numérica, cujos dois últimos algarismos devem respeitar os critérios estabelecidos.
        ///
        ///Uma descrição detalhada do funcionamento do algoritmo por ser obtida em \link https://en.wikipedia.org/wiki/Luhn_algorithm \endlink .
        ///
        ///@attention O método deve receber uma string puramente numérica.
        ///
        ///O método retorna *True* se os dígitos verificadores respeitarem a lógica do algoritmo. Caso contrário, retorna *False*.
        static bool AlgoritmoDeLuhn(string);

        ///Destrutor virtual.
        ///
        ///Utilizado para deletar um objeto de qualquer uma das classes herdeiras.
        virtual ~Dominio()
        {

        }
};


///É a posição do banco utilizado pelo passageiro em um veículo.
///
///A posição do assento pode ser *dianteira* ou *traseira*.
///
///Desse modo, o *valor* passado para o domínio pela função setValor() tem de ser do formato "D" ou "T".
class Assento : public Dominio
{
    private:
        void validar(string);
};


///São os objetos de uso pessoal do usuário, os quais são transportados de forma empacotada em malas, mochilas, sacolas, etc.
///
///É permitido o transporte de 0 a 4 bagagens. Portanto, o método validar(string) apenas aceita as string's '0', '1', '2', '3' e '4'.
class Bagagem : public Dominio
{
    private:
        const static int TAMANHO = 1;
        void validar(string);
};


///Domínio que identifica a entidade bancária cujo o usuário do sistema é cliente.
///
///O formato do valor esperado é "XXX", nos quais todos os dígitos são puramente numéricos (0-9).
///A título de exemplo, a string "000" configura um *valor* válido.
class CodigoDeBanco : public Dominio
{
    private:
        const static int TAMANHO = 3;
        void validar(string);
};


///Número utilizado para identificar uma carona composta por diferentes usuários do sistema.
///
///O formato é do tipo "XXXX", nos quais todos os dígitos são puramente numéricos (0-9).
///A título de exemplo, a string "0000" configura um *valor* válido.
class CodigoDeCarona : public Dominio
{
    private:
        const static int TAMANHO = 4;
        void validar(string);
};

///Número utilizado pelo sistema e pelos para identificar o planejamento e previsão do evento no domínio de aplicação.
///
///O formato é do tipo "XXXXX", nos quais todos os dígitos são puramente numéricos (0-9).
///A título de exemplo, a string "00000" configura um *valor* válido.
class CodigoDeReserva : public Dominio
{
    private:
        const static int TAMANHO = 5;
        void validar(string);
};


///É um aglomerado geográfico de pessoas que desempenha funções socioeconômicas.
///
///No contexto de um sistema de caronas, é utilizada para identificar a região de início e fim do trajeto.
///
///O formato para o *valor* deve ser uma string de 1 a 10 caracteres, os quais podem ser letras, ponto ou espaço.
///Pelo menos um dos caracteres deve ser letra, antes de ponto deve haver uma letra e não há espaços em sequência.
class Cidade : public Dominio
{
    private:
        const static int TAMANHO = 10;
        void validar(string);
};


///CPF é a sigla para Cadastro de Pessoa Física.
///
///Tem a função de identificar os contribuintes da Receita Federal do Brasil.
///Como é reservado para cada cidadão, permite identificar exclusivamente os usuários.
///
///O formato para o *valor* é "XXX.XXX.XXX-YY".
///Na string, X são dígitos numéricos (0-9) e Y são dígitos verificadores para os 9 primeiros algarismos de acordo com um algoritmo verificador de CPF.
///
///A lógica do algoritmo verificador pode ser consultada em \link geradorcpf.com/algoritmo_do_cpf.htm \endlink .
class CPF : public Dominio
{
    private:
        const static int TAMANHO = 14;
        void validar(string);
};


///Indicação do dia, mês e ano em que determinado fato ocorreu ou deverá ocorrer.
///
///É utilizado para identificar o momento em que ocorre o evento do sistema.
///
///O formato para *valor* é "DD/MM/AAAA", na qual 'DD' representa o dia e vai de 1 a 31, a depender do mês.
///'MM' representa o mês e vai de 1 a 12.
///'AAAA' representa o ano.
///
///Vale observar que a verificação da data aborda a ocorrência de anos bissextos.
class Data : public Dominio
{
    private:
        const static int TAMANHO = 10;
        void validar(string);
};


///Espaço de tempo no qual o evento do domínio de aplicação acontece.
///
///O formato de *valor* deve ser uma string numérica de '1' a '48', que representam a grandeza tempo em horas.
class Duracao : public Dominio
{
    private:
        void validar(string);
};


///Cada um dos territórios autônomos dentro de uma federação.
///
///Como o sistema é desenvolvido para atuar no Brasil, o *valor* deve receber uma das siglas dos estados brasileiros.
///
///As siglas são "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE" e "TO".
class Estado : public Dominio
{
    private:
        const static int TAMANHO = 2;
        void validar(string);
};


///Sistema de intercâmbio de mensagens entre computadores ligados em rede utilizado para contactar os usuários.
///
///O formato deve ser "local@dominio", no qual as partes 'local' e 'dominio' podem conter no máximo 20 caracteres cada.
///
///Os caracteres permitidos são letras minúsculas ou ponto final. Não podem haver dois pontos em sequência.
///
///O 'local' não pode iniciar e nem terminar com ponto. O 'dominio' não pode começar com ponto.
class Email : public Dominio
{
    private:
        void validar(string);
};


///Palavra dada ao usuário que compõe um dos elementos básicos da sua individualização, além de ser um dos identificadores no sistema.
///
///O formato deve ser uma string de 1 a 20 caracteres composta por letras, pontos ou espaços.
///
///Pelo menos um dos caracteres deve ser letra, antes de ponto deve haver uma letra e não há espaços em sequência.
class Nome : public Dominio
{
    private:
        void validar(string);
};


///Dado o código de banco que identifica a entidade bancária do usuário, o número de agência identifica o local onde tal agente se estabelece e o usuário possui seu cadastro.
///
///O formato do *valor* deve ser "XXXX-Y", nos quais os X são algarismos (0-9) e Y é um dígito verificador obtdo pelo AlgoritmoDeLuhn(string) .
class NumeroDeAgencia: public Dominio
{
    private:
        const static int TAMANHO = 6;
        void validar(string);
};


///É um número que identifica a escrituração de registro individual do usuário do sistema em sua instituição financeira.
///
///O formato do *valor* deve ser "XXXXXX-Y", nos quais os X são algarismos (0-9) e Y é um dígito verificador obtdo pelo AlgoritmoDeLuhn(string) .
class NumeroDeConta : public Dominio
{
    private:
        const static int TAMANHO = 8;
        void validar(string);
};


///Valor econômico de um serviço ou mercadoria.
///
///O formato do *valor* deve ser uma string numérica de '1' a '5000'. O *valor* representa uma grandeza monetária em reais.
class Preco : public Dominio
{
    private:
        void validar(string);
};


///Números por meio dos quais se estabelece uma conexão telefônica, que são utilizados para contactar o usuário.
///
///O formato do *valor* deve ser uma string numérica no formato "XX-YY-ZZZZZZZZZ".
///
///As substrings 'XX', 'YY' e 'ZZZZZZZZZ' não podem ser individualmente compostas puramente por zeros.
class Telefone : public Dominio
{
    private:
        const static int TAMANHO = 15;
        void validar(string);
};


///Combinação de caracteres responsável pela segurança da conta e pela identificação do usuário.
///
///O formato do *valor* deve ser uma string de 5 caracteres **distintos**.
///
///Os caracteres podem ser letras maiúsculas ou minúsculas, algarismos ou os símbolos '#', '$', '%' e '&'.
class Senha : public Dominio
{
    private:
        const static int TAMANHO = 5;
        void validar(string);
};


///Espaços disponíveis para incorporação de novos usuários.
///No contexto de um sistema de caronas, a quantidade de lugares disponíveis no veículo.
///
///O formato do *valor* deve ser uma string numérica de '0' a '4'.
///Portanto, as vagas disponíveis só podem ser '0', '1', '2', '3' ou '4'.
class Vagas : public Dominio
{
    private:
        const static int TAMANHO = 1;
        void validar(string);
};
