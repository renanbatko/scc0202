#ifndef PROJ_H
#define PROJ_H

typedef struct palavraschave kw;
struct palavraschave {
	char word[50];
};


typedef struct celula cell;
struct celula {
	int code;
	char name[50];
	int relevance;
	char url[100];
	kw keyword[10];
	int n_kw;
	cell *next;
};

typedef struct lista list;

/****************************************/
/* NOME: list *create()                 */
/* DESCRICAO: funcao que cria uma lista */
/* RETORNO: ponteiro para lista         */
/****************************************/
list *create();

/*************************************************************/
/* NOME: int sorted_insertion(list *li, cell *c)             */
/* DESCRICAO: insere um elemento na lista, de forma ordenada */
/* PARAMETROS: list *li - ponteiro para a lista              */
/*             cell *c - ponteiro para um novo elemento      */
/* RETORNO: 1 - insercao feita com sucesso                   */
/*          0 - falha na insercao                            */
/*************************************************************/
int sorted_insertion(list *, cell *);

/*********************************************************************/
/* NOME: void insert_kw(list *li, char *new_kw, int keycode)         */
/* DESCRICAO: adiciona uma palavra chave na celula de codigo keycode */
/* PARAMETROS: list *li - ponteiro para a lista                      */
/*             char *new_kw - nova palavra chave                     */
/*             int keycode - codigo do site                          */
/*********************************************************************/
void insert_kw(list *, char *, int);

/*************************************************************/
/* NOME: int remove_site(list *li, int keycode)              */
/* DESCRICAO: remove uma celula da lista                     */
/* PARAMETROS: list *li - ponteiro para a lista              */
/*             int keycode - codigo da celula a ser removida */
/* RETORNO: 1 - remocao feita com sucesso                    */
/*          0 - falha na remocao                             */
/*************************************************************/
int remove_site(list *, int);

/*************************************************************************/
/* NOME: void update_relevance(list *li, int keycode, int new_relevance) */
/* DESCRICAO: atualiza a relevancia de um site                           */
/* PARAMETROS: list *li - ponteiro para a lista                          */
/*             int keycode - codigo do site                              */
/*             int new_relevance - nova relevancia                       */
/*************************************************************************/
void update_relevance(list *, int, int);

/************************************************/
/* NOME: void print_structure(list *li)         */
/* DESCRICAO: imprime o conteudo da lista       */
/* PARAMETROS: list *li - ponteiro para a lista */
/************************************************/
void print_structure(list *);

/***************************************************************/
/* NOME: void search_by_kw(list *li, char *kw)                 */
/* DESCRICAO: pesquisa na lista pela palavra chave informada   */ 
/* PARAMETROS: list *li - ponteiro para a lista                */
/*             char *kw - palavra chave                        */
/***************************************************************/
void search_by_kw(list *, char *);

/*************************************************************/
/* NOME: void suggest_site(list *li, char *kw)               */
/* DESCRICAO: pesquisa na lista pela palavra chave informada */
/*            e pesquisa por outros sites pelas outras       */
/*            palavras chave                                 */ 
/* PARAMETROS: list *li - ponteiro para a lista              */
/*             char *kw - palavra chave                      */
/*************************************************************/
void suggest_site(list *, char *);

/**************************************************/
/* NOME: void destroy(list *li)                   */
/* DESCRICAO: libera a memoria alocada pela lista */
/* PARAMETROS: list *li - ponteiro para a lista   */
/**************************************************/
void destroy(list *);

#endif

