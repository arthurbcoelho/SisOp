/*
** Multiplicação de Matrizes Quadradas (N x N)
** Prof. Filipo Mór - filipomor.com
** 24 de março de 2021
*/
#include "functions.hpp"
#include <iomanip>

int main(int argc, char *argv[])
{
    if(argc < 1){
        cout << "Not enough arguments" << endl;
        exit(1);
    }

    int N = atoi(argv[1]);

    srand(time(NULL));

    int* Ma = (int*)malloc(sizeof(int) * N * N);
    if ( Ma == NULL )
    {
        cout << "\nErro alocando memoria! \n" << endl;
        exit( EXIT_FAILURE );
    }
    
    int* Mb = (int*)malloc(sizeof(int) * N * N);
    if ( Mb == NULL )
    {
        cout << "\nErro alocando memoria! \n" << endl;
        exit( EXIT_FAILURE );
    }

    int* Mc = (int*)malloc(sizeof(int) * N * N);
    if ( Mc == NULL )
    {
        cout << "\nErro alocando memoria! \n" << endl;
        exit( EXIT_FAILURE );
    }
    //int vectorSize = *(&Ma + 1) - Ma;

	cout << "::: Matrix Multiplication \n" << endl;
	cout << "::: Width: " << N << " | Height: " << N <<" | Total Size: " << N*N  << endl;
	cout << "::: Preenchendo as matrizes... " << endl;

    PreencheMatriz(N, N, Ma);

    int vectorSize = sizeof(*Ma) / sizeof(int);
    cout << vectorSize << endl;

    PreencheMatriz(N, N, Mb);
    PreencheMatrizResultado(N, N, Mc);

	cout << "Done! Now calculating...\n" << endl;
    MostraMatriz(N, N, Ma, " Matriz A ");
    MostraMatriz(N, N, Mb, " Matriz B ");
    MostraMatriz(N, N, Mc, " Matriz C ");
    int L, C, K;

    // conta o tempo de processamento
    clock_t start, end;
    start = clock();

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

	end = clock();
	double tempoProcessamento = ((double)(end-start)) / (double)(CLOCKS_PER_SEC);
	
	cout << "\nCalculation is done! Now saving data on the disc...\n" << endl;
    MostraMatriz(N, N, Mc, " Matriz C ");
    cout << "Saving Matriz A on disc...\n" << endl;
	SalvaMatriz(N, N, Ma, "::: Matriz A :::", "matrizA.txt");
    cout << "Saving Matriz B on disc...\n" << endl;
	//SalvaMatriz(N, N, Mb, "::: Matriz B :::", "matrizB.txt");
    cout << "Saving Matriz C on disc...\n" << endl;
	//SalvaMatriz(N, N, Mc, "::: Matriz C :::", "matrizC.txt");

    cout << "\nAll done! Tempo de processamento: " << fixed << tempoProcessamento << "segundos." << endl;
    return 0;
}


