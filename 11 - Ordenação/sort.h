
#ifndef SORT_H     // Evita incluir o arquivo duas vezes
#define SORT_H     // Marca se já foi incluído

void bubbleSort(int *vet, int n);                 // Declara Bubble Sort
void mergeSort(int *vet, int *aux, int esq, int dir); // Declara Merge Sort
void quickSort(int a[], int p, int r);            // Declara Quick Sort

#endif
