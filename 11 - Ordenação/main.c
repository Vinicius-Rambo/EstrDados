#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 

#define TAM 100000
//Estava querendo testar como funciona a modularização no C, por isso fiz esses outros dois arquivos

//Verifica se número já existe
void vetorAleatorio(int *dados, int tam){
    for(int i = tam - 1; i > 0; i--){
        int j = rand() % (i + 1); //Posição aleatória
        int temp = dados[i];      //Guarda valor
        dados[i] = dados[j];      //Troca
        dados[j] = temp;          //Finaliza troca
    }
}

//Preenche com números aleatórios únicos
int inserirVetor(int *dados, int tam){
    for(int i = 0; i < tam; i++){ 
        dados[i] = i + 1; //Preenche crescente
    } 
    vetorAleatorio(dados, tam); //Embaralha valores
    return *(dados);
}

//Mostra vetor (debug)
void mostrarVetor(int *dados, int tam){
    for(int i = 0; i < tam; i++){
        printf("[%d]\n", dados[i]);
    }
}

int menu(){

    int opc;
    do{
        printf("\n- - - Menu - - -\n");
        printf("[1] - Mostrar valores do vetor\n");
        printf("[2] - Tempo por QuickSortSort\n");
        printf("[3] - Tempo por MergeSort\n");
        printf("[4] - Tempo por BubbleSortt\n");
        printf("[5] - Todos os tempos\n");
        printf("[0] - Sair\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opc);
        if (opc <0 || opc > 5) {
            printf("Entrada invalida\n");
        }

    }while(opc < 0 || opc > 5);

    return opc;
}

int main(){
    int tam, opcao;
    
    //Variaveis para o cronometro
    clock_t ini, fim;
    double tempo; 

    srand(time(NULL)); //Seed, de vetor sempre diferente 
    
    printf("- - - Ordenações - - -\n");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    if(tam < 1 || tam > TAM){
        printf("Tamanho inválido!\n");
        return 1;
    }

    //Vetores estáticos (VLA)
    int dados[tam], bub[tam], mer[tam], aux[tam], qui[tam];
    *dados = inserirVetor(dados, tam);
    
    //Copia os valores aleatórios para cada vetor
    for(int i = 0; i < tam; i++){
        bub[i] = dados[i];
        mer[i] = dados[i];
        qui[i] = dados[i];
    }

    do{
        opcao = menu();
        system("clear");
        switch (opcao) {  
            
            case 1:
                mostrarVetor(dados, tam);
                break;
            
            case 2: 
                ini = clock();
                quickSort(qui, 0, tam - 1);
                fim = clock();
                tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("QuickSort : %f s\n", tempo);
                break;

            case 3:
                ini = clock();
                mergeSort(mer, aux, 0, tam - 1);
                fim = clock();
                tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("Merge     : %f s\n", tempo);
                break;
            
            case 4:
                ini = clock();
                bubbleSort(bub, tam);
                fim = clock();
                tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("Bubble    : %f s\n", tempo);
                break;
            
            case 5: 
                ini = clock();
                quickSort(qui, 0, tam - 1);
                fim = clock();
                tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("QuickSort : %f s\n", tempo);
                
                ini = clock();
                mergeSort(mer, aux, 0, tam - 1);
                fim = clock();
                tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("Merge     : %f s\n", tempo);
                
                ini = clock();
                bubbleSort(bub, tam);
                fim = clock();
                tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
                printf("Bubble    : %f s\n", tempo);
                break;
            
            default: 
                printf("Bye... \n");
                break;
        }
    }while (opcao != 0); 
    return 0;
  
  }
