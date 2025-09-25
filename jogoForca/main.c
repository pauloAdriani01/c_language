#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

void retornaPalavra(char palavra[10], int numeroAleatorio);
bool jogo(char palavra[10]);

bool analiseLetras(char letrasDescobertas[10], char letra, char palavra[10], int numeroLetras);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    char palavra[10] = "";
    int numeroAleatorio = 0;
    int condicaoJogo = 1;
    
    printf("---JOGO DA FORCA NO CONSOLE---\n");

    printf("Tente acertar a palavra!\n\n");
    
    system("pause");

    system("cls");
    
    do { 
        system("cls");

        //Geração de número de acordo com o tempo, para não gerar um número igual
        srand(time(NULL));
        numeroAleatorio = rand() % 50;
        
        retornaPalavra(palavra, numeroAleatorio);
        
        jogo(palavra);
        
        printf("\nObrigado por jogar!\n\n");

        printf("Deseja jogar novamente? (1 - Sim / 0 - Não): ");
        scanf("%d", &condicaoJogo);

        if(condicaoJogo == 0) {
            printf("\nEncerrando o jogo.\n\n");
            break;
        }
        else if (condicaoJogo != 0 && condicaoJogo != 1) {
            printf("\nOpção inválida. Encerrando o jogo.\n\n");
            break;
        }

    } while(condicaoJogo == 1);

    system("pause");
    
    return 0;
}

void retornaPalavra(char palavra[10], int numeroAleatorio) {
    switch(numeroAleatorio) {
        case 0:
            strcpy(palavra, "casa");
            
            break;
            
        case 1:
            strcpy(palavra, "gato");
            
            break;
            
        case 2:
            strcpy(palavra, "livro");
            
            break;
            
        case 3:
            strcpy(palavra, "sol");
            
            break;
            
        case 4:
            strcpy(palavra, "flor");
            
            break;
            
        case 5:
            strcpy(palavra, "mesa");
            
            break;
            
        case 6:
            strcpy(palavra, "bola");
            
            break;
            
        case 7:
            strcpy(palavra, "carro");
            
            break;
            
        case 8:
            strcpy(palavra, "pao");
            
            break;
            
        case 9:
            strcpy(palavra, "rio");
            
            break;
            
        case 10:
            strcpy(palavra, "ceu");
            
            break;
            
        case 11:
            strcpy(palavra, "mar");
            
            break;
            
        case 12:
            strcpy(palavra, "luz");
            
            break;
            
        case 13:
            strcpy(palavra, "cao");
            
            break;
            
        case 14:
            strcpy(palavra, "mao");
            
            break;
            
        case 15:
            strcpy(palavra, "pe");
            
            break;
            
        case 16:
            strcpy(palavra, "olho");
            
            break;
            
        case 17:
            strcpy(palavra, "som");
            
            break;
            
        case 18:
            strcpy(palavra, "cor");
            
            break;
            
        case 19:
            strcpy(palavra, "dia");
            
            break;
            
        case 20:
            strcpy(palavra, "noite");
            
            break;
            
        case 21:
            strcpy(palavra, "fogo");
            
            break;
            
        case 22:
            strcpy(palavra, "ar");
            
            break;
            
        case 23:
            strcpy(palavra, "voz");
            
            break;
            
        case 24:
            strcpy(palavra, "rua");
            
            break;
            
        case 25:
            strcpy(palavra, "leite");
            
            break;
            
        case 26:
            strcpy(palavra, "fruta");
            
            break;
            
        case 27:
            strcpy(palavra, "peixe");
            
            break;
            
        case 28:
            strcpy(palavra, "verde");
            
            break;
            
        case 29:
            strcpy(palavra, "azul");
            
            break;
            
        case 30:
            strcpy(palavra, "doce");
            
            break;
            
        case 31:
            strcpy(palavra, "frio");
            
            break;
            
        case 32:
            strcpy(palavra, "quente");
            
            break;
            
        case 33:
            strcpy(palavra, "vento");
            
            break;
            
        case 34:
            strcpy(palavra, "pedra");
            
            break;
            
        case 35:
            strcpy(palavra, "folha");
            
            break;
            
        case 36:
            strcpy(palavra, "arvore");
            
            break;
            
        case 37:
            strcpy(palavra, "chuva");
            
            break;
            
        case 38:
            strcpy(palavra, "neve");
            
            break;
            
        case 39:
            strcpy(palavra, "areia");
            
            break;
            
        case 40:
            strcpy(palavra, "barco");
            
            break;
            
        case 41:
            strcpy(palavra, "ponte");
            
            break;
            
        case 42:
            strcpy(palavra, "vidro");
            
            break;
            
        case 43:
            strcpy(palavra, "chave");
            
            break;
            
        case 44:
            strcpy(palavra, "rato");
            
            break;
            
        case 45:
            strcpy(palavra, "sapo");
            
            break;
            
        case 46:
            strcpy(palavra, "bola");
            
            break;
            
        case 47:
            strcpy(palavra, "luz");
            
            break;
            
        case 48:
            strcpy(palavra, "mar");
            
            break;
            
        case 49:
            strcpy(palavra, "sol");
            
            break;
            
        default:
            strcpy(palavra, "");
            
            break;
            
    }
}

bool jogo(char palavra[10]) {
    int numeroLetras = strlen(palavra);
    int tentativas = 5;
    
    char letrasDescobertas[10];
    
    //Criação do "descobrimento" da palavra de acordo com o tamanho de caracteres da palavra gerada
    for(int i = 0; i < numeroLetras; i++) {
        letrasDescobertas[i] = '_';
        
    }
    letrasDescobertas[numeroLetras] = '\0';
    
    char escolhaJogador[10];
    
    while(tentativas > 0) {
        printf("\nNúmero de letras na palavra: %d\n", numeroLetras);
        printf("Número de tentativas: %d\n", tentativas);
        printf("Letras descobertas: %s\n", letrasDescobertas);
        printf("\nDigite uma letra ou uma palavra: ");
            
        fgets(escolhaJogador, 10, stdin);
        escolhaJogador[strcspn(escolhaJogador, "\n")] = '\0';
            
        //Passa a informação dada pelo jogador para o minúsculo
        for(int i = 0; i < strlen(escolhaJogador); i++) {
            escolhaJogador[i] = tolower(escolhaJogador[i]);
                
        }
            
        //Confere se o jogador colocou apenas 1 letras
        if(strlen(escolhaJogador) == 1) {
            char letra = escolhaJogador[0];
                
        //Testa caso a letra inserida pelo jogador não estiver na palavra ou estiver na palavra
            if(!analiseLetras(letrasDescobertas, letra, palavra, numeroLetras)) {
                printf("Letra %c não está na palavra!\n", letra);
                            
                tentativas--;
                
            }
            else {
                printf("A letra %c está na palavra!\n", letra);
                            
            }
                
        }
        //Caso o jogador jogue uma palavra
        else {
            if(strcmp(escolhaJogador, palavra) == 0) {
                printf("\nParabéns! Palavra correta!\n");
                printf("Palavra: %s", palavra);
                    
                return false; 
                    
            }
            else {
                printf("Palavra incorreta!\n");
                    
                tentativas--;
                    
            }
                
        }
        
        //Confere se as letras descobertas forma a palavra gerada
        if(strcmp(letrasDescobertas, palavra) == 0) {
            printf("\nParabéns! Palavra correta!\n");
            printf("Palavra: %s", palavra);
            
            return false; 
        }

        system("cls");
        
    }
    
    printf("\nEnforcado! Fim das tentativas!\n");
    printf("A palavra era: %s\n", palavra);
    
    return false;

}

bool analiseLetras(char letrasDescobertas[10], char letra, char palavra[10], int numeroLetras) {
    bool acertou = false;
    
    //Confere se a letra colocada pelo usuario é a correta
    //Em caso positivo, susbtitui um dos _ da string "letrasDescobertas" pela letra em si
    for(int i = 0; i < numeroLetras; i++) {
        if(palavra[i] == letra) {
            letrasDescobertas[i] = letra;
            
            acertou = true;
            
        }
        
    }
    
    return acertou;
    
}