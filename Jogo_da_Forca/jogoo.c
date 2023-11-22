#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS_FACIL 8
#define MAX_TENTATIVAS_MEDIO 6
#define MAX_TENTATIVAS_DIFICIL 4
#define NUM_PALAVRAS 5

char* palavras[NUM_PALAVRAS] = {"PROGRAMACAO", "COMPUTADOR", "LINGUAGEM", "DESENVOLVIMENTO", "ALGORITMO"};

void inicializarForca(char* palavraSecreta, char* letrasReveladas) {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (palavraSecreta[i] == ' ')
            letrasReveladas[i] = ' ';
        else
            letrasReveladas[i] = '_';
    }
    letrasReveladas[strlen(palavraSecreta)] = '\0';
}

void exibirForca(char* letrasReveladas, int tentativas, int maxTentativas) {
    printf("Palavra: %s\n", letrasReveladas);
    printf("Tentativas restantes: %d/%d\n", maxTentativas - tentativas, maxTentativas);
}

int letraEstaNaPalavra(char letra, char* palavraSecreta, char* letrasReveladas) {
    int encontrada = 0;
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (palavraSecreta[i] == letra) {
            letrasReveladas[i] = letra;
            encontrada = 1;
        }
    }
    return encontrada;
}

int main() {
    srand(time(NULL));

    char palavraSecreta[20];
    char letrasReveladas[20];
    char letra;
    int tentativas;
    int opcao;
    int maxTentativas;

    do {
        int ok =system("clear");

        printf("\nMENU:\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Ranking\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        ok = scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ok = system("clear");

                printf("\nNÍVEIS DE DIFICULDADE:\n");
                printf("1 - Fácil\n");
                printf("2 - Médio\n");
                printf("3 - Difícil\n");
                printf("Escolha o nível de dificuldade: ");
                int nivel;
                ok = scanf("%d", &nivel);

                switch (nivel) {
                    case 1:
                        maxTentativas = MAX_TENTATIVAS_FACIL;
                        break;
                    case 2:
                        maxTentativas = MAX_TENTATIVAS_MEDIO;
                        break;
                    case 3:
                        maxTentativas = MAX_TENTATIVAS_DIFICIL;
                        break;
                    default:
                        printf("Opção inválida. Voltando ao menu.\n");
                        continue;
                }

                tentativas = 0;
                strcpy(palavraSecreta, palavras[rand() % NUM_PALAVRAS]);
                inicializarForca(palavraSecreta, letrasReveladas);

                while (1) {
                    ok = system("clear");

                    exibirForca(letrasReveladas, tentativas, maxTentativas);

                    printf("Digite uma letra: ");
                    ok = scanf(" %c", &letra);
                    getchar();
                  
                    letra = toupper(letra);  // Converter para maiúscula

                    if (!isalpha(letra)) {
                        printf("Por favor, digite uma letra válida.\n");
                        continue;
                    }

                    if (!letraEstaNaPalavra(letra, palavraSecreta, letrasReveladas)) {
                        tentativas++;
                    }

                    if (strcmp(palavraSecreta, letrasReveladas) == 0) {
                        ok = system("clear");
                        exibirForca(letrasReveladas, tentativas, maxTentativas);
                        printf("Parabéns! Você acertou a palavra: %s\n", palavraSecreta);
                      getchar();
                        break;
                    }

                    if (tentativas == maxTentativas) {
                        ok = system("clear");
                        printf("Você perdeu! A palavra era: %s\n", palavraSecreta);
                      getchar();
                        break;
                    }
                }
                break;
            case 2:
              ok = system("clear");
              printf("Ranking:\n");
              printf("1 - Jogador 1: XXX pontos\n");
              printf("2 - Jogador 2: XXX pontos\n");
              printf("3 - Jogador 3: XXX pontos\n");
              printf("4 - Sair\n");
              break;
                printf("Saindo do jogo.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
          case 3:
            printf("Saindo do jogo.\n");
            break;
        }

    } while (opcao != 2);

    return 0;
}

