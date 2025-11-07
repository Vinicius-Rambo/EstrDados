#include <stdio.h>

struct elemento{
    int dado;
    struct elemento *esq;
    struct elemento *dir;
};
typedef struct elemento *arvore; //declaração da arvore

arvore criarArvore(){
    return NULL;
}
void inserirArvore(arvore *a, int valor){

    if((*a) == NULL){
        (*a) = (arvore)malloc(sizeof(struct elemento));
        (*a) -> dado = valor;
        (*a) ->esq = NULL;
        (*a) ->dir = NULL;
    }
    //se a arvore não tiver vazia
    else if(valor < (*a)-> dado){ 
        inserirArvore((&(*a)->esq), valor); 
    } 

    else if(valor > (*a)-> dado){ 
        inserirArvore((&(*a)->dir), valor); 
    } 

    else{
        printf("Valor já existe!!!\n");
    }
}

arvore buscaArvore(arvore a, int valor){
    if(a==NULL){ //Arvore vazia retorna null 
        return NULL;
    }
    else if (valor < a -> dado){ //Se menor que a raiz, busca à esquerda
        return buscaArvore(a -> esq, valor);
    }

    else if (valor > a -> dado){ //Se maior busca a direita.
        return buscaArvore (a-> dir, valor);
    }
    else //Nem menor, nem maior encontrou o elemento
        return a;
}

void preOrdem(arvore a){ //Imprimi primeiro as raizes
    if (a != NULL) {
        printf("\n%d", a->dado);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void inOrdemAsc(arvore a){ //Em ordem Crescente
    if (a != NULL){
        inOrdemAsc(a->esq);
        printf("\n%d", a-> dado);
        inOrdemAsc(a->dir);
    }
}
void inOrdemDesc(arvore a){ //Em ordem Decrescente
    if (a != NULL){
        inOrdemAsc(a->dir);
        printf("\n%d", a-> dado);
        inOrdemAsc(a->esq);
    }
}

void posOrdem(arvore a){
    if (a != NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("\n%d", a->dado);
    }
}

