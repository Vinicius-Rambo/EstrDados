#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int buscaSeq(int *vet, int qtd, int valor, int *tentativas){
  int i = 0; //Indice inical 
  int pos = -1;
  
  *tentativas = 0; //Para contar quanto tempo demora:

  while((i < qtd) && (pos == -1 )) { //Indice menor do que o tamanho 
      (*tentativas)++;      
      if (valor == vet[i]){
        pos = i;
      }
      i++;
  }

  return (pos); 
}

int buscaBin(int *vet, int inicio, int fim, int valor, int *tentativas){
    int meio;
    int pos = -1; // posição
    int i = inicio, f = fim; 

    *tentativas = 0; //Para contar quanto tempo demora:
    
    while ((i <= f) && (pos == -1)) { //Enquanto inicio menor que o fim e pos menor que zero.
        (*tentativas)++;
        meio = (i + f)/2; 
        if (valor == vet[meio]){
            pos = meio; 

        }else if (valor > vet[meio]){ //Se o valor for maior que o meio 
            i = meio + 1;             //o proximo vai ser o novo meio

        }else {
            f = meio - 1; //Se valor menor o anterior, novo meio
        }
    }

    return (pos);
}

void inserirOrdenado(int lista[], int *qtd, int valor){
    if(*qtd >= TAM){
      printf("lista cheia \n");
      return; //Finaliza a funçao aqui se for cheia.
    }

    int i = *qtd - 1;
    
    //Desloca para direita enquando for maior 
    while (i >= 0 && lista[i] > valor) {
          lista[i + 1] = lista[i];
          i--;
    }

    //insere na posição correta
    lista[i + 1] = valor;
    (*qtd)++;

}

int main(){
    int seq[TAM], i;
    int qtd = 0, valor;
    int posSeq, posBin; //Variavel para armazenar a posiçao localizada
    int tentSeq, tentBin; //Variavel de tentativas

    for(i = 0; i < TAM; i++){
      printf("Digite seu %d numero: ", i + 1);
      scanf("%d", &valor);
      inserirOrdenado(seq, &qtd, valor);
    }
    
    for(i = 0; i < TAM; i++){
    	printf("%d - ", seq[i]);
    }
    
    printf("\nQual número deseja buscar: ");
    scanf("%d", &valor);
    
    posSeq = buscaSeq(seq, qtd, valor, &tentSeq);
    posBin = buscaBin(seq, 0, qtd - 1, valor, &tentBin);

    if(posSeq != -1){ //Se não achar na sequencial logicamente não acha na binaria, por isso uma unica validação
      printf("\nNúmero %d encontrado na posição %d\n", valor, posSeq);
    } else {
      printf("\nNúmero %d não encontrado\n", valor);
    }
    
    printf("Busca Sequencial: %d tentativas\n", tentSeq);
    printf("Busca Binaria: %d tentativas\n", tentBin);
    
  return 0;
}
