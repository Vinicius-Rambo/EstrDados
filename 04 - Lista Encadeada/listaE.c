#include <stdio.h>
#include <stdlib.h>

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

int contaLista(Lista l) {
    Lista p;
    int cont = 0;      // Inicia o contador com 0
    p = l;              // Aponta p para o inicio da lista

    while (p != NULL) { // Enquanto não acabou a lista
        cont++;          // Incrementa o contador
        p = p->prox;     // Passa para o proximo elemento
    }

    return cont;         // Retorna o contador
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
        printf("%d - ", p->dado);  // Imprime o elemento
        p = p->prox;               // Avança o ponteiro para o proximo nodo
    }

    printf("\n"); // Avança para a próxima linha
}

int menu() {
    int opc;

    do {
        printf("- - - Menu - - -\n");
        printf("[1] Inserir elemento\n");
        printf("[2] Remover elemento\n");
        printf("[3] Contar elementos\n");
        printf("[4] Buscar elemento\n");
        printf("[5] Imprimir lista\n");
        printf("[0] Sair\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opc);

        if (opc < 0 || opc > 5) {
            printf("Entrada invalida\n");
        }

    } while (opc < 0 || opc > 5);

    return opc;
}

int main() {
    int opc, valor, qtd;
    Lista l1 = criaLista();

    printf("Lista Encadeada\n");

    do {
        opc = menu();
        system("clear");
        switch (opc) {
            case 1:
                printf("Inserir o número a ser adicionado: ");
                scanf("%d", &valor);
                l1 = insereLista(l1, valor);
                break;

            case 2:
                printf("Inserir o número a ser removido: ");
                scanf("%d", &valor);
                l1 = retiraLista(l1, valor);
                break;

            case 3:
                qtd = contaLista(l1);
                printf("\nA quantidade de itens é: %d\n", qtd);
                break;
            
            case 4:
                printf("Digite o que deseja buscar: ");
                scanf("%d", &valor);
                buscaLista(l1, valor);
                break;

            case 5:
                imprimeLista(l1);
                break;

            default:
                printf("Bye.....\n");
                break;
        }

    } while (opc != 0);

    return 0;
}
