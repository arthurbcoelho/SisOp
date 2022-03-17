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

//void getLargestNumber(int* M){
//    for(int i = 0; i < M.size(); i++);
//}


void MostraMatriz(int Altura, int Largura, int* M, string Titulo)
{
    int L, C; //Linha e Coluna
    
    
    cout << "------" << Titulo << "------" <<endl;
    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            cout.width(6);
            cout << left << M[L * Altura + C];
        }
        cout << endl;
    }
    cout << endl;
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
void PreencheMatrizResultado(int Altura, int Largura, int* M)
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

