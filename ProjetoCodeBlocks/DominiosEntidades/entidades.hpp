#pragma once

#include "dominios.hpp"
#include <iostream>
#include <string>
#include <stdexcept>


class Entidade
{
    public:
};



///A Entidade **Usuario** � uma abstra��o para o usu�rio do sistema de carona, o qual � indentificado pelos objetos das classes Nome, Telefone, Email, Senha e CPF.
class Usuario : public Entidade
{
    private:
        Nome nome;
        Telefone telefone;
        Email email;
        Senha senha;
        CPF cpf;


    public:
        ///O M�todo tem a fun��o de atribuir um objeto da classe Nome ao atributo **nome** da classe Usuario.
        void setNome(const Nome &nome)
        {
            this->nome = nome;
        }
        ///O M�todo  tem a fun��o de atribuir um objeto da classe Telefone ao atributo **telefone** da classe Usuario.
        void setTelefone (const Telefone &telefone)
        {
            this->telefone = telefone;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Email ao atributo **email** da classe Usuario.
        void setEmail (const Email &email)
        {
            this->email = email;
        }

        ///O M�todo tem a fun��o de atribuir um objeto da classe Senha ao atributo **senha** da classe Usuario.
        void setSenha (const Senha &senha)
        {
            this->senha = senha;
        }

        ///O M�todo tem a fun��o de atribuir um objeto da classe CPF ao atributo **cpf** da classe Usuario.
        void setCPF (const CPF &cpf)
        {
            this->cpf = cpf;
        }

        ///O M�todo tem a fun��o de buscar o atributo **nome** da classe Usu�rio, salvo a partir da atribui��o do objeto da classe Nome.
        ///Retorna o atributo **nome** da classe Usuario.
        Nome getNome ()
        {
            return nome;
        }

        ///O M�todo tem a fun��o de buscar o atributo **telefone** da classe Usu�rio, salvo a partir da atribui��o do objeto da classe Telefone.
        ///Retorna o atributo **telefone** da classe Usuario.
        Telefone getTelefone ()
        {
            return telefone;
        }

        ///O M�todo tem a fun��o de buscar o atributo **email** da classe Usu�rio, salvo a partir da atribui��o do objeto da classe Email.
        ///Retorna o atributo **email** da classe Usuario.
        Email getEmail ()
        {
            return email;
        }

        ///O M�todo tem a fun��o de buscar o atributo **senha** da classe Usu�rio, salvo a partir da atribui��o do objeto da classe Senha.
        ///Retorna o atributo **senha** da classe Usuario.
        Senha getSenha ()
        {
            return senha;
        }

        ///O M�todo tem a fun��o de buscar o atributo **cpf** da classe Usu�rio, salvo a partir da atribui��o do objeto da classe CPF.
        ///Retorna o atributo **cpf** da classe Usuario.
        CPF getCPF ()
        {
            return cpf;
        }
};



///A Entidade **Carona** � uma abstra��o para o evento principal do sistema de carona, o qual � indentificada pelos objetos codigo, cidadeDeOrigem, estadoDeOrigem,
///cidadeDeDestino, estadoDeDestino, data, duracao, vagas, preco.
class Carona : public Entidade
{
    private:

        CodigoDeCarona codigo;
        Cidade cidadeDeOrigem;
        Estado estadoDeOrigem;
        Cidade cidadeDeDestino;
        Estado estadoDeDestino;
        Data data;
        Duracao duracao;
        Vagas vagas;
        Preco preco;

        Usuario * provedor;

    public:
        ///O M�todo  tem a fun��o de atribuir um objeto da classe CodigoDeCarona ao atributo **codigo** da classe Carona.
        void setCodigoDeCarona (const CodigoDeCarona &codigo)
        {
            this->codigo = codigo;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Cidade ao atributo **cidadeDeOrigem** da classe Carona.
        void setCidadeDeOrigem (const Cidade &cidadeDeOrigem)
        {
            this->cidadeDeOrigem = cidadeDeOrigem;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Estado ao atributo **estadoDeOrigem** da classe Carona.
        void setEstadoDeOrigem (const Estado &estadoDeOrigem)
        {
            this->estadoDeOrigem = estadoDeOrigem;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Cidade ao atributo **cidadeDeOrigem** da classe Carona.
        void setCidadeDeDestino (const Cidade &cidadeDeDestino)
        {
            this->cidadeDeDestino = cidadeDeDestino;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Estado ao atributo **estadoDeOrigem** da classe Carona.
        void setEstadoDeDestino (const Estado &estadoDeDestino)
        {
            this->estadoDeDestino = estadoDeDestino;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Data ao atributo **data** da classe Carona.
        void setData (const Data &data)
        {
            this->data = data;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Duracao ao atributo **duracao** da classe Carona.
        void setDuracao (const Duracao &duracao)
        {
            this->duracao = duracao;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Vagas ao atributo **vagas** da classe Carona.
        void setVagas (const Vagas &vagas)
        {
            this->vagas = vagas;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Preco ao atributo **preco** da classe Carona.
        void setPreco (const Preco &preco)
        {
            this->preco = preco;
        }

        void setProvedorDaCarona (Usuario * provedor)
        {
            this->provedor = provedor;
        }

        ///O M�todo tem a fun��o de buscar o atributo **codigo** da classe Carona, salvo a partir da atribui��o do objeto da classe CodigoDeCarona.
        ///Retorna o atributo **codigo** da classe Carona.
        CodigoDeCarona getCodigoDeCarona()
        {
            return codigo;
        }

        ///O M�todo tem a fun��o de buscar o atributo **cidadeDeOrigem** da classe Carona, salvo a partir da atribui��o do objeto da classe CidadeDeOrigem.
        ///Retorna o atributo **cidadeDeOrigem** da classe Carona.
        Cidade getCidadeDeOrigem ()
        {
            return cidadeDeOrigem;
        }

        ///O M�todo tem a fun��o de buscar o atributo **estadoDeOrigem** da classe Carona, salvo a partir da atribui��o do objeto da classe Estado.
        ///Retorna o atributo **estadoDeOrigem** da classe Carona.
        Estado getEstadoDeOrigem()
        {
            return estadoDeOrigem;
        }

        ///O M�todo tem a fun��o de buscar o atributo **cidadeDeOrigem** da classe Carona, salvo a partir da atribui��o do objeto da classe Cidade.
        ///Retorna o atributo **cidadeDeDestino** da classe Carona.
        Cidade getCidadeDeDestino ()
        {
            return cidadeDeDestino;
        }

        ///O M�todo tem a fun��o de buscar o atributo **estadoDeDestino** da classe Carona, salvo a partir da atribui��o do objeto da classe Estado.
        ///Retorna o atributo **estadoDeDestino** da classe Carona.
        Estado getEstadoDeDestino()
        {
            return estadoDeDestino;
        }

        ///O M�todo tem a fun��o de buscar o atributo **data** da classe Carona, salvo a partir da atribui��o do objeto da classe Data.
        ///Retorna o atributo **data** da classe Carona.
        Data getData ()
        {
            return data;
        }

        ///O M�todo tem a fun��o de buscar o atributo **duracao** da classe Carona, salvo a partir da atribui��o do objeto da classe Duracao.
        ///Retorna o atributo **duracao** da classe Carona.
        Duracao getDuracao()
        {
            return duracao;
        }

        ///O M�todo tem a fun��o de buscar o atributo **vagas** da classe Carona, salvo a partir da atribui��o do objeto da classe Carona.
        ///Retorna o atributo **vagas** da classe Carona.
        Vagas getVagas ()
        {
            return vagas;
        }

        ///O M�todo tem a fun��o de buscar o atributo **preco** da classe Carona, salvo a partir da atribui��o do objeto da classe Preco.
        ///Retorna o atributo **preco** da classe Carona.
        Preco getPreco()
        {
            return preco;
        }

        Usuario * getProvedorDaCarona ()
        {
            return provedor;
        }
};


///A Entidade **Reserva** � uma abstra��o para o registro de um usu�rio em uma carona do sistema, a qual � indentificada por objetos das classe Codigo, Assento e Bagagem.
class Reserva : public Entidade
{
    private:

        CodigoDeReserva codigo;
        Assento assento;
        Bagagem bagagem;

        Usuario * cliente;
        Carona * caronaAssociada;

    public:
        ///O M�todo  tem a fun��o de atribuir um objeto da classe CodigoDeReserva ao atributo **codigo** da classe Reserva.
        void setCodigoDeReserva (const CodigoDeReserva &codigo)
        {
            this->codigo = codigo;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Assento ao atributo **assento** da classe Reserva.
        void setAssento (const Assento &assento)
        {
            this->assento = assento;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe Bagagem ao atributo **bagagem** da classe Reserva.
        void setBagagem (const Bagagem &bagagem)
        {
            this->bagagem = bagagem;
        }

        void setCliente(Usuario * cliente)
        {
            this->cliente = cliente;
        }

        void setCaronaAssociada(Carona * carona)
        {
            this->caronaAssociada = caronaAssociada;
        }

        ///O M�todo tem a fun��o de buscar o atributo **codigo** da classe Reserva, salvo a partir da atribui��o do objeto da classe CodigoDeReserva.
        ///Retorna o atributo **codigo** da classe Reserva.
        CodigoDeReserva getCodigoDeReserva()
        {
            return codigo;
        }

        ///O M�todo tem a fun��o de buscar o atributo **assento** da classe Reserva, salvo a partir da atribui��o do objeto da classe Assento.
        ///Retorna o atributo **assento** da classe Reserva.
        Assento getAssento()
        {
            return assento;
        }

        ///O M�todo tem a fun��o de buscar o atributo **bagagem** da classe Reserva, salvo a partir da atribui��o do objeto da classe Bagagem.
        ///Retorna o atributo **bagagem** da classe Reserva.
        Bagagem getBagagem ()
        {
            return bagagem;
        }

        Usuario * getCliente()
        {
            return cliente;
        }

        Carona * getCarona()
        {
            return caronaAssociada;
        }
};



///A Entidade **Conta** � uma abstra��o para a escritura��o de registro individual na institui��o financeira do usu�rio do sistema, a qual � indentificada pelos objetos codigoDeBanco, numeroDeAgencia e numeroDeConta.
class Conta : public Entidade
{
    private:
        CodigoDeBanco codigoDeBanco;
        NumeroDeAgencia numeroDeAgencia;
        NumeroDeConta numeroDeConta;

        Usuario * dono;

    public:
        ///O M�todo  tem a fun��o de atribuir um objeto da classe CodigoDeBanco ao atributo **codigoDeBanco** da classe Conta.
        void setCodigoDeBanco (const CodigoDeBanco &codigoDeBanco)
        {
            this->codigoDeBanco = codigoDeBanco;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe NumeroDeAgencia ao atributo **numeroDeAgencia** da classe Conta.
        void setNumeroDeAgencia (const NumeroDeAgencia &numeroDeAgencia)
        {
            this->numeroDeAgencia = numeroDeAgencia;
        }

        ///O M�todo  tem a fun��o de atribuir um objeto da classe NumeroDeConta ao atributo **numeroDeConta** da classe Conta.
        void setNumeroDeConta (const NumeroDeConta &numeroDeConta)
        {
            this->numeroDeConta = numeroDeConta;
        }

        void setDonoDaConta (Usuario * dono)
        {
            this->dono = dono;
        }

        ///O M�todo tem a fun��o de buscar o atributo **codigoDeBanco** da classe Conta, salvo a partir da atribui��o do objeto da classe CodigoDeBanco.
        ///Retorna o atributo **codigoDeBanco** da classe Conta.
        CodigoDeBanco getCodigoDeBanco()
        {
            return codigoDeBanco;
        }

        ///O M�todo tem a fun��o de buscar o atributo **numeroDeAgencia** da classe Conta, salvo a partir da atribui��o do objeto da classe NumeroDeAgencia.
        ///Retorna o atributo **numeroDeAgencia** da classe Conta.
        NumeroDeAgencia getNumeroDeAgencia()
        {
            return numeroDeAgencia;
        }

        ///O M�todo tem a fun��o de buscar o atributo **numeroDeConta** da classe Conta, salvo a partir da atribui��o do objeto da classe NumeroDeConta.
        ///Retorna o atributo **numeroDeConta** da classe Conta.
        NumeroDeConta getNumeroDeConta()
        {
            return numeroDeConta;
        }

        Usuario * getDonoDaConta ()
        {
            return dono;
        }
};
