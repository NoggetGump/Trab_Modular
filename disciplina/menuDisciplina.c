/***************************************************************************
*
*  $MCI Módulo de definição: Módulo interfaceDisciplina
*
*  Arquivo gerado:              interfaceDisciplina.c
*  Letras identificadoras:      INTD
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: 	mrol - Matheus Rodrigues de Oliveira Leal
*             SaintL - Leonardo Abreu Santos
*	      ngtgmp - Felipe Nogueira de Souza
	          LL - Clayton Lucas Mendes Lima
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*		0.01  ngtgmp   01/10/2017 Inicio do desenvolvimento
*		0.02  ngtgmp   02/10/2017 Funções implementadas e rodando sem defeitos aparentes
*		0.03  ngtgmp   05/10/2017 Mudança de main para função do principal
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "disciplina.h"

typedef enum {
	AcaoErro,         /*Acao Erro*/
        CriaDis,           /* Cria disciplina */
	DestroiDis,        /* Destroi disciplina */
	ExibeDis,          /*Exibe a disciplina*/
	AcaoTerminar = 99  /* Terminar programa */
   } IDIS_Acao ;
   
void MEN_menuDisciplina (void)
{
	Disciplina* d;
	int acao = AcaoErro;
	
	while(1)
	{  /* Selecionar a ação*/
         /* Exibir menu de opcoes*/
            printf("\n\n----------" ) ;
            printf("\n %d Criar Disciplina", CriaDis ) ;
            printf("\n %d Destruir Disciplina" , DestroiDis    ) ;
            printf("\n %d Exibir" , ExibeDis  ) ;
            printf("\n %d Terminar" , AcaoTerminar    ) ;
         /* Validar a opcao fornecida */
            printf( "\n\nEscolha a opcao :  " ) ;
			scanf("%d", &acao);
		switch(acao)
		{
			case CriaDis:
			{
				if(DIS_gera_cmd(&d) == DIS_CondRetDisciplinaCriada)
					printf("Disciplina criada com sucesso");
				else 
					printf("Condicao de retorno anormal, incapaz de criar disciplina.");
				break;
			}
			case DestroiDis:
			{
				if(DIS_deleta_Disciplina (&d) == DIS_CondRetDisciplinaDeletada)
					printf("Disciplina deletada com sucesso");
				else
					printf("Condicao de retorno anormal, incapaz de deletar disciplina.");
				break;
			}
			case ExibeDis:
			{
				if(DIS_exibe(d) == DIS_CondRetOK)
					printf("Disciplina exibida com sucesso");
				else
					printf("Condicao de retorno anormal, incapaz de exibir disciplina.");
				break;
			}
			case AcaoTerminar:
			{
				printf("Encerrando o programa");
				exit(0);
			}
			default:
			{
				printf("Acao incorreta");
				break;
			}
		}
	}
}
