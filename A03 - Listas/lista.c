#include <stdio.h>
#include <string.h>
#define MaxItens 10
#define TamItem 20
typedef char tpLista[MaxItens] [TamItem];

void criaLista(tpLista l){ //Lista L
    int i;
    for(i = 0; i < MaxItens;i++){ //Percorre o vetor limpando a lista;
        l[i][0] = '\0';
    }
}

void imprimeLista(tpLista l){ //Mostra a lista inteira percorrendo todas as Strings
    int i;
    printf("\nItens da lista\n");
    for(i=0; i < MaxItens && strlen(l[i]) > 0; i++){ //For problematico caso um item seja excluido da lista não mostrando inteiro
        printf("\n%s", l[i]);
    }
}

int contaLista(tpLista l){
    int i;
    for (i = 0; i < MaxItens && strlen(l[i]) > 0; i++); //Percorre a lista adicionando +1 por item
    return(i); //Retorna a quantidade de itens na lista
}

void insereLista(tpLista l, char *item){
    int i;
    for(i=0; i < MaxItens && strlen(l[i]) > 0; i++); //Percorre até achar o vazio ou a lista estiver cheia (MaxItens)
    if (i < MaxItens){
        strcpy(l[i], item);
        printf("\nItem (%s) inserido com sucesso\n", item);
    }else //Não cabe na lista
        printf("\nLista cheia, não pode inserir");

}
void retiraLista(tpLista l, char *item){
    int i;
    for (i = 0; i < MaxItens && strlen(l[i]) > 0 && (strcmp(l[i], item) != 0); i++); //Pode sair por 3 razões os de baixo verifica
    if (i < MaxItens && (strcmp(l[i], item) == 0)){ //Encontrou o elemento e vai remover
        printf("\nItem (%s) encontrado, removendo\n", item);
        if (i < (MaxItens - 1)){ //Tem outros elementos depois dele, puxa todos para cima.
            for (; i < (MaxItens - 1) && strlen(l[i]) > 0; i++){
                strcpy(l[i], l[i + 1]);
            }    
        }

        l[MaxItens - 1][0] = '\0'; //Zera o ultimo item 
    }
    else // Não encontrou o elemento buscado
        printf("\nItem (%s) não encontrado", item);
}

int main(){
    tpLista l1;
    int opc, qtdItem;
    char item[80];
    criaLista(l1);
    do{
        printf("\n- - - Menu da Lista - - -\n");
        printf("[1] - Inserir na Lista\n");
        printf("[2] - Imprime a Lista\n");
        printf("[3] - Retirar da Lista\n");
        printf("[4] - Quantos itens possui\n");
    
        printf("[0] - Sair\n");
        printf("Escolha sua opção: ");
        scanf(" %d", &opc);
        getchar();

        switch(opc){
            case 1: 
                printf("Digite seu item: ");
                fgets(item, sizeof(item), stdin);
                item[strlen(item)-1] = '\0';
                insereLista(l1, item);
                break;
            
            case 2: imprimeLista(l1); break;
            
            case 3:
                printf("Digite seu item: ");
                fgets(item, 80, stdin);
                item[strlen(item)-1] = '\0';
                retiraLista(l1, item);
                break; 

            case 4:
                qtdItem = contaLista(l1);
                printf("\nSua lista possui: %d itens\n", qtdItem);     
                break;           

            case 0: 
                printf("Saindo....");
                break;    

            default: 
                printf("Valor invalido tente novamente");
                break;
        }    
    }while(opc != 0);
    return 0;
}