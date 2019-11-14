# Trabalho 2 da Disciplina Técnicas de Programação 1 

## Autor: Matheus Costa de Oliveira
## Coautor: Ronald Cesar

### Considerações a respeito da plataforma adotada.

O enunciado do trabalho em questão solicitou o desenvolvimento para a o IDE Code::Blocks para Windows. Por isso, os códigos do sistema estão localizados na Pasta 'ProjetoCodeBlocks'.

Antes de reconstruir (Rebuild) o projeto no Code::Blocks (Windows), alguns procedimentos devem ser adotados.

1- Em Project -> Build options... -> Linker settings, está linkada a biblioteca 'pdcurses.lib'. É recomendao que se muda para um "path" não relativo que leve para a pasta onde o arquivo se encontra (a priori, na pasta principal do projeto)

2- É fundamental que o arquivo 'curses.h' seja copiado para a pasta que gerencia o compilador do Code::Blocks, normalmente chamada de MinGW. Dentro desta, existe uma outra pasta chamada de "include", que é onde o arquivo 'curses.h' deve ser copiado.

3- Uma estratégia alternativa para identificação da biblioteca 'curses' é trocar a inclusão *#include <curses.h>* por *#include "curses.h"* nos arquivos 'main.cpp' e 'SubSistInicializacao/MInit.cpp'.

Caso a plataforma adotada seja Linux, basta rodar o comando 'make' no diretório 'ProjetoCodeBlocks' e executar o arquivo executável por meio do comando './executable'.

### Documentos PDF

A arquitetura do sistema e um Smoke Teste para testá-lo estão disponibilizados nos documentos PDF.



