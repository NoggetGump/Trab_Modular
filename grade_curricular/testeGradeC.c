/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              testeGradeC.C
*  Letras identificadoras:      TGRADC
*
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Matheus Rodrigues de Oliveira Leal - mrol
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   mrol   23/10/2017 In�cio do desenvolvimento
*       2.00   mrol   24/10/2017 Adicionadas mais fun��es para teste
*
*  $ED Descri��o do m�dulo
*     Este m�dulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo grade curr�cular. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo grade curr�cular:
*
*     "=" <Char> <Char> <Int> <Char> <Char>
*                   - chama a fun��o GRC_cadastra( <Char> <Char> <Int> <Char> <Char> )
*                     Obs. nota��o: <Char> <Int> s�o os valores dos par�metros
*                     que se encontram no comando de teste.
*     "=obtercre" <INT>
*                      - chama a fun��o GRC_consultaCreditos
*     "=obterem" <Char>
*                      - chama a fun��o GRC_consultaEmenta
*     "=obternome"<Char>
*                      - chama a fun��o GRC_consultaNome
*     "=obtercod" <Char>
*                      - chama a fun��o GRC_consultaCodigo
*     "=obterbib" <Char>
*                      - chama a fun��o GRC_consultaBibiliografia
*
***************************************************************************/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include    "tst_espc.h"
#include    "generico.h"
#include    "lerparm.h"
#include    "gradeCurricular.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     GERA_PAR_DIS_CMD   "=geradis"
#define     CONSULTA_CRE       "=obtercre"
#define     CONSULTA_EM        "=obterem"
#define     CONSULTA_NOME      "=obternome"
#define     CONSULTA_COD       "=obtercod"
#define     CONSULTA_BIB       "=obterbib"
#define     INSERE_PRE_REQUISITO "=inserepr"
#define	    REMOVE_PRE_REQUISITO "=removepr"
#define	    BUSCA_CODIGO	 "=buscacod"
#define	    CRIA_GRC	 	 "=criagrc"
#define	    MOSTRA_DIS_GRC	 "=mostradisgrc"
#define	    MOSTRA_GRC	 	 "=mostragrc"
#define	    LIMPA_GRC	         "=limpagrc"
#define	    LIBERA_GRC	         "=liberagrc"
#define	    REMOVE_DIS_GRC	 "=removedisgrc"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TDIS Efetuar opera��es de teste espec�ficas para grade curr�cular
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     grade curr�cular sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      GRC_tpCondRet CondRetObtido  ;
      GRC_tpCondRet CondRetEsperada  ;
                                      /* inicializa para qualquer coisa */



      //char ValorEsperado;
      char ValorDado1Nome[25];
      char ValorDado2Codigo[8];
      int ValorDado3Creditos;
      char ValorDado4Bib[300];
      char ValorDado5Ementa[300];

      int  NumLidos = -1 ;
      char *ValorObtido1;
	  char *ValorEsperado1;
      int ValorEsperado33;
	  int ValorObtido33;


      TST_tpCondRet Ret ;

      /* Testar GRC cadastra discipina por parametros externos */

         if ( strcmp( ComandoTeste , GERA_PAR_DIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ssissi" , &ValorDado1Nome, &ValorDado2Codigo, &ValorDado3Creditos , &ValorDado4Bib, &ValorDado5Ementa , &CondRetEsperada ) ;
            if ( NumLidos != 6 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_cadastra( ValorDado1Nome, ValorDado2Codigo, ValorDado3Creditos, ValorDado4Bib, ValorDado5Ementa ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao gerar disciplina recebendo parametros externos.\n" );

         } /* fim ativa: Testar GRC cadastra disciplina por parametros externos */

      /* Testar GRC consulta de creditos */

         else if ( strcmp( ComandoTeste , CONSULTA_CRE ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &ValorEsperado33 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_consultaCreditos( &ValorObtido33 ) ;

			return TST_CompararInt ( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter creditos.\n" );

         } /* fim ativa: Testar GRC consulta de creditos */

      /* Testar GRC consulta de ementa */

         else if ( strcmp( ComandoTeste , CONSULTA_EM ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" ,  &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_consultaEmenta(&ValorObtido1);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter ementa." );

         } /* fim ativa: Testar GRC consulta de ementa */

      /* Testar GRC consulta de nome */

         else if ( strcmp( ComandoTeste , OBTER_NOME_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_consultaNome( &ValorObtido1  ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter nome.\n" );

         } /* fim ativa: Testar GRC consulta de nome */
	/* Testar GRC consulta de codigo */

         else if ( strcmp( ComandoTeste , CONSULTA_COD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_consultaCodigo( &ValorObtido1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC consulta de codigo */

	/* Testar GRC busca por codigo */
         else if ( strcmp( ComandoTeste , BUSCA_CODIGO ) == 0 )
         {

            NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_buscaPorCodigo( &ValorObtido1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC busca por codigo */

	/* Testar GRC insere todos pre requesito*/
         else if ( strcmp( ComandoTeste , INSERE_PRE_REQUISITO ) == 0 )
         {

            NumLidos = LER_LerParametros( "si", &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_inserePreRequisito( &ValorObtido1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC insere por codigo pre requesito */

	/* Testar GRC remove todos pre requesito*/
         else if ( strcmp( ComandoTeste , REMOVE_PRE_REQUISITO ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_removePreRequisitos() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC remove por codigo pre requesito */

	/* Testar GRC consulta de bibliografia */
         else if ( strcmp( ComandoTeste , CONSULTA_BIB ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" , &ValorEsperado1 ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_consultaBibiliografia( &ValorObtido1 ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter bibliografia.\n" );

         } /* fim ativa: Testar GRC consulta de bibliografia */

	/* Testar GRC cria grade curricular */
         else if ( strcmp( ComandoTeste , CRIA_GRC ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_cria() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC cria grade curricular */

	/* Testar GRC mostra disciplina atual de grade curricular */
         else if ( strcmp( ComandoTeste , MOSTRA_DIS_GRC ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_mostraAtual() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC mostra disciplina atual de grade curricular */

	/* Testar GRC mostra todas as disciplinas de grade curricular */
         else if ( strcmp( ComandoTeste , MOSTRA_GRC ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_mostraTodas() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC mostra todas as disciplinas de grade curricular */

	/* Testar GRC retira disciplina atual de grade curricular */
         else if ( strcmp( ComandoTeste , RETIRA_DIS_GRC ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_retira() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC retira disciplina atual de grade curricular */

	/* Testar GRC limpa disciplina atual de grade curricular */
         else if ( strcmp( ComandoTeste , LIMPA_DIS_GRC ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_limpa() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC limpa disciplina atual de grade curricular */

	/* Testar GRC libera disciplina atual de grade curricular */
         else if ( strcmp( ComandoTeste , LIBERA_GRC ) == 0 )
         {

            NumLidos = LER_LerParametros( "i",&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = GRC_libera() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao tentar obter codigo.\n" );

         } /* fim ativa: Testar GRC libera disciplina atual de grade curricular */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
