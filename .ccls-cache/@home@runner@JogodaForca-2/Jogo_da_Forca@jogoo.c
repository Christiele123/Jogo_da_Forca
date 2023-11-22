#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main();{

#define MAX_TENTATIVAS 6
#define NUM_PALAVRAS 5

char *palavras[NUM_PALAVRAS] = {"PROGRAMACAO", "COMPUTADOR", "LINGUAGEM",
                                "DESENVOLVIMENTO", "ALGORITMO"};

void inicializarForca(char *palavraSecreta, char *letrasReveladas) {
  int i;
  for (i = 0; i < strlen(palavraSecreta); i++) {
    if (palavraSecreta[i] == ' ')
      letrasReveladas[i] = ' ';
    else
      letrasReveladas[i] = '_';
  }
  letrasReveladas[i] = '\0';
}

void exibirForca(char *letrasReveladas) {
  printf("Palavra: %s\n", letrasReveladas);
}

int letraEstaNaPalavra(char letra, char *palavraSecreta,
                       char *letrasReveladas) {
  int i, encontrada = 0;
  for (i = 0; i < strlen(palavraSecreta); i++) {
    if (palavraSecreta[i] == letra) {
      letrasReveladas[i] = letra;
      encontrada = 1;
    }
  }
  return encontrada;
}

void exibirMenu() {
  printf("\nMENU:\n");
  printf("1 - Novo Jogo\n");
  printf("0 - Sair\n");
}

int main() {
  srand(time(NULL));

  char palavraSecreta[20];
  char letrasReveladas[20];
  char letra;
  int tentativas;

  int opcao;

  do {
    system("clear");
    exibirMenu();

    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      tentativas = 0;
      strcpy(palavraSecreta, palavras[rand() % NUM_PALAVRAS]);
      inicializarForca(palavraSecreta, letrasReveladas);

      while (1) {
        system("clear");

        exibirForca(letrasReveladas);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        letra = toupper(letra); // Converter para maiúscula

        if (!isalpha(letra)) {
          printf("Por favor, digite uma letra válida.\n");
          continue;
        }

        if (!letraEstaNaPalavra(letra, palavraSecreta, letrasReveladas)) {
          tentativas++;
        }

        if (strcmp(palavraSecreta, letrasReveladas) == 0) {
          system("clear");
          exibirForca(letrasReveladas);
          printf("Parabéns! Você acertou a palavra: %s\n", palavraSecreta);
          break;
        }

        if (tentativas == MAX_TENTATIVAS) {
          system("clear");
          printf("Você perdeu! A palavra era: %s\n", palavraSecreta);
          break;
        }
      }
      break;
    case 0:
      printf("Saindo do jogo.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }

  } while (opcao != 0);

  return 0;
}
