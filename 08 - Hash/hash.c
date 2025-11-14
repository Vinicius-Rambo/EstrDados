#include <stdio.h>
#include <stdlib.h>
#define TAM_HASH 10

//Lista encadeada ordenada falada em uma das aulas 

struct elemento {
    int dado;              // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

typedef struct elemento Nodo;
Nodo n;
Nodo *p;
typedef Nodo *Lista;

Lista criaLista() { //Função para criar uma lista vazia
    return NULL;
}

Lista insereLista(Lista l, int e) { //Lista Ordenada
    Lista p, ant, novo;

    novo = malloc(sizeof(struct elemento));
    novo -> dado = e;
    p = l;
    ant = p;
    while((p != NULL) && (p->dado <e)){
        ant = p;
        p = p->prox;
    }
    if (p != ant){
        ant -> prox = novo;
    }
    else {
        l = novo;
    }
    novo -> prox = p;
    return l;
}

Lista retiraLista(Lista l, int e) {
    Lista p, ant; 
    p = l;
    ant = NULL;

    // Procura o elemento e até o fim da lista ou encontra-lo
    while ((p != NULL) && (p->dado != e)) { // Procura o elemento e
        ant = p;
        p = p->prox;
    }

    if (p != NULL) {    // Encontrou o elemento e. Remove
        if (ant == NULL) { // Removendo primeiro elemento
            l = p->prox;
        } else { // Não é o primeiro elemento da lista
            ant->prox = p->prox;
        }
        free(p);
        printf("Elemento %d removido.\n", e);
    } else {
        printf("Elemento %d nao encontrado.\n", e);
    }

    return l;
}

Lista buscaLista(Lista l, int e) {
    Lista p = l;

    while (p != NULL && p->dado != e) {
        p = p->prox;
    }

    if (p != NULL) {
        printf("Elemento encontrado!\n");
    } else {
        printf("Elemento nao encontrado!\n");
    }

    return p;
}

void imprimeLista(Lista l) {
    Lista p; // Ponteiro auxiliar, para percorrer a lista
    printf("\nItens da lista\n");

    p = l; // Fazer p apontar para o inicio da lista
    while (p != NULL) {            // Enquanto não chegar ao final da lista
        printf("[%d] - ", p->dado);  // Imprime o elemento
        p = p->prox;               // Avança o ponteiro para o proximo nodo
    }
    printf("\n"); // Avança para a próxima linha
}

// Codigos do Hash que usam Lista

int hash(int chave){
    return (chave % TAM_HASH);
}

void criaHash(Lista *h){
    int i;
    for (i=0; i<TAM_HASH; i++)
    h[i]=criaLista();
}

void insereHash(Lista *h, int valor){
    int i;
    i = hash(valor);
    h[i] = insereLista(h[i],valor);
}

Lista buscaHash(Lista *h, int valor){
    int i;
    i = hash(valor);
    return (buscaLista(h[i], valor));
}

void retiraHash(Lista *h, int valor){
    int i;
    i = hash(valor);
    h[i] = retiraLista(h[i],valor);
}

void imprimeHash(Lista *h){
    int i;

    printf("\nImprimindo as listas do hash [h]\n");
    for (i=0; i < TAM_HASH; i++){
        printf("\nHash[%d]: ",i);
        imprimeLista(h[i]);
    }
    printf("\n");
}

int menu(){
    int opc;
    do{
        printf("- - - Menu - - -\n");
        printf("[1] - Inserir um elemento no hash\n");
        printf("[2] - Retirar um elemento no hash\n");
        printf("[3] - Buscar um elemento no hash\n");
        printf("[4] - Imprimir todos os elemento no hash\n");
        printf("[0] - Sair\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opc);

        if (opc <0 || opc > 4) {
            printf("Entrada invalida\n");
        }

    }while (opc <0 || opc > 4);
    return opc;
}

int main(){
    int opc, valor;
    Lista h[TAM_HASH];
    criaHash(h);
    do{
        opc = menu();
        system("clear");
        switch (opc){
            case 1: 
                printf("Digite o número a ser adicionado no hash: ");
                scanf("%d", &valor);
                insereHash(h, valor);
            break;
            
            case 2: 
                printf("Digite o número a ser retirado do hash: ");
                scanf("%d", &valor);
                retiraHash(h, valor);
            break;

            case 3: 
                printf("Digite o número a ser buscado no hash: ");
                scanf("%d", &valor);
                buscaHash(h, valor);
            break;

            case 4:
                imprimeHash(h);
            break;

            default:
                printf("Bye ...");
                break;
        }
    }while(opc != 0);
    return 0;
}
