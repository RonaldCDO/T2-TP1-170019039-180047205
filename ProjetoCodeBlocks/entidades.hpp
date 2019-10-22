#pragma once

#include "dominios.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


///A Entidade **Usuario** é uma abstração para o usuário do sistema de carona, o qual é indentificado pelos objetos das classes Nome, Telefone, Email, Senha e CPF.
class Usuario
{
    public:
        Nome nome;
        Telefone telefone;
        Email email;
        Senha senha;
        CPF cpf;

        ///O Método tem a função de atribuir um objeto da classe Nome ao atributo **nome** da classe Usuario.
        void setNome(const Nome &nome)
        {
            this->nome = nome;
        }
        ///O Método  tem a função de atribuir um objeto da classe Telefone ao atributo **telefone** da classe Usuario.
        void setTelefone (const Telefone &telefone)
        {
            this->telefone = telefone;
        }

        ///O Método  tem a função de atribuir um objeto da classe Email ao atributo **email** da classe Usuario.
        void setEmail (const Email &email)
        {
            this->email = email;
        }

        ///O Método tem a função de atribuir um objeto da classe Senha ao atributo **senha** da classe Usuario.
        void setSenha (const Senha &senha)
        {
            this->senha = senha;
        }

        ///O Método tem a função de atribuir um objeto da classe CPF ao atributo **cpf** da classe Usuario.
        void setCPF (const CPF &cpf)
        {
            this->cpf = cpf;
        }

        ///O Método tem a função de buscar o atributo **nome** da classe Usuário, salvo a partir da atribuição do objeto da classe Nome.
        ///Retorna o atributo **nome** da classe Usuario.
        Nome getNome ()
        {
            return nome;
        }

        ///O Método tem a função de buscar o atributo **telefone** da classe Usuário, salvo a partir da atribuição do objeto da classe Telefone.
        ///Retorna o atributo **telefone** da classe Usuario.
        Telefone getTelefone ()
        {
            return telefone;
        }

        ///O Método tem a função de buscar o atributo **email** da classe Usuário, salvo a partir da atribuição do objeto da classe Email.
        ///Retorna o atributo **email** da classe Usuario.
        Email getEmail ()
        {
            return email;
        }

        ///O Método tem a função de buscar o atributo **senha** da classe Usuário, salvo a partir da atribuição do objeto da classe Senha.
        ///Retorna o atributo **senha** da classe Usuario.
        Senha getSenha ()
        {
            return senha;
        }

        ///O Método tem a função de buscar o atributo **cpf** da classe Usuário, salvo a partir da atribuição do objeto da classe CPF.
        ///Retorna o atributo **cpf** da classe Usuario.
        CPF getCPF ()
        {
            return cpf;
        }
};



///A Entidade **Reserva** é uma abstração para o registro de um usuário em uma carona do sistema, a qual é indentificada por objetos das classe Codigo, Assento e Bagagem.
class Reserva
{
    public:

        CodigoDeReserva codigo;
        Assento assento;
        Bagagem bagagem;

        ///O Método  tem a função de atribuir um objeto da classe CodigoDeReserva ao atributo **codigo** da classe Reserva.
        void setCodigoDeReserva (const CodigoDeReserva &codigo)
        {
            this->codigo = codigo;
        }

        ///O Método  tem a função de atribuir um objeto da classe Assento ao atributo **assento** da classe Reserva.
        void setAssento (const Assento &assento)
        {
            this->assento = assento;
        }

        ///O Método  tem a função de atribuir um objeto da classe Bagagem ao atributo **bagagem** da classe Reserva.
        void setBagagem (const Bagagem &bagagem)
        {
            this->bagagem = bagagem;
        }

        ///O Método tem a função de buscar o atributo **codigo** da classe Reserva, salvo a partir da atribuição do objeto da classe CodigoDeReserva.
        ///Retorna o atributo **codigo** da classe Reserva.
        CodigoDeReserva getCodigoDeReserva()
        {
            return codigo;
        }

        ///O Método tem a função de buscar o atributo **assento** da classe Reserva, salvo a partir da atribuição do objeto da classe Assento.
        ///Retorna o atributo **assento** da classe Reserva.
        Assento getAssento()
        {
            return assento;
        }

        ///O Método tem a função de buscar o atributo **bagagem** da classe Reserva, salvo a partir da atribuição do objeto da classe Bagagem.
        ///Retorna o atributo **bagagem** da classe Reserva.
        Bagagem getBagagem ()
        {
            return bagagem;
        }
};



///A Entidade **Carona** é uma abstração para o evento principal do sistema de carona, o qual é indentificada pelos objetos codigo, cidadeDeOrigem, estadoDeOrigem,
///cidadeDeDestino, estadoDeDestino, data, duracao, vagas, preco.
class Carona
{
    public:

        CodigoDeCarona codigo;
        Cidade cidadeDeOrigem;
        Estado estadoDeOrigem;
        Cidade cidadeDeDestino;
        Estado estadoDeDestino;
        Data data;
        Duracao duracao;
        Vagas vagas;
        Preco preco;

        ///O Método  tem a função de atribuir um objeto da classe CodigoDeCarona ao atributo **codigo** da classe Carona.
        void setCodigoDeCarona (const CodigoDeCarona &codigo)
        {
            this->codigo = codigo;
        }

        ///O Método  tem a função de atribuir um objeto da classe Cidade ao atributo **cidadeDeOrigem** da classe Carona.
        void setCidadeDeOrigem (const Cidade &cidadeDeOrigem)
        {
            this->cidadeDeOrigem = cidadeDeOrigem;
        }

        ///O Método  tem a função de atribuir um objeto da classe Estado ao atributo **estadoDeOrigem** da classe Carona.
        void setEstadoDeOrigem (const Estado &estadoDeOrigem)
        {
            this->estadoDeOrigem = estadoDeOrigem;
        }

        ///O Método  tem a função de atribuir um objeto da classe Cidade ao atributo **cidadeDeOrigem** da classe Carona.
        void setCidadeDeDestino (const Cidade &cidadeDeDestino)
        {
            this->cidadeDeDestino = cidadeDeDestino;
        }

        ///O Método  tem a função de atribuir um objeto da classe Estado ao atributo **estadoDeOrigem** da classe Carona.
        void setEstadoDeDestino (const Estado &estadoDeDestino)
        {
            this->estadoDeDestino = estadoDeDestino;
        }

        ///O Método  tem a função de atribuir um objeto da classe Data ao atributo **data** da classe Carona.
        void setData (const Data &data)
        {
            this->data = data;
        }

        ///O Método  tem a função de atribuir um objeto da classe Duracao ao atributo **duracao** da classe Carona.
        void setDuracao (const Duracao &duracao)
        {
            this->duracao = duracao;
        }

        ///O Método  tem a função de atribuir um objeto da classe Vagas ao atributo **vagas** da classe Carona.
        void setVagas (const Vagas &vagas)
        {
            this->vagas = vagas;
        }

        ///O Método  tem a função de atribuir um objeto da classe Preco ao atributo **preco** da classe Carona.
        void setPreco (const Preco &preco)
        {
            this->preco = preco;
        }

        ///O Método tem a função de buscar o atributo **codigo** da classe Carona, salvo a partir da atribuição do objeto da classe CodigoDeCarona.
        ///Retorna o atributo **codigo** da classe Carona.
        CodigoDeCarona getCodigoDeCarona()
        {
            return codigo;
        }

        ///O Método tem a função de buscar o atributo **cidadeDeOrigem** da classe Carona, salvo a partir da atribuição do objeto da classe CidadeDeOrigem.
        ///Retorna o atributo **cidadeDeOrigem** da classe Carona.
        Cidade getCidadeDeOrigem ()
        {
            return cidadeDeOrigem;
        }

        ///O Método tem a função de buscar o atributo **estadoDeOrigem** da classe Carona, salvo a partir da atribuição do objeto da classe Estado.
        ///Retorna o atributo **estadoDeOrigem** da classe Carona.
        Estado getEstadoDeOrigem()
        {
            return estadoDeOrigem;
        }

        ///O Método tem a função de buscar o atributo **cidadeDeOrigem** da classe Carona, salvo a partir da atribuição do objeto da classe Cidade.
        ///Retorna o atributo **cidadeDeDestino** da classe Carona.
        Cidade getCidadeDeDestino ()
        {
            return cidadeDeDestino;
        }

        ///O Método tem a função de buscar o atributo **estadoDeDestino** da classe Carona, salvo a partir da atribuição do objeto da classe Estado.
        ///Retorna o atributo **estadoDeDestino** da classe Carona.
        Estado getEstadoDeDestino()
        {
            return estadoDeDestino;
        }

        ///O Método tem a função de buscar o atributo **data** da classe Carona, salvo a partir da atribuição do objeto da classe Data.
        ///Retorna o atributo **data** da classe Carona.
        Data getData ()
        {
            return data;
        }

        ///O Método tem a função de buscar o atributo **duracao** da classe Carona, salvo a partir da atribuição do objeto da classe Duracao.
        ///Retorna o atributo **duracao** da classe Carona.
        Duracao getDuracao()
        {
            return duracao;
        }

        ///O Método tem a função de buscar o atributo **vagas** da classe Carona, salvo a partir da atribuição do objeto da classe Carona.
        ///Retorna o atributo **vagas** da classe Carona.
        Vagas getVagas ()
        {
            return vagas;
        }

        ///O Método tem a função de buscar o atributo **preco** da classe Carona, salvo a partir da atribuição do objeto da classe Preco.
        ///Retorna o atributo **preco** da classe Carona.
        Preco getPreco()
        {
            return preco;
        }
};




///A Entidade **Conta** é uma abstração para a escrituração de registro individual na instituição financeira do usuário do sistema, a qual é indentificada pelos objetos codigoDeBanco, numeroDeAgencia e numeroDeConta.
class Conta
{
    public:
        CodigoDeBanco codigoDeBanco;
        NumeroDeAgencia numeroDeAgencia;
        NumeroDeConta numeroDeConta;

        ///O Método  tem a função de atribuir um objeto da classe CodigoDeBanco ao atributo **codigoDeBanco** da classe Conta.
        void setCodigoDeBanco (const CodigoDeBanco &codigoDeBanco)
        {
            this->codigoDeBanco = codigoDeBanco;
        }

        ///O Método  tem a função de atribuir um objeto da classe NumeroDeAgencia ao atributo **numeroDeAgencia** da classe Conta.
        void setNumeroDeAgencia (const NumeroDeAgencia &numeroDeAgencia)
        {
            this->numeroDeAgencia = numeroDeAgencia;
        }

        ///O Método  tem a função de atribuir um objeto da classe NumeroDeConta ao atributo **numeroDeConta** da classe Conta.
         void setNumeroDeConta (const NumeroDeConta &numeroDeConta)
        {
            this->numeroDeConta = numeroDeConta;
        }

        ///O Método tem a função de buscar o atributo **codigoDeBanco** da classe Conta, salvo a partir da atribuição do objeto da classe CodigoDeBanco.
        ///Retorna o atributo **codigoDeBanco** da classe Conta.
        CodigoDeBanco getCodigoDeBanco()
        {
            return codigoDeBanco;
        }

        ///O Método tem a função de buscar o atributo **numeroDeAgencia** da classe Conta, salvo a partir da atribuição do objeto da classe NumeroDeAgencia.
        ///Retorna o atributo **numeroDeAgencia** da classe Conta.
        NumeroDeAgencia getNumeroDeAgencia()
        {
            return numeroDeAgencia;
        }

        ///O Método tem a função de buscar o atributo **numeroDeConta** da classe Conta, salvo a partir da atribuição do objeto da classe NumeroDeConta.
        ///Retorna o atributo **numeroDeConta** da classe Conta.
        NumeroDeConta getNumeroDeConta()
        {
            return numeroDeConta;
        }
};
