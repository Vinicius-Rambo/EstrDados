#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define ALUNOS 4 //Maximo de alunos
#define TURMAS 2 //Maximo de turmas

//Estrutura dos alunos
struct Taluno{
    char nome[100];
    char situacao[10];
    int matricula;
    int faltas;
    float media;
    float nota1;
    float nota2;
};

//Estrutura de uma turma
struct Tturma{
    struct Taluno turma[ALUNOS]; //Aluno dentro de turma.
    int numTurma;
    char letraTurma;
    int qtdAlunos;
};

struct Tturma turmas[TURMAS]; // Variavel da turma.
int qtdTurmas = 0;

void criarTurma(){ //Funcao de nova turma
    if(qtdTurmas >= TURMAS){ 
        printf("\nNúmero maximo de turmas atingido"); 
        return;
    }

    printf("zn- - - Criar uma turma: - - -");
    printf("Informe o número da turma: ");
    scanf("%d", &turmas[qtdTurmas].numTurma);
    printf("Informe a letra da turma: ");
    scanf(" %c", &turmas[qtdTurmas].letraTurma);
    
    turmas[qtdTurmas].qtdAlunos = 0; //Começa sem alunos.
    qtdTurmas++;

    printf("\nTurma criada com sucesso, %d espaços totais", 10 - qtdTurmas);
}

void mostrarTurmas(){ //Func. mostrar turmas.
    if(qtdTurmas == 0){
        printf("Digite uma turma antes!!");
        return;
    }
    printf("\n - - - Lista de turmas - - -\n");
    for(int i = 0; i < qtdTurmas; i++){
        printf("[%d] %dº %c - Alunos: %d\n", i, turmas[i].numTurma, turmas[i].letraTurma, turmas[i].qtdAlunos);
    }
}

void inserirAlunosTurma(){//Func. de inserir alunos
    int indice, numCadastro, i;
    if (qtdTurmas == 0){ // Se já ouver turma
        printf("\nNenhuma turma cadastrada! crie uma antes\n");
        criarTurma();
    }
    
    mostrarTurmas(); //Chama a func, anterior de mostrar turmas.
    printf("Digite a turma que deseja cadastrar: ");
    scanf("%d", &indice);

    if(indice < 0 || indice >=qtdTurmas) { //Verifica se a turma é valida
        printf("\nERRO: turma invalida!\n");
        return;
    }

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &numCadastro);

    if (numCadastro + turmas[indice].qtdAlunos > ALUNOS){
        printf("\nERRO: essa turma só pode ter no maximo %d alunos\n", ALUNOS);
        return;
    }

    for(i = 0; i < numCadastro; i++){
        int pos = turmas[indice].qtdAlunos;

        //Inserção de nome
        printf("\n--- %dº aluno ---\n", pos + 1);
        getchar(); //Limpa o buffer
        printf("Nome: ");
        fgets(turmas[indice].turma[pos].nome, 100, stdin);
        turmas[indice].turma[pos].nome[strcspn(turmas[indice].turma[pos].nome, "\n")] = '\0'; //Forma de retirar o \n do final famoso encosto
        
        //Inserções
        printf("Matricula: ");
        scanf("%d", &turmas[indice].turma[pos].matricula);
        
        printf("Faltas: ");
        scanf("%d", &turmas[indice].turma[pos].faltas);

        printf("Nota1: ");
        scanf("%f", &turmas[indice].turma[pos].nota1);

        printf("Nota2: ");
        scanf("%f", &turmas[indice].turma[pos].nota2);
        
        //Calculo de media
        turmas[indice].turma[pos].media = (turmas[indice].turma[pos].nota1 + turmas[indice].turma[pos].nota2) / 2;
      
        //Situação do aluno
        if(turmas[indice].turma[pos].media >= 6.0 && turmas[indice].turma[pos].faltas <= 20){ 
            strcpy(turmas[indice].turma[pos].situacao, "Aprovado");
        }else {
            strcpy(turmas[indice].turma[pos].situacao, "Reprovado");
        }
        
        turmas[indice].qtdAlunos++;
    }
    printf("\nAlunos cadastrados");
}

void exibirAlunos(){ //Func. de exibir dados
    int t, i; //Contador
    if(qtdTurmas == 0){
        printf("\nNenhuma turma cadastrada\n");
        return;
    }

    for(int t = 0; t < qtdTurmas; t++){

        printf(" - - - Turma %dº%c", turmas[t].numTurma, turmas[t].letraTurma);

        if(turmas[t].qtdAlunos ==0){
            printf("Turma [%dº%c]sem alunos. \n\n", turmas[t].numTurma, turmas[t].letraTurma);   
        }
        for (i = 0; i < turmas[t].qtdAlunos;i++){
            printf("\n--- %dº aluno ---\n", i + 1);
            printf("Nome: %s\n", turmas[t].turma[i].nome);
            printf("Matrícula: %d\n", turmas[t].turma[i].matricula);
            printf("Nota 1: %.1f\n", turmas[t].turma[i].nota1);
            printf("Nota 2: %.1f\n", turmas[t].turma[i].nota2);
            printf("Média: %.1f\n", turmas[t].turma[i].media);
            printf("Faltas: %d\n", turmas[t].turma[i].faltas);
            printf("Situação: %s\n", turmas[t].turma[i].situacao);
        }
    }
}

void salvarDados(){ //Func. de salvar dados em um binario
    FILE *arq = fopen("registro.bin", "wb+"); //Abre o arquivo em modo escrita. usando um ponteiro.
    if(!arq){ //Se não abri o arquivo
        printf("\nErro ao abrir seu arquivo!\n");
        return; //Retorna com erro
    }
    fwrite(&qtdTurmas, sizeof(int), 1, arq); //Salva a quantidade de turmas
    fwrite(&turmas, sizeof(struct Tturma), qtdTurmas, arq); 
    fclose(arq); //Fecha o arquivo

    printf("\nDados salvos em 'registro.bin'!\n");
}

void carregarDados() { //Func de carregar esses dadis
    FILE *arq = fopen("registro.bin", "rb"); //Abre o arquivo em modo leitura
    if (!arq) { //Se não houver arquivo
        printf("\nNenhum arquivo encontrado!\n"); 
        return 1;
    }

    fread(&qtdTurmas, sizeof(int), 1, arq);
    fread(turmas, sizeof(struct Tturma), qtdTurmas, arq);
    fclose(arq);

    printf("\nDados carregados de 'registro.bin'!\n");
}

// Parte principal
int main(){
    int opcao;

    do{
        printf("\n- - - Menu - - -\n");
        printf("1 - Criar turma\n");
        printf("2 - Mostrar turmas\n");
        printf("3 - Inserir alunos em uma turma\n");
        printf("4 - Exibir todos os alunos\n");
        printf("5 - Salvar dados\n");
        printf("6 - Carregar dados\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1: criarTurma(); break;
            case 2: mostrarTurmas(); break;
            case 3: inserirAlunosTurma(); break;
            case 4: exibirAlunos();break;
            case 5: salvarDados(); break;
            case 6: carregarDados(); break;
            case 0: printf("\n\nSaindo.....\n"); break;
            default: printf("\nOpção invalida, tente novamente\n");
        }
    }while(opcao != 0);

 return 0;
}