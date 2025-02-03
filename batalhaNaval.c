#include <stdio.h>

    int *T[5][5];
    int NH[2]; // - Navio Horizontal
    int NV[2]; // - Navio Vertical


void exibirtabuleiro(){

    for (int X=0,Y=0; X < 6 && Y < 6; X++)  // Função para exibir o tabuleiro
    {
        if (X == 0 && Y == 0)
        {
                printf("\nEstado do tabuleiro :\n  X T 1 2 3 4\nY   | | | | |\n");
        }
        
        if(X == 5 && Y < 4){
            X = 0;
            Y++;
            printf("\n");
        }
        if(X < 5 && Y < 5)
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
void configurarnv(){

    printf("Insira a posição X que o Navio Vertical irá ficar, de cima para baixo :");
    scanf("%d", &NV[0]);
    if (NV[0] < 5 && NV[0] >= 0)
    {
        printf("Entrada aceita!\n");
        printf("Insira a posição Y que ficará o Navio Vertical :");
        scanf("%d",&NV[1]);

        if (NV[1] < 4 && NH[1] >= 0)
        {
            if(T[NV[0]][NV[1]] == 0 && T[NV[0]][NV[1]+1] == 0){
             printf("Entrada aceita!\n\n");
             printf("Posicionando Navio Vertical...\n");
             T[NV[0]][NV[1]] = 3;
             T[NV[0]][NV[1]+1] = 3;

              exibirtabuleiro();

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
    if (NH[0] < 4 && NH[0] >= 0)
    {
        printf("Entrada aceita!\n");
        printf("Insira a posição Y que ficará o Navio Horizontal :");
        scanf("%d",&NH[1]);

        if (NH[1] < 5 && NH[1] >= 0)
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
