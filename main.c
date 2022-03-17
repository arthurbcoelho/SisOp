/*
** Multiplicação de Matrizes Quadradas (N x N)
** Prof. Filipo Mór - filipomor.com
** 24 de março de 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void SalvaMatriz(int Altura, int Largura, int* M, char* Titulo, char* NomeArquivo)
{
	int L, C; //Linha e Coluna
	
	FILE *fp = fopen(NomeArquivo, "w");
	if( fp == NULL)
	{
		printf("\n::: Erro abrindo arquivo '%s''!\n", NomeArquivo);
		exit(EXIT_FAILURE);
	}

    fprintf(fp, " %s \n", Titulo);
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            fprintf(fp, " %2d ", M[L * Altura + C]);
        }
        fprintf(fp, "\n");
    }	
    
    fclose(fp);
	
}

void MostraMatriz(int Altura, int Largura, int* M, char* Titulo)
{
    int L, C; //Linha e Coluna

    printf(" %s \n", Titulo);
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            printf(" %2d ", M[L * Altura + C]);
        }
        printf("\n");
    }
}

void PreencheMatriz(int Altura, int Largura, int* M)
{

    int L, C, r; //Linha e Coluna
    
    printf("Random number: %d \n", r);

    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            r = (rand() % 10) + 1; 
            M[L * Altura + C] = L * C + r;
        }
    }

}
void PreencheMatrizResultado(int Altura, int Largura, int* M, int Valor)
{
    int L, C; //Linha e Coluna

    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            M[L * Altura + C] = 0;
        }
    }

}

int main(int argc, char *argv[])
{
    if(argc < 1){
        printf("Not enough arguments"); //TODO
        exit(1);
    }

    int N = atoi(argv[1]);

    srand(time(NULL));
    
    int* Ma = (int*)malloc(sizeof(int) * N * N);
    if ( Ma == NULL )
    {
        printf("\nErro alocando memoria! \n");
        exit( EXIT_FAILURE );
    }

    int* Mb = (int*)malloc(sizeof(int) * N * N);
    if ( Mb == NULL )
    {
        printf("\nErro alocando memoria! \n");
        exit( EXIT_FAILURE );
    }

    int* Mc = (int*)malloc(sizeof(int) * N * N);
    if ( Mc == NULL )
    {
        printf("\nErro alocando memoria! \n");
        exit( EXIT_FAILURE );
    }

	printf("::: Matrix Multiplication \n");
	printf("::: Width: %d | Height: %d | Total Size: %d \n", N, N, N*N);
	printf("::: Preenchendo as matrizes... ");

    PreencheMatriz(N, N, Ma);
    PreencheMatriz(N, N, Mb);
    PreencheMatriz(N, N, Mc);

	printf("Done! Now calculating...\n");
    //MostraMatriz(N, N, Ma, " Matriz A ");
    //MostraMatriz(N, N, Mb, " Matriz B ");
    //MostraMatriz(N, N, Mc, " Matriz C ");
    int L, C, K;

    // conta o tempo de processamento
    clock_t tempo;
    tempo = clock();

    //C = A . B
    for(L=0; L<N; L++)
    {
        for(C=0; C<N; C++)
        {
            for(K=0; K<N; K++)
            {
                Mc[L * N + C] += Ma[L * N + K] * Mb[K * N + C];
            }
        }
    }

	clock_t final = clock();
	double tempoProcessamento = ((double)(final-tempo)) / (double)(CLOCKS_PER_SEC);
	
	printf("Calculation is done! Now saving data on the disc...\n");
    //MostraMatriz(N, N, Mc, " Matriz C ");
    printf("Saving Matriz A on disc...\n");
	SalvaMatriz(N, N, Ma, "::: Matriz A :::", "matrizA.txt");
    printf("Saving Matriz B on disc...\n");
	SalvaMatriz(N, N, Mb, "::: Matriz B :::", "matrizB.txt");
    printf("Saving Matriz C on disc...\n");
	SalvaMatriz(N, N, Mc, "::: Matriz C :::", "matrizC.txt");
    
    printf("\nAll done! Tempo de processamento: %f segundos.\n", tempoProcessamento);
    return 0;
}