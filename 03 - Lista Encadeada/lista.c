#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int dado;              // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

typedef struct elemento Nodo;
Nodo n;
Nodo *p;

typedef Nodo *Lista;

Lista criaLista(){
    return NULL;
}

Lista insereLista(Lista l, int e){
    Lista p, ant, novo;
    novo = malloc(sizeof(struct elemento)); // Aloca o espaço e faz as atribuições de valores
    novo -> dado = e; // Procura o ponto de inserção na lista
    p=l;
    ant=p;
    while ((p != NULL) && (p->dado < e)) {
        ant = p;
        p = p->prox;
    }
    if (p != ant) { // Não vai inserir antes do primeiro, insere entre ant e p
        ant->prox = novo;
    }
    else { // Lista vazia ou inserindo antes do primeiro elemento
        l = novo;
    }
    novo->prox = p;
    return l;
}

Lista retiraLista(Lista l, int e){
    Lista p, // Ponteiro p para o elemento atual
        ant; // Ponteiro ant para o elemento anterior
    p = l;
    ant = l;
    // Procura o elemento e até o fim da lista ou encontrá-lo
    while ((p != NULL) && (p->dado != e)){ // Procura o elemento e
        ant = p;
        p = p->prox;
    }
    if (p != NULL){    // Encontrou o elemento e. Remove
        if (p == ant){ // Removendo primeiro elemento
            l = p->prox;
            free(p);
        }
        else{ // Não é o primeiro elemento da lista
            ant->prox = p->prox;
            free(p);
        }
    }
    return (l);
}
int contaLista(Lista l){
    Lista p;
    int cont = 0; // inicia o contador com 0
    p = l;        // aponta p para o início da lista
    while (p != NULL){  // enquando não acabou a lista
        cont++;         // incrementa o contador
        p = p->prox;    // passa para o próximo elemento
    }
    return cont; // retorna o contador
}

void imprimeLista(Lista l){
    Lista p; // Ponteiro auxiliar, para percorrer a lista
    printf("\nItens da lista\n");
    p = l; // Fazer p apontar para o início da lista
    while (p != NULL){            // Enquanto não chegar ao final da lista
        printf("%d - ", p->dado); // Imprime o elemento
        p = p->prox;              // Avança o ponteiro para o próximo nodo
    }
    printf("\n"); // Avança para a próxima linha
}

Lista buscaLista(Lista l, int e){
    Lista p; // Ponteiro para percorrer a lista
    p = l;   // Faz o ponteiro apontar para o início da lista
    // Percorre a lista enquanto não chegar ao final da lista
    // e não encontrar o elemento
    while ((p != NULL) && (p->dado != e)){
        p = p->prox;
    }
    return (p); // Retorna o endereço do nodo encontrado
    // ou NULL caso tenha chegado ao final sem
    // encontrar o elemento e na lista.
}

int menu(){
    int opc;
    do{
        printf("- - - Menu - - -\n");
        printf("[1] Inserir elemento\n");
        printf("[2] Remover elemento\n");
        printf("[3] Contar elementos\n");
        printf("[4] Buscar elemento\n");
        printf("[5] Imprimir lista\n");
        printf("[0] Sair\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opc);
        getchar();
        if(opc < 0 || opc > 5){
            printf("Entrada invalida");
        }

    }while(opc < 0 || opc > 5);
    return opc;
}

int main(){
    int opc, valor, qtd;
    Lista l1;
    criaLista();

    printf("Lista Encadeada\n");
    do{
        opc = menu();
        switch (opc){
            case 1:
                printf("Inserir o item a ser adicionado: ");
                scanf("%d", &valor);
                insereLista(l1, valor);
                break;

            case 2:
                printf("Inserir o item a ser removido: ");
                scanf("%d", &valor);
                retiraLista(l1, valor);
                break;

            case 3:
                qtd = contaLista(l1);
                printf("\nA quantidade de itens é: %d", qtd);
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
                printf("Saindo.....");
                break; 

            

        }
    }while(opc != 0);

return 0; }