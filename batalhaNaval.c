#include <stdio.h>

    #define TamanhoX 10
    #define TamanhoY 10
    
    int *T[TamanhoX][TamanhoY];
    int NH[2]; // - Navio Horizontal
    int NV[2]; // - Navio Vertical
    int D1[2]; // - Navio Diagonal 1
    int D2[2]; // - Navio Diagonal 2

    int H; // Habilidade escolhida
    int Hpos[2];

    int HC[3][5] = { // Habilidade de Cone
      {0,0,1,0,0},
      {0,1,1,1,0},
      {1,1,1,1,1}
    }; 
    int HO[3][5] = { // Habilidade de Octaedro
      {0,0,1,0,0},
      {0,1,1,1,0},
      {0,0,1,0,0}
    }; 
    int HZ[3][5] = { // Habilidade de Cruz
      {0,0,1,0,0},
      {1,1,1,1,1},
      {0,0,1,0,0}
    };

    // Possivel criar um novo padrão para a habilidade

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

void habilidade(){
    printf("\nVamos utilizar uma Habilidade! Selecione o numero correspondente :");
    printf("\n1 - Ataque em Cone\n{0,0,1,0,0}\n{0,1,1,1,0}\n{1,1,1,1,1}");
    printf("\n2 - Ataque em Octaedro\n{0,0,1,0,0}\n{0,1,1,1,0}\n{0,0,1,0,0}");
    printf("\n3 - Ataque em Cruz\n{0,0,1,0,0}\n{1,1,1,1,1}\n{0,0,1,0,0}\n\n");

    scanf("%d",&H);

    printf("\nAgora escolha o local de ataque! Escolha o local do centro do ataque, respeitando as bordas");
    exibirtabuleiro();
   printf("\nEscolha o local em X : ");
   if (H == 1)
   {
    scanf("%d",&Hpos[0]);

        if (Hpos[0] < TamanhoX-2 && Hpos[0] >= 2)
        {
        printf("Entrada aceita!\n");
        printf("Escolha o local em Y : ");
        scanf("%d",&Hpos[1]);

        if (Hpos[1] < TamanhoY-1 && Hpos[1] >= 1)
        {
        printf("Entrada aceita!\n\n");
        printf("Usando Habilidade!\n");
        for (int y = 0; y < 3; y++) 
        {
            for (int x = 0;x < 5; x++)
            {
                if(HC[y][x]!=0){
                 T[(Hpos[0]+(x-2))][(Hpos[1]+(y-1))] = HC[y][x];
                }
            }
            
        }

        exibirtabuleiro();

        }
        else{
         printf("Entrada incorreta! Por favor, selecione um local correto!\n");
         printf("Vamos tentar do inicio novamente!\n");

         habilidade();
        }
    }
    else{
    printf("\nEntrada incorreta! Por favor, insira um local adequado!\n");
    habilidade();
    }
   }
   else if (H == 2)
   {
    scanf("%d",&Hpos[0]);

        if (Hpos[0] < TamanhoX-1 && Hpos[0] >= 1)
        {
        printf("Entrada aceita!\n");
        printf("Escolha o local em Y : ");
        scanf("%d",&Hpos[1]);

        if (Hpos[1] < TamanhoY-1 && Hpos[1] >= 1)
        {
        printf("Entrada aceita!\n\n");
        printf("Usando Habilidade!\n");
        for (int y = 0; y < 3; y++) 
        {
            for (int x = 0;x < 5; x++)
            {
                if(HO[y][x]!=0){
                 T[(Hpos[0]+(x-2))][(Hpos[1]+(y-1))] = HO[y][x];
                }
            }
            
        }

        exibirtabuleiro();

        }
        else{
         printf("Entrada incorreta! Por favor, selecione um local correto!\n");
         printf("Vamos tentar do inicio novamente!\n");

         habilidade();
        }
    }
    else{
    printf("\nEntrada incorreta! Por favor, insira um local adequado!\n");
    habilidade();
    }
   }
   else  if (H == 3)
   {
    scanf("%d",&Hpos[0]);

        if (Hpos[0] < TamanhoX-2 && Hpos[0] >= 2)
        {
        printf("Entrada aceita!\n");
        printf("Escolha o local em Y : ");
        scanf("%d",&Hpos[1]);

        if (Hpos[1] < TamanhoY-1 && Hpos[1] >= 1)
        {
        printf("Entrada aceita!\n\n");
        printf("Usando Habilidade!\n");
        for (int y = 0; y < 3; y++) 
        {
            for (int x = 0;x < 5; x++)
            {
                if(HZ[y][x]!=0){
                 T[(Hpos[0]+(x-2))][(Hpos[1]+(y-1))] = HZ[y][x];
                }
            }
            
        }

        exibirtabuleiro();

        }
        else{
         printf("Entrada incorreta! Por favor, selecione um local correto!\n");
         printf("Vamos tentar do inicio novamente!\n");

         habilidade();
        }
    }
    else{
    printf("\nEntrada incorreta! Por favor, insira um local adequado!\n");
    habilidade();
    }
   }
  else{
    printf("\nSeleção invalida! Selecione novamente!\n");
    habilidade();
  }

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
              habilidade();
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

    return 0;
}
