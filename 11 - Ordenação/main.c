
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h" 

#define TAM 100000
//Estava querendo testar como funciona a modularização no C, por isso fiz esses outros dois arquivos

//Verifica se número já existe
int existe(int dados[], int tam, int num){
    for(int i = 0; i < tam; i++){
        if(dados[i] == num)
            return 1; //Já existe
    }
    return 0; //Não existe
}

//Preenche com números aleatórios únicos
void preencheVetor(int *dados, int tam){
    int num, t = 0;
    
    for(int i = 0; i < tam; i++){
        num = rand() % (tam * 3); //Numero random
      
        if(existe(dados, t, num)){ //Se já existe
            i--; //Tenta de novo
            continue;
        }

        dados[i] = num; //Adiciona ao vetor
        t++;
    }
}

//Mostra vetor (debug)
void mostrarVetor(int *dados, int tam){
    for(int i = 0; i < tam; i++){
        printf("[%d]", dados[i]);
    }
    printf("\n");
}

int main(){
    int tam;
    
    //Variaveis para o cronometro
    clock_t ini, fim;
    double tempo;  // <-- Faltava ponto e vírgula
    
    printf("- - - Ordenações - - -\n");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    if(tam < 1 || tam > TAM){
        printf("Tamanho inválido!\n");
        return 1;
    }

    //Vetores estáticos (VLA)
    int dados[tam], bub[tam], mer[tam], aux[tam], qui[tam];
    
    srand(time(NULL)); //Seed, de vetor sempre diferente 
    
    preencheVetor(dados, tam); //Preenche vetor
    
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
    printf("Merge : %f s\n", tempo);

    // QuickSort 
    ini = clock();
    quickSort(qui, 0, tam - 1);
    fim = clock();
    tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    printf("QuickSort : %f s\n", tempo);

    //BubbleSort
    //ini = clock();
    //bubbleSort(bub, tam);
    //fim = clock();
    //tempo = (double)(fim - ini) / CLOCKS_PER_SEC;
    //printf("Bubble : %f s\n", tempo);
    
    return 0;
}

