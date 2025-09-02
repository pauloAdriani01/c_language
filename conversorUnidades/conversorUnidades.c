#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double calculo(int escolha);

double calculoDistancia();
double calculoTempo();
double calculoTemperatura();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    char decisao = 'S';
    int escolha;
    double resultado;

    while(decisao ==  'S' || decisao == 's' ) {
        printf("CONVERSOR DE MEDIDAS\n");
        printf("Que tipo de cálculo você gostaria de realizar?\n\n");

        printf("1 --> Distância\n");
        printf("2 --> Tempo\n");
        printf("3 --> Temperatura\n");
        scanf("%d", &escolha);

        resultado = calculo(escolha);

        printf("\nResultado da sua operação: %.4lf", resultado);

        printf("\n\nGostaria de realizar outro cálculo? (S/N)\n");
        scanf(" %c", &decisao);

        if(decisao == 'N' || decisao == 'n') {
            printf("\nOperação finalizada.");
        }
        else if(decisao != 'S' && decisao != 's') {
            printf("\n[ERRO] Caracter inválido");
        }

    }

    return 0;
}

double calculo(int escolha) {
    double resultado;

    switch(escolha) {
        case 1:
            printf("\nCálculo de Distância Escolhido.\n\n");

            resultado = calculoDistancia();

            break;
        case 2:
            printf("\nCálculo de Tempo Escolhido.\n\n");

            resultado = calculoTempo();

            break;
        case 3:
            printf("\nCálculo de Temperatura Escolhido.\n\n");

             resultado = calculoTemperatura();

            break;
        default:
            printf("\n[ERRO] Escolha inválida.");
            break;
    }

    return resultado;
}

double calculoDistancia() {
    int escolha;
    double num;
    double resultado;

    printf("Qual cálculo você deseja realizar?\n");

    printf("1 --> metro(m) para pé(ft) \n");
    printf("2 --> metro(m) para jarda(yd)\n");
    printf("3 --> metro(m) para milha(mi)\n");
    scanf("%d", &escolha);

    switch(escolha) {
        case 1:
            printf("\nEscolha: metro(m) para pé(ft)\n");

            printf("Metros: ");
            scanf("%lf", &num);

            resultado = num * 3.281;

            break;
        case 2:
            printf("\nEscolha: metro(m) para jarda(yd)\n");

            printf("Metros: ");
            scanf("%lf", &num);

            resultado = num * 1.094;

            break;
        case 3:
            printf("\nEscolha: metro(m) para milha(mi)\n");

            printf("Metros: ");
            scanf("%lf", &num);

            resultado = num / 1609;

            break;
        default:
            printf("\n[ERRO] Escolha inválida.");
            break;
    }

    return resultado;
}

double calculoTempo() {
    int escolha;
    double num;
    double resultado;

    printf("Qual cálculo você deseja realizar?\n");

    printf("1 --> segundo(s) para dia\n");
    printf("2 --> minuto(min) para mês\n");
    printf("3 --> hora(h) para ano\n");
    scanf("%d", &escolha);

    switch(escolha) {
        case 1:
            printf("\nEscolha: segundo(s) para dia\n");

            printf("Segundos: ");
            scanf("%lf", &num);

            resultado = num / 86400;

            break;
        case 2:
            printf("\nEscolha: minuto(min) para mês\n");

            printf("Minutos: ");
            scanf("%lf", &num);

            resultado = num / 43800;

            break;
        case 3:
            printf("\nEscolha: hora(h) para ano\n");

            printf("Horas: ");
            scanf("%lf", &num);

            resultado = num / 8760;

            break;
        default:
            printf("\n[ERRO] Escolha inválida.");
            break;
    }

    return resultado;
}

double calculoTemperatura() {
    int escolha;
    double num;
    double resultado;

    printf("Qual cálculo você deseja realizar?\n");

    printf("1 --> Celsius(°C) para Fahrenheit(°F)\n");
    printf("2 --> Celsius(°C) para Kelvin(K)\n");
    printf("3 --> Fahrenheit(°F) para Celsius(°C)\n");
    scanf("%d", &escolha);

    switch(escolha) {
        case 1:
            printf("\nEscolha: Celsius(°C) para Fahrenheit(°F)\n");

            printf("Celsius: ");
            scanf("%lf", &num);

            resultado = (num * 1.8) + 32;

            break;
        case 2:
            printf("\nEscolha: Celsius(°C) para Kelvin(K)\n");

            printf("Celsius: ");
            scanf("%lf", &num);

            resultado = num + 273.15;

            break;
        case 3:
            printf("\nEscolha: Fahrenheit(°F) para Celsius(°C)\n");

            printf("Fahrenheit: ");
            scanf("%lf", &num);

            resultado = (num - 32) * 5 / 9;

            break;
        default:
            printf("\n[ERRO] Escolha inválida.");
            break;
    }

    return resultado;
}
