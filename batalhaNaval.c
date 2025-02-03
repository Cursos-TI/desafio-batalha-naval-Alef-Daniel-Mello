#include <stdio.h>

    #define TamanhoX 10
    #define TamanhoY 10
    
    int *T[TamanhoX][TamanhoY];
    int NH[2]; // - Navio Horizontal
    int NV[2]; // - Navio Vertical
    int D1[2]; // - Navio Diagonal 1
    int D2[2]; // - Navio Diagonal 2


void exibirtabuleiro(){

    for (int X=0,Y=0; X < TamanhoX+1 && Y < TamanhoY+1; X++)  // Função para exibir o tabuleiro
    {
        if (X == 0 && Y == 0)
        {
            printf("\nEstado do tabuleiro :\n  X ");
            for (int L = 0; Y == 0 && L < TamanhoY; L++)
            {
             printf("%d ",L);
            }

            printf("\nY   ");

            for (int L = 0; Y == 0 && L < TamanhoY; L++)
            {
             printf("| ",L);
            }
             printf("\n");
      
                
        }
        
        if(X == TamanhoX && Y < TamanhoY-1){
            X = 0;
            Y++;
            printf("\n");
        }
        if(X < TamanhoX && Y < TamanhoY)
        {
            if (X == 0)
            {
                printf("%d - ",Y);
            }
        printf("%d ",T[X][Y]);

        }
    }
    printf("\n"); 
}
void configurardiag2(){
printf("Insira a posição X que o Navio Diagonal 2 irá ficar, começando do lado Esquerdo Superior :");
    scanf("%d", &D2[0]);
    if (D2[0] < TamanhoX-1 && D2[0] >= 0)
    {
        printf("Entrada aceita!\n");
        printf("Insira a posição Y que ficará o Navio Diagonal :");
        scanf("%d",&D2[1]);

        if (D2[1] < TamanhoY-1 && D2[1] >= 0)
        {
            if(T[D2[0]][D2[1]] == 0 && T[D2[0]+1][D2[1]+1] == 0){
             printf("Entrada aceita!\n\n");
             printf("Posicionando Navio Diagonal...\n");
             T[D2[0]][D2[1]] = 3;
             T[D2[0]+1][D2[1]+1] = 3;

              exibirtabuleiro();
            }
        else
        {
           printf("Posição ocupada! selecione o Navio Vertical novamente!\n");
           configurardiag2();
        }
        
        }
        else{
         printf("\nEntrada incorreta! Por favor, insira o número correto ao selecionar a posição diagonal!\n");
         printf("Vamos tentar do inicio novamente!\n");

         configurardiag2();
        }
    }
    else{
    printf("Entrada incorreta! Por favor, insira o número correto ao selecionar a posição diagonal!\n");
    configurardiag2();
    }

}

void configurardiag1(){
printf("Insira a posição X que o Navio Diagonal 1 irá ficar, começando do lado Esquerdo Superior :");
    scanf("%d", &D1[0]);
    if (D1[0] < TamanhoX-1 && D1[0] >= 0)
    {
        printf("Entrada aceita!\n");
        printf("Insira a posição Y que ficará o Navio Diagonal :");
        scanf("%d",&D1[1]);

        if (D1[1] < TamanhoY-1 && D1[1] >= 0)
        {
            if(T[D1[0]][D1[1]] == 0 && T[D1[0]+1][D1[1]+1] == 0){
             printf("Entrada aceita!\n\n");
             printf("Posicionando Navio Diagonal...\n");
             T[D1[0]][D1[1]] = 3;
             T[D1[0]+1][D1[1]+1] = 3;

              exibirtabuleiro();
              configurardiag2();
            }
        else
        {
           printf("Posição ocupada! selecione o Navio Vertical novamente!\n");
           configurardiag1();
        }
        
        }
        else{
         printf("\nEntrada incorreta! Por favor, insira o número correto ao selecionar a posição diagonal!\n");
         printf("Vamos tentar do inicio novamente!\n");

         configurardiag1();
        }
    }
    else{
    printf("Entrada incorreta! Por favor, insira o número correto ao selecionar a posição diagonal!\n");
    configurardiag1();
    }

}
void configurarnv(){

    printf("Insira a posição X que o Navio Vertical irá ficar, de cima para baixo :");
    scanf("%d", &NV[0]);
    if (NV[0] < TamanhoX && NV[0] >= 0)
    {
        printf("Entrada aceita!\n");
        printf("Insira a posição Y que ficará o Navio Vertical :");
        scanf("%d",&NV[1]);

        if (NV[1] < TamanhoY-1 && NV[1] >= 0)
        {
            if(T[NV[0]][NV[1]] == 0 && T[NV[0]][NV[1]+1] == 0){
             printf("Entrada aceita!\n\n");
             printf("Posicionando Navio Vertical...\n");
             T[NV[0]][NV[1]] = 3;
             T[NV[0]][NV[1]+1] = 3;

              exibirtabuleiro();
              configurardiag1();
            }
        else
        {
           printf("Posição ocupada! selecione o Navio Vertical novamente!\n");
           configurarnv();
        }
        
        }
        else{
         printf("\nEntrada incorreta! Por favor, insira o número correto ao selecionar a posição vertical!\n");
         printf("Vamos tentar do inicio novamente!\n");

         configurarnv();
        }
    }
    else{
    printf("Entrada incorreta! Por favor, insira o número correto ao selecionar a posição horizontal!\n");
    configurarnv();
    }

}
void configurarnh(){

    printf("Insira a posição X que o Navio Horizontal irá ficar, da esquerda para direita :");
    scanf("%d", &NH[0]);
    if (NH[0] < TamanhoX-1 && NH[0] >= 0)
    {
        printf("Entrada aceita!\n");
        printf("Insira a posição Y que ficará o Navio Horizontal :");
        scanf("%d",&NH[1]);

        if (NH[1] < TamanhoY && NH[1] >= 0)
        {
        printf("Entrada aceita!\n\n");
        printf("Posicionando Navio Horizontal...\n");
        T[NH[0]][NH[1]] = 3;
        T[NH[0]+1][NH[1]] = 3;

        exibirtabuleiro();
        configurarnv();
        }
        else{
         printf("Entrada incorreta! Por favor, insira o número correto ao selecionar a posição vertical!\n");
         printf("Vamos tentar do inicio novamente!\n");

         configurarnh();
        }
    }
    else{
    printf("Entrada incorreta! Por favor, insira o número correto ao selecionar a posição horizontal!\n");
    configurarnh();
    }

}


int main() {
    
    printf("-- Batalha Naval! --\n\n");
    
    exibirtabuleiro();
    printf("Para definir as posições, use as letras como guia, sendo X as posições horizontais e Y as posições verticais!\n\n");

    configurarnh();

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
