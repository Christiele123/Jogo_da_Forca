#include <stdio.h>
#include <stdlib.h>

int main() {
  char opcao = 0;
  float saldo = 0.0f;
  int numeros[10];
  char palavra[20];
  int tentativa = 3;
  

  while (opcao != '0') {
    int deu_certo = system("clear");
    printf("\e[0; 96mJOGO DA FORCA\e[0m\n");
    printf("1 - NOVO JOGO\n");
    printf("2 - RANKING\n");
    printf("3 - SAIR\n");
    deu_certo = scanf("%c", &opcao);
    while (getchar() != '\n') {
    }
    switch (opcao) {
    case '1':
      deu_certo = system("clear");
      printf("NOVO JOGO\n");
      printf("1 - FÁCIL\n");
      printf("2 - MÉDIO\n");
      printf("3 - DIFÍCIL\n");
      printf("0 - SAIR\n");
      deu_certo = scanf("%c", &opcao);
      while (getchar() != '\n');
      switch (opcao) {
    }
    
}
return 0;
