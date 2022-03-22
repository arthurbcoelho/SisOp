#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void SalvaMatriz(int Altura, int Largura, int *M, string Titulo, string NomeArquivo)
{
    int L, C; // Linha e Coluna

    NomeArquivo = "./files/" + NomeArquivo;

    ofstream FILE;
    FILE.open(NomeArquivo);

    if (!FILE.is_open())
    {
        cout << "\n::: Erro abrindo arquivo " << NomeArquivo << endl;
        exit(EXIT_FAILURE);
    }

    FILE << " " << Titulo << " " << endl;
    for (L = 0; L < Altura; L++)
    {
        for (C = 0; C < Largura; C++)
        {
            FILE.width(3);
            FILE << left << M[L * Altura + C];
        }
        FILE << endl;
    }

    FILE.close();
}

void MostraMatriz(int Altura, int Largura, int *M, string Titulo)
{
    int L, C, i; // Linha e Coluna

    cout << "------" << Titulo << "------" << endl;
    for (L = 0; L < Altura; L++)
    {
        for (C = 0; C < Largura; C++)
        {
            cout.width(6);
            cout << left << M[L * Largura + C];
        }
        cout << endl;
    }
    cout << endl;
}

void PreencheMatriz(int Altura, int Largura, int *M, int matrizResultado)
{

    int L, C; // Linha e Coluna

    if (matrizResultado == 0)
    {
        for (L = 0; L < Altura; L++)
        {
            for (C = 0; C < Largura; C++)
            {
                if (matrizResultado == 0)
                {
                    M[L * Altura + C] = (C + 1) + L ;
                }
                else if (matrizResultado == 1)
                {
                    M[L * Altura + C] = 0; // Inicia Mc 
                }
                else
                {
                    cout << "Erro ao preencher matriz!" << endl;
                }
            }
        }
    }
}
int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        cout << "Not enough arguments" << endl;
        exit(1);
    }

    int N = atoi(argv[1]);

    srand(time(NULL));

    int *Ma = (int *)malloc(sizeof(int) * N * N);
    if (Ma == NULL)
    {
        cout << "\nErro alocando memoria! " << endl;
        exit(EXIT_FAILURE);
    }

    int *Mb = (int *)malloc(sizeof(int) * N * N);
    if (Mb == NULL)
    {
        cout << "\nErro alocando memoria! " << endl;
        exit(EXIT_FAILURE);
    }

    int *Mc = (int *)malloc(sizeof(int) * N * N);
    if (Mc == NULL)
    {
        cout << "\nErro alocando memoria! " << endl;
        exit(EXIT_FAILURE);
    }

 
    // cout << "::: Matrix Multiplication \n" << endl;
    // cout << "::: Width: " << N << " | Height: " << N << " | Total Size: " << N * N << endl;
    // cout << "::: Preenchendo as matrizes... " << endl;
  
    PreencheMatriz(N, N, Ma, 0);
    PreencheMatriz(N, N, Mb, 0);
    PreencheMatriz(N, N, Mc, 1);

 
    // cout << "Done! Now calculating..." << endl;
    // MostraMatriz(N, N, Ma, " Matriz A ");
    // MostraMatriz(N, N, Mb, " Matriz B ");
    // MostraMatriz(N, N, Mc, " Matriz C ");
    
    int L, C, K;

    // conta o tempo de processamento
    clock_t start, end;
    start = clock();

    // C = A . B
    for (L = 0; L < N; L++)
    {
        for (C = 0; C < N; C++)
        {
            for (K = 0; K < N; K++)
            {
                // AB1 AB1
                //Mc[L * N + C] += Ma[L * N + K] * Mb[K * N + C];
                // AB1 AB2
                //Mc[L * N + C] += Ma[L * N + K] * Mb[K + N * C];
                // AB2 AB1
                Mc[L * N + C] += Ma[L + N * K] * Mb[K * N + C];
                // AB2 AB2
                //Mc[L * N + C] += Ma[L + N * K] * Mb[K + N * C];
            }
        }
    }

    end = clock();
    double tempoProcessamento = ((double)(end - start)) / (double)(CLOCKS_PER_SEC);

  
    // cout << "\nCalculation is done! Now saving data on the disc..." << endl;
    //MostraMatriz(N, N, Mc, " Matriz C ");
    // cout << "\nAll done! Tempo de processamento: " << fixed << tempoProcessamento << "segundos." << endl;
    

    cout << N << " " << fixed << tempoProcessamento << endl;
    return 0;
}
