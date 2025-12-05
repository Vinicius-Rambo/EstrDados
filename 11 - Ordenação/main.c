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

int main(){
    int tam;
    
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

    mostrarVetor(dados, tam);

    //Copia os valores aleatórios para cada vetor
    for(int i = 0; i < tam; i++){
        bub[i] = dados[i];
        mer[i] = dados[i];
        qui[i] = dados[i];
    }
    
    //MergeSort
    ini = clock();
    mergeSort(mer, aux, 0, tam - 1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Merge     : %f s\n", tempo);

    // QuickSort 
    ini = clock();
    quickSort(qui, 0, tam - 1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("QuickSort : %f s\n", tempo);

    //BubbleSort
    ini = clock();
    bubbleSort(bub, tam);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("Bubble    : %f s\n", tempo);
    
    return 0;
}
