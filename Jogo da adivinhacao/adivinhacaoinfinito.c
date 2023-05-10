#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

   printf("        P  /_\\  P                                  \n");
   printf("       /_\\_|_|_/_\\                                 \n");
   printf("   n_n | ||. .|| | n_n         Bem vindo ao        \n");
   printf("   |_|_|nnnn nnnn|_|_|     Jogo de Adivinhacao!    \n");
   printf("  |" "  |  |_|  |"  " |                            \n");
   printf("  |_____| ' _ ' |_____|                            \n");
   printf("        \\__|_|__/                                  \n");


   int segundos = time(0);
   srand(segundos);

   int numerogrande = rand();

   int numerosecreto = numerogrande % 100;
   int chute;
   int tentativas = 1;
   double pontos = 1000;

   while(1)
   {
      printf("Tentativa %d.\n", tentativas);
      printf("Qual e o seu chute?");

      scanf("%d", &chute);
      printf("Seu chute foi %d\n", chute);

      if(chute < 0){
         printf("Voce nao pode chutar numeros negativos.\n");
         continue;
      }

      int acertou = (chute == numerosecreto);
      int maior = chute > numerosecreto;
      
      if (acertou)
      {
         printf("Parabens! Voce acertou!\n");
         break;
      }
      else if (maior)
      {
         printf("Seu chute foi maior que o numero secreto.\n");
      }
      else
      {
         printf("Seu chute foi menor que o numero secreto.\n");
      }

      tentativas++;

      double pontosperdidos = abs(chute - numerosecreto) / (double)2;

      pontos = pontos - pontosperdidos;
   }
   printf("Fim de jogo!\n");
   printf("Voce acertou em %d tentativas!\n", tentativas);
   printf("Total de pontos %.1f.\n", pontos);
}
