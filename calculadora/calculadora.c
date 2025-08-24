#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int coletaNumeros(int operandos, int numeros[]);
int operacao(int operandos, int numeros[], int resultado);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int operandos = 0, resultado = 0;

    printf("Calculadora em C\n\n");

    printf("Ol�! Com quantos operandos voc� gostaria de realizar o seu c�lculo?\n");
    scanf(" %d", &operandos);

    int numeros[operandos];

    coletaNumeros(operandos, numeros);

    resultado = operacao(operandos, numeros, resultado);

    printf("Resultado da sua opera��o: %d", resultado);

    printf("\n\n");

    system("pause");

    return 0;
}

int coletaNumeros(int operandos, int numeros[]) {
    for(int i = 0; i < operandos; i++) {
        printf("Qual n�mero � o %d�? ", i + 1);
        scanf(" %d", &numeros[i]);
    }
}

int operacao(int operandos, int numeros[], int resultado) {
    char operador = '0';

    printf("\n\nQual opera��o voc� deseja realizar com os seus %d operandos?\n", operandos);
    printf("|------------------|\n");
    printf("+ --> Adi��o");
    printf("\n- --> Subtra��o");
    printf("\n* --> Multiplica��o");
    printf("\n/ --> Divis�o\n");
    printf("|------------------|\n");
    scanf(" %c", &operador);

    printf("\n");

    switch (operador) {
        case '+':
            for(int i = 0; i < operandos; i++) {
                resultado += numeros[i];
            }

            break;
        case '-':
            if(operandos > 2) {
                resultado = numeros[0] - numeros[1];

                for(int i = 2; i < operandos; i++) {
                    resultado = resultado - numeros[i];
                }
            }
            else {
                resultado = numeros[0] - numeros[1];

            }

            break;
        case '*':
            if(operandos > 2) {
                resultado = numeros[0] * numeros[1];

                for(int i = 2; i < operandos; i++) {
                    resultado = resultado * numeros[i];
                }
            }
            else {
                resultado = numeros[0] * numeros[1];

            }

            break;
        case '/':
            //Checagem de "zeros" presentes no array de operandos
            for(int i = 0; i < operandos; i++) {
                if(numeros[i] == 0) {
                    printf("[ERRO]Zero detectado em um dos operandos.\n\n");
                    return 0;
                }
            }

            if(operandos > 2) {
                resultado = numeros[0] / numeros[1];

                for(int i = 2; i < operandos; i++) {
                    resultado = resultado / numeros[i];
                }
            }
            else {
                resultado = numeros[0] / numeros[1];
            }

            break;
        default:
            printf("[ERRO]Operador inv�lido.");
            break;
    }

    return resultado;
}
