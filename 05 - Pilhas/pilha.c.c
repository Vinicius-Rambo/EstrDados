#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct elemento{
    int dado; // Conteúdo (inteiro)
    struct elemento *prox; // Ponteiro para o próximo registro
};

typedef struct elemento *Pilha;

Pilha criaPilha(){ //Criar Pilha
    return NULL;
}

int pilhaVazia(Pilha p){ //Confere se a pilha está vazia
    if (p == NULL) //Se a pilha for vazia retorna 1
        return (TRUE);

    else
        return (FALSE);
}

Pilha empilha(Pilha p, int e){ //Inserir no primeiro espaço
    Pilha novo;
    novo = malloc(sizeof(struct elemento)); // Aloca o espaço
    novo -> dado = e; // Atribui os dados ao novo elemento
    novo -> prox = p; // O próximo do novo é o topo anterior
    return (novo); // O novo elemento passa a ser o topo
}

Pilha desempilha (Pilha p, int *e){ //Remove no primeiro espaço
    Pilha ap; // apontador auxiliar
    if (!pilhaVazia(p)){ // se a pilha não for vazia
        printf("Removendo o valor da pilha: ");
        *e = p->dado; // Retorna o valor do elemento que está no topo da pilha
        ap = p; // Salva o endereço do topo para liberação    
        p = p->prox;// Faz o topo apontar para o próximo elemento
        free(ap);  //Libera o espaço ocupado pelo elemento removido

    }else{ // A pilha está vazia. Retorna valor -1.
        *e = -1;
        printf("[= Pilha Vazia =] ");
    }
    return (p);
}

void imprimePilha(Pilha p){ //Percorre a pilha dando sua inserção
    Pilha ap; //apontador auxiliar

    ap = p;
    
    if(ap == NULL){
        printf("[= Pilha vazia =]");
    }
    else{
        while (ap != NULL){
            printf(" [%d]\n",ap->dado);
            ap = ap->prox;
        }
    }
    printf("\n");
}

int menu() {
    int opc;

    do {
        printf("\n- - - Menu - - -\n");
        printf("[1] Empilhar item \n");
        printf("[2] Desempilhar Item\n");
        printf("[3] Imprimir a Pilha\n");
        printf("[0] Sair\n");

        printf("Escolha uma das opções: ");
        scanf("%d", &opc);

        if (opc < 0 || opc > 5) {
            printf("Entrada invalida\n");
        }

    } while (opc < 0 || opc > 5);

    return opc;
}

int main(){
    int opc, valor;
    Pilha p1; //Declaração da variával p
    p1 = criaPilha(); //Inicialização da P 

    do{
        opc = menu();
        system("clear");
        switch (opc){

            case 1: 
                printf("Inserir o número a ser adicionado na pilha: ");
                scanf("%d", &valor);
                p1 = empilha(p1, valor);
                break;

            case 2:
                p1 = desempilha(p1, &valor);
                break;

            case 3: 
                printf("Imprimindo a pilha: \n");
                imprimePilha(p1);
                break;

            default:
                printf("Bye .... ");
                break;
        }
    }while (opc != 0);

 return 0;
}