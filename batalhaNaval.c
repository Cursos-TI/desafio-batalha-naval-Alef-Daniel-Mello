#include <stdio.h>

    int *T[5][5];
    int NH[2]; // - Navio Horizontal
    int NV[2]; // - Navio Vertical

int main() {

    
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("-- Batalha Naval! --\n\n");
    
    for (int X,Y; X < 6 && Y < 6; X++)
    {
        if(X == 5 && Y < 4){
            X = 0;
            Y++;
            printf("\n");
        }
        printf("%d ",T[X][Y]);
    }
    
    printf("Estado do tabuleiro :\n  X T 1 2 3 4\nY   | | | | |\n0 - 0 0 0 0 0\n1 - 0 0 0 0 0\n2 - 0 0 0 0 0\n3 - 0 0 0 0 0\n4 - 0 0 0 0 0\n\n");
    printf("Para definir as posições, use as letras como guia, sendo X as posições horizontais e Y as posições verticais!\n\n");

    
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
void ConfigurarNH(){

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
        printf("Estado do tabuleiro :\n  X 0 1 2 3 4\nY   | | | | |\n0 - 0 0 0 0 0\n1 - 0 0 0 0 0\n2 - 0 0 0 0 0\n3 - 0 0 0 0 0\n4 - 0 0 0 0 0\n\n");

        }
    }
    else{
    printf("Entrada incorreta! Por favor, insira o número correto ao selecionar a posição horizontal!\n");
    ConfigurarNH();
    }
}