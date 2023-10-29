#include <stdio.h>
#include <stdlib.h>

int main() {
  char opcao = 0;
  float saldo = 0.0f;
  int tentativas = 3, acertos = 0,letras_acertadas = 0, letras_erradas = 3;
  char palavra[10]
  char resposta[10]
  
  
  while (opcao != '0') {
    int deu_certo = system("clear");
    printf("\e[0; 96mJOGO DA FORCA\e[0m\n");
    printf("1 - NOVO JOGO\n");
    printf("2 - CARREGAR JOGO\n");
    printf("3 - SAIR\n");
    deu_certo = scanf("%c", &opcao);
    while (getchar() != '\n'){
      switch (opcao) {
        case '1':
          deu_certo = system("clear");
          printf("NOVO JOGO\n");
          printf("1 - FÁCIL\n");
          printf("2 - MÉDIO\n");
          printf("3 - DIFÍCIL\n");
          printf("0 - SAIR\n");
          deu_certo = scanf("%c", &valor);
          while (getchar() != '\n');
        switch (valor) {
          case '1':
          
          
          
        }
        
        
        
    }
  }
  return 0;
