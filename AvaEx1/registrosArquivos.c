#include <stdio.h>
#include <string.h>

#define TAM 100 

//Definição Aluno Aluno
struct Taluno{    
    char nome[40];
    int matricula;
    float prova1, prova2, media;
    int faltas;
    char situacao[15];
}aluno;

void inserirAluno(struct Taluno *aluno){
    printf("Digite o nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
}


int main(){


    struct Taluno aluno;
    int n = 0, selecionar;

    printf("Sistema de Cadastro de alunos - - - \n");

    do{
        printf("\nMenu:\n");
        printf("[1] Inserir aluno\n");
        printf("[2] Exibir alunos\n");
        printf("[3] Salvar Dados\n");
        printf("[4] Carregar Dados\n");
        printf("[5] Carregar Dados Json\n");
        printf("[0] Sair do Programa\n");
        printf("Selecione sua opção: \n");
        scanf("%d", &selecionar);
        
        switch(selecionar){

            case 1: break; 
            case 2: break; 
            case 3: break; 
            case 4: break; 
            case 5: break; 
            case 0: printf("Saindo...."); break; //Fechando programa
            default: break;
        }
    }while(selecionar != 0);

    return 0;
}




















