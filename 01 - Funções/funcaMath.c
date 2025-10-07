#include <stdio.h>

float soma(float num1, float num2){
    float soma = num1 + num2;
    return soma;
}

float subtrair(float num1, float num2){
    float subtrair = num1 - num2;
    return subtrair;
}

float multiplicar(float num1, float num2){
    float multiplicar = num1 * num2;
    return multiplicar;
}

float divisao(float num1, float num2){
    float divisao;
    if(num2 == 0){
        printf ("Valor invalido, divisão por zero\n");
        divisao = 0;
    }

    else{
        divisao = num1 / num2;
    }

    return divisao;
}


float calcular(char op, float num1, float num2){
    float resultado;
    switch(op){
        case '+':
            resultado = soma(num1, num2);
            break;

        case '-':
            resultado = subtrair(num1 , num2);
            break;
        
        case '*':
            resultado = multiplicar(num1, num2);
            break;
         
        case '/':
            resultado = divisao(num1, num2);
            break;    

    }
    return resultado;
}

int main(){
    float num1, num2, resultado;
    char op;

    printf("\nCalculadora de 4 operações\n");
    printf("Digite seu 1º valor: ");
    scanf("%f", &num1);

    printf("Digite seu 2º valor: ");
    scanf("%f", &num2);
    printf("informe uma operação");

    do{
        printf("\n[+]\n[-]\n[*]\n[/]\n");
        scanf(" %c", &op);
        if(op != '+' && op != '-' && op != '*' && op != '/'){
            printf("Entrada Invalida"); 
        }

    }while(op != '+' && op != '-' && op != '*' && op != '/');

    resultado = calcular(op, num1, num2);

    printf("O seu resultado é: %.2f", resultado);

return 0;}