/*
** Multiplicação de Matrizes Quadradas (N x N)
** Prof. Filipo Mór - filipomor.com
** 24 de março de 2021
*/
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void SalvaMatriz(int Altura, int Largura, int* M, string Titulo , string NomeArquivo)
{
	int L, C; //Linha e Coluna

    NomeArquivo = "./files/" + NomeArquivo;

    ofstream FILE;
    FILE.open (NomeArquivo);

	if(!FILE.is_open())
	{
		cout << "\n::: Erro abrindo arquivo " << NomeArquivo << endl;
		exit(EXIT_FAILURE);
	}

    FILE << " " << Titulo << " " << endl;
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            FILE.width(3);            
            FILE << left << M[L * Altura + C];

        }
        FILE << endl;
    }	
    
    FILE.close();
	
}



void MostraMatriz(int Altura, int Largura, int* M, string Titulo)
{
    int L, C; //Linha e Coluna

    cout << Titulo << endl;
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            cout.width(3);
            cout << left << M[L * Altura + C];
        }
        cout << endl;
    }
}
void PreencheMatriz(int Altura, int Largura, int* M)
{

    int L, C, r; //Linha e Coluna 
    
    cout << "Random number: " << r << endl;

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

int main_teste(int argc, char *argv[])
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

	cout << "::: Matrix Multiplication \n" << endl;
	cout << "::: Width: " << N << " | Height: " << N <<" | Total Size: " << N*N  << endl;
	cout << "::: Preenchendo as matrizes... " << endl;

    PreencheMatriz(N, N, Ma);
    PreencheMatriz(N, N, Mb);
    PreencheMatriz(N, N, Mc);

	cout << "Done! Now calculating...\n" << endl;
    MostraMatriz(N, N, Ma, " Matriz A ");
    MostraMatriz(N, N, Mb, " Matriz B ");
    MostraMatriz(N, N, Mc, " Matriz C ");
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
	
	cout << "Calculation is done! Now saving data on the disc...\n" << endl;
    MostraMatriz(N, N, Mc, " Matriz C ");
    cout << "Saving Matriz A on disc...\n" << endl;
	//SalvaMatriz(N, N, Ma, "::: Matriz A :::", "matrizA.txt");
    cout << "Saving Matriz B on disc...\n" << endl;
	//SalvaMatriz(N, N, Mb, "::: Matriz B :::", "matrizB.txt");
    cout << "Saving Matriz C on disc...\n" << endl;
	SalvaMatriz(N, N, Mc, "::: Matriz C :::", "./files/matrizC.txt");
    
    cout << "\nAll done! Tempo de processamento: " << tempoProcessamento << "segundos." << endl;
    return 0;
}

int main(){
    int N = 5;
    
    int* Ma = (int*)malloc(sizeof(int) * N * N);
    if ( Ma == NULL )
    {
        cout << "\nErro alocando memoria! " << endl;
        exit( EXIT_FAILURE );
    }

    PreencheMatriz(N, N, Ma);
    MostraMatriz(N, N, Ma, "Teste");
    SalvaMatriz(N, N, Ma, "::: Matriz A :::", "matrizA.txt");

    return 0;
}

