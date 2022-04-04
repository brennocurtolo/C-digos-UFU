#ifndef FONTE2_H_INCLUDED
#define FONTE2_H_INCLUDED

typedef struct no* lista;

lista cria_lista ();
int lista_vazia (lista li);
int insere_elem (lista* li, int elem);
int remove_elem (lista* li, int elem);
int get_elem_pos(lista li, int pos, int* elem);
int esvazia_lista (lista* li);
int apaga_lista (lista* li);

#endif // FONTE2_H_INCLUDED
