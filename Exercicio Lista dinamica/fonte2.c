#include <stdio.h>
#include <stdlib.h>

#include "fonte2.h"

struct no{
    int info;
    struct no* prox;
};

lista cria_lista (){
    return NULL;
}

int lista_vazia (lista li){
    if (li == NULL)
        return 1;

    else
        return 0;
}
/*
    //Não ordenada

int insere_elem (lista* li, int elem){

    lista li2 = (lista) malloc(sizeof(struct no));

    if (li2 == NULL)
        return 0;

    li2 -> info = elem;
    li2 -> prox = *li;                                      //prox recebe o conteudo do endereço dentro de li (endereço dentro da variavel lista)
    *li = li2;                                              //o conteudo do endereço dentro de li (endereço dentro da variavel lista) agora é o endereço de uma nova struct alocada (o prorio li2)

    return 1;
}
*/

    //Ordenada

int insere_elem (lista* li, int elem){

    lista li2 = (lista) malloc(sizeof(struct no));

    if (li2 == NULL)
        return 0;

    li2 -> info = elem;

    if (lista_vazia(*li) || elem <= (*li) -> info){

        li2 -> prox = *li;                              //aponta para o 1° no atual da lista (ja existente)
        *li = li2;                                      //faz a lista apontar para o novo no

        return 1;
    }

     lista aux = *li;                                   //aux aponta para o primeiro no
     while (aux -> prox != NULL && elem > aux -> prox -> info)
        aux = aux -> prox;

     li2 -> prox = aux -> prox;
     aux -> prox = li2;

     return 1;
}

/*
    //nao ordenada
int remove_elem (lista* li, int elem){

    if (lista_vazia (*li) == 1)
        return 0;

    lista aux = *li;

    if (elem == (*li) -> info){

        *li = aux -> prox;
        free (aux);

        return 1;
    }

    while (aux -> prox != NULL && aux -> prox -> info != elem)
            aux = aux -> prox;

    if (aux -> prox == NULL)
        return 0;

    lista aux2 = aux -> prox;
    aux -> prox =  aux2 -> prox;
    free(aux2);

    return 1;
}
*/

    //Ordenada

int remove_elem (lista* li, int elem){

    if (lista_vazia (*li) == 1 || elem < (*li) -> info)
        return 0;

    lista aux = *li;

    if (elem == (*li) -> info){

        *li = aux -> prox;
        free (aux);

        return 1;
    }

    while (aux -> prox != NULL && aux -> prox -> info < elem)
            aux = aux -> prox;

    if (aux -> prox == NULL || aux -> prox -> info > elem)
        return 0;

    lista aux2 = aux -> prox;
    aux -> prox = aux2 -> prox;
    free(aux2);

    return 1;
}

int esvazia_lista (lista* li){
    if (*li == NULL)
        return 0;

    while (*li != NULL){

        lista aux = *li;
        *li = aux -> prox;
        free(aux);

    }
    return 1;
}

int apaga_lista (lista* li){

    return (esvazia_lista(li));
}

int get_elem_pos(lista li, int pos, int* elem){                           //li (não passa por referencia pois a lista não é alterada em momento nenhum, so estou pegando os elementos)

    if (lista_vazia (li) == 1 || pos <= 0)
        return 0;

    int cont = 1;                                                              //se a lista não é vazia começa-se o contador com 1
    lista aux = li;

     while (aux->prox != NULL && cont < pos)
    {
        aux = aux->prox;
        cont++;
    }

    if (cont != pos)
        return 0;

    *elem = aux -> info;
        return 1;
}


















