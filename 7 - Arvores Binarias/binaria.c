#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dado;
    struct elemento *esq;
    struct elemento *dir;
};
typedef struct elemento *Arvore; //declaração da Arvore

Arvore criarArvore(){
    return NULL;
}
void inserirArvore(Arvore *a, int valor){

    if((*a) == NULL){
        (*a) = (Arvore)malloc(sizeof(struct elemento));
        (*a) -> dado = valor;
        (*a) ->esq = NULL;
        (*a) ->dir = NULL;
    }
    //se a Arvore não tiver vazia
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

void antecessor(Arvore a, Arvore *x){
    Arvore aux;
    if ((*x)->dir != NULL) {
        antecessor(a, &((*x)->dir));
    }
    else {
        a->dado = (*x)->dado;
        aux = *x;
        *x = aux->esq;
        free(aux);
    }
}

void retiraArvore(Arvore *a, int valor){
    Arvore aux;
    if (*a != NULL) { // Árvore não nula
        if (valor > ((*a)->dado)) { // Retira na sub-árvore da direita
            retiraArvore(&((*a)->dir), valor);
        }else if (valor < ((*a)->dado)) { // Retira na sub-árvore da esquerda
            retiraArvore(&((*a)->esq), valor);
        }else{ // Achou elemento, vai remover
            if ((*a)->dir == NULL) { // Elemento não tem filho da direita,
                aux = (*a);
                *a = aux->esq;
                free(aux);
            }else if ((*a)->esq == NULL) { // Elemento não tem filho da esquerda,
                aux = (*a)->dir; // promove filho da direita
                free(*a);
                *a = aux;
            }else{ // Elemento tem dois filhos, promove o antecessor
                antecessor(*a, &((*a)->esq));
            }
        }
    }
}

Arvore buscaArvore(Arvore a, int valor){
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

void preOrdem(Arvore a){ //Imprimi primeiro as raizes
    if (a != NULL) {
        printf("[%d] - ", a->dado);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void inOrdemAsc(Arvore a){ //Em ordem Crescente
    if (a != NULL){
        inOrdemAsc(a->esq);
        printf("[%d] - ", a->dado);
        inOrdemAsc(a->dir);
    }
}
void inOrdemDesc(Arvore a){ //Em ordem Decrescente
    if (a != NULL){
        inOrdemDesc(a->dir);
        printf("[%d] - ", a->dado);
        inOrdemDesc(a->esq);
    }
}

void posOrdem(Arvore a){
    if (a != NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("[%d] - ", a->dado);
    }
}

int menu(){
    int opc;
    do{
        printf("\n - - - Menu - - -\n");
        printf("[1] - Inserir um elemento na Arvore \n");
        printf("[2] - Buscar um elemento na Arvore  \n");
        printf("[3] - Imprimir em pré-ordem         \n");
        printf("[4] - Imprimir em Ordem crescente   \n");
        printf("[5] - Imprimir em Ordem decrescente \n");
        printf("[6] - Imprimir em Pós-Ordem         \n");
        printf("[7] - Retirar um elemento:          \n");
        printf("[0] Sair                            \n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opc);

        if (opc <0 || opc > 7) {
            printf("Entrada invalida\n");
        }

    }while (opc <0 || opc > 7);

    return opc;
}

int main(){
    int opc, valor;
    Arvore a1; //Declaração da arvore
    a1 = criarArvore();

    do{
        opc = menu();
        system("clear");
        switch (opc){

            case 1:
                printf("Digite o número a ser adicionado na Arvore: ");
                scanf("%d", &valor);
                inserirArvore(&a1, valor);
                break;

            case 2:
                printf("Digite o número a ser buscado: ");
                scanf("%d", &valor);
                valor = buscaArvore(a1, valor);
                if(valor == NULL)
                    printf("Valor não exite na arvore");
                else
                    printf("Valor encontrado na Arvore:");
                break;
                
            case 3:
                preOrdem(a1);
                break;
                
            case 4:
                inOrdemAsc(a1);
                break;

            case 5:
                inOrdemDesc(a1);
                break;

            case 6:
                posOrdem(a1);
                break;
            
            case 7: 
                printf("Digite o número a ser adicionado na Arvore: ");
                scanf("%d", &valor);
                retiraArvore(&a1, valor);
                break;
        
            default:
                printf("Bye ... ");
                break;
        }
    }while(opc != 0);
    return 0;
}

