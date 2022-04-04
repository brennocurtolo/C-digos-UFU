#include <stdio.h>
#include <stdlib.h>

#include "fonte2.h"

void imprime(lista li);

int main()
{
    int maximo = 0, n = 0;
    lista li;
    int x;
    int elem;

    while(maximo != 7){

        printf("\n");
        printf(" 1 - Criar uma lista\n");
        printf(" 2 - Inserir uma string na lista\n");
        printf(" 3 - Remover uma string da lista\n");
        printf(" 4 - Imprimir Lista\n");
        printf(" 5 - Limpar Lista\n");
        printf(" 6 - Apagar Lista\n");
        printf(" 7 - Sair\n");
        printf("\n");

        scanf("%d", &n);
        setbuf(stdin, NULL);

        switch(n){
           case 1:
               li = cria_lista();
                if(li == NULL)
                    printf("A lista foi criada!\n");
                else
                    printf("A lista nao foi criada!\n");
                break;
            case 2:
                printf ("Digite um inteiro:\n");
                scanf("%d", &elem);
                insere_elem(&li, elem);
                break;
            case 3:
                printf ("Qual elemento deseja remover?\n");
                scanf("%d", &elem);
                remove_elem (&li, elem);
                break;
            case 4:
                imprime(li);
                break;
            case 5:
                esvazia_lista(&li);
                if(li == NULL)
                    printf("Lista esvaziada\n");
                else
                    printf("Erro ao esvaziar lista\n");
                break;
            case 6:
                apaga_lista(&li);
                if(li == 0)
                    printf("memoria liberada\n");
                break;
            case 7:
                maximo = 7;
                break;
            default:
                printf("opcao invalida!\n");
        }
    }
    return 0;
}

void imprime(lista li){

    if(lista_vazia(li) == 1){

        printf("\n --Lista Vazia--\n");

    }
    printf("\nLista: ");
    int pos;
    int y;

    for(pos = 1; get_elem_pos(li, pos, &y) == 1; pos++){
        printf(" %d\n", y);
    }

}
