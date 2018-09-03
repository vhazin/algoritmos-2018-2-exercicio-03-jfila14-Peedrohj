#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int id;
    struct elemento* proximo;
} Elemento;

typedef struct lista{
    int tamanho;
    Elemento* inicio;
    Elemento* final;
} Lista;

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(lista));
    
    lista->tamanho = 0;
    lista->inicio = NULL;
    
    return lista;
}

void inserir(Lista* lista, int info){
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->id = info;

    if(lista->tamanho == 0){
        lista->inicio = novo;
        lista->final = novo;
        novo->proximo = NULL;
        lista->tamanho++;
    }else{
        lista->final->proximo = novo;
        lista->final = novo;
        novo->proximo = NULL;
        lista->tamanho++;
    } 
}

void retirar(Lista* lista, int valor){
    Elemento* pointer = lista -> inicio;
    Elemento* anterior = NULL;
    
    while(pointer != NULL){
        if(pointer->id == valor){
            if(anterior == NULL){
                lista->inicio = pointer->proximo;
                free(pointer);
                lista->tamanho--;
            }else {
                anterior->proximo = pointer->proximo;
                free(pointer);
                lista->tamanho--;
            }
        break;
        }
        anterior = pointer;
        pointer = pointer->proximo;
    }
}

void printLista(Lista* lista){
    Elemento* pointer = lista->inicio;

    while(pointer != NULL){
        printf("%d ", pointer->id);
        pointer = pointer->proximo;
    }
}
int main(){
    int in, out, element;
    Lista* lista = criarLista();

    scanf("%d", &in);

    while(in--){
        scanf("%d", &element);
        inserir(lista, element);
    }

    scanf("%d", &out);

    while(out--){
        scanf("%d", &element);
        retirar(lista, element);
    }

    printLista(lista);
}