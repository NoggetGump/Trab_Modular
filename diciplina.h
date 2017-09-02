
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Disciplina
*
*  Arquivo gerado:              disciplina.h
*  Letras identificadoras:      DIS
*
*  Nome da base de software:    
*  Arquivo da base de software: 
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: mrol - Matheus Rodrigues de Oliveira Leal
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   mrol   30/08/2017 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar as diciplinas do sistema acadêmico.
*     Uma disciplina deverá ter um código que a identifica.
*     A cada momento o módulo admite no máximo uma única diciplina.
*     Ao iniciar a execução do programa não existe diciplinas.
*     Uma disciplina deverá ter um critério de avaliação, que será um código que se *refere a uma forma de calcular a média final para poder determinar se um aluno *está aprovado ou não.
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

/***********************************************************************
*
*  $TC Tipo de dados: DIS Descritor de diciplina
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma disciplina
*
***********************************************************************/

struct diciplina{
  char *nome;
  char *codigo;
  int creditos;
  char *bibliografia;
};
typedef struct disciplina* Disciplina;

/***********************************************************************
*
*  $TC Tipo de dados: DIS Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         DIS_CondRetOK = 0 ,
               /* Executou correto */

         DIS_CondRetErroEstrutura = 1 ,
              /* Estrutura da diciplina está errada */

         DIS_CondRetFaltouMemoria = 8
               /* Faltou memória ao alocar dados */

   }DIS_tpCondRet;

/***********************************************************************
*
*  $FC Função: DIS obter nome
*
*  $ED Descrição da função
*    Recebe uma disciplina e retorna o seu nome.
*
***********************************************************************/
DIS_tpCondRet DIS_get_nome(Disciplina d, char* nome);
