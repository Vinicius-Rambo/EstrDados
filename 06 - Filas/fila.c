#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

//Estrutura de um elemento da fila

struct elemento{
	int dado; //Conteudo inteiro
	struct elemento *prox; //ponteiro para o proximo registr
};

typedef struct elemento *ApElemento;
typedef struct{
	ApElemento ini;
	ApElemento fim;
} Fila;


Fila criaFila(){ //Cria uma fila F, com inicio e fim Nulo
	Fila f;
	f.ini = NULL;
	f.fim = NULL;
	return (f);
}

int filaVazia(Fila f){ //Verifica se a fila é vazia:

	if (f.ini == NULL) //Se o inicio for nulo retorna TRUE 
		return (TRUE);
	else
		return (FALSE);  
}

void imprimeFila(Fila f){
	ApElemento ap;
	printf("\nItens da lista\n");
	ap = f.ini;
	while (ap != NULL){
		printf("%d - ",ap->dado);
		ap = ap->prox;
	}
    printf("\n");
}

Fila insereFila(Fila f, int e){
    ApElemento novo;
    novo = malloc(sizeof(struct elemento)); // Aloca o espaço e faz as atribuições de valores   
    novo -> dado = e;
    novo -> prox = NULL;
    if (filaVazia(f)){
	f.ini = novo;
	f.fim = novo;
    }
    else{
	f.fim->prox = novo;
	f.fim = novo;
    }
    return (f);
}

Fila retiraFila (Fila f, int *e){
    ApElemento ap;

    if (!filaVazia(f)){
        *e = f.ini->dado; // Retorna o valor do elemento que está no inicio da fila
        ap = f.ini; // Salva o endereço do inicio para liberação
        f.ini = f.ini->prox; // Faz o inicio apontar para o segundo elemento
        free(ap); // Libera o espaço ocupado pelo elemento removido
        if (filaVazia(f)) // Se retirou o único elemento, atualiza o fim
            f.fim = NULL;
    }
    else{
        *e = -1;
        printf("\nFila Vazia");
    }
    
    return (f);
}

int menu(){
    int opc;
    do{
        printf("\n - - - Menu - - -\n");
        printf("[1] Adicionar item \n");
        printf("[2] Retirar item \n");
        printf("[3] Imprimir a Fila\n");
        printf("[0] Sair\n");

        printf("Escolha uma das opções: ");
        scanf("%d", &opc);

        if (opc <0 || opc > 3) {
            printf("Entrada invalida\n");
        }
    }while (opc <0 || opc > 3);

    return opc;
}

int main(){
    int opc, valor;
    Fila f1; //Declarando a Fila1
    f1 = criaFila();

    do{
	    opc = menu();
	    //system("clear"); //Limpar o terminal
	    switch(opc){

            case 1:
            printf("Digite o número a ser adicionado na Fila: ");
            scanf("%d", &valor);
            f1 = insereFila(f1, valor);
            break;

            case 2:
            f1 = retiraFila(f1, &valor);
            break;

            case 3:
            printf("Imprimindo toda a fila: \n");
            imprimeFila(f1);
            break;

            default:
            printf("Bye ...");
            break;
	    }
    }while (opc != 0);
    return 0;
}

