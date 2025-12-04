#include "sort.h" //Assinatura do sort.h
#define troca(A, B) { int t = A; A = B; B = t; } //troca do quickSort

//Bubble sort
void bubbleSort(int *vet, int n){
    int i, j, trocou, aux;
    j = 1;
    trocou = 1; //Se houve trocas é teve algo fora de ordem..

    while((j < n) && trocou){ //Enquanto tiver trocas e o vetor for incompleto
        trocou = 0; //Não houve trocas

        for (i = 0; i < (n - j); i++){
            if(vet[i] > vet[i + 1]){ // Se o elemento for maior que o proximo
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                trocou = 1; //Houve uma troca.
            }
        }
        j++; //Próxima passada
    }
}

//Merge Sort
void merge(int *vet, int *aux, int esq, int meio, int dir) {
    int l1, l2, i;

    for(l1 = esq, l2 = meio + 1, i = esq; l1 <= meio && l2 <= dir; i++) {
        if(vet[l1] <= vet[l2])
            aux[i] = vet[l1++]; //Copia da esquerda
        else
            aux[i] = vet[l2++]; //Copia da direita
    }

    while(l1 <= meio) aux[i++] = vet[l1++]; //Resto da esquerda
    while(l2 <= dir)  aux[i++] = vet[l2++]; //Resto da direita
    
    for(i = esq; i <= dir; i++)
        vet[i] = aux[i]; //Copia tudo de volta
}

void mergeSort(int *vet, int *aux, int esq, int dir) {
    if(esq < dir){ //Se ainda pode dividir
        int meio = (esq + dir) / 2;

        mergeSort(vet, aux, esq, meio);     // Esquerda
        mergeSort(vet, aux, meio+1, dir);   // Direita
        merge(vet, aux, esq, meio, dir);    // Junta
    }
}

//Quick sort


int particione(int a[], int p, int r){
    int i = p - 1, j = r;
    int v = a[r]; //Pivot

    for(;;){
        while(a[++i] < v); //Avança i
        while(v < a[--j])  //Volta j
            if(j == p) break;

        if(i >= j) break; //Se cruzou, para

        troca(a[i], a[j]); //Troca
    }

    troca(a[i], a[r]); //Coloca pivot no lugar
    return i; //Retorna posição final do pivot
}

void quickSort(int a[], int p, int r){
    if(p < r){ //Ainda dá pra dividir
        int i = particione(a, p, r); //Particiona
        quickSort(a, p, i - 1); //Esquerda
        quickSort(a, i + 1, r); //Direita
    }
}
