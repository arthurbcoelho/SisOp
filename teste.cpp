#include <iostream>


using namespace std;

void PreencheMatriz(int Altura, int Largura, int* M)
{

    int L, C, r; //Linha e Coluna 
    
    // cout << "Random number: " << r << endl;

    for(L = 0; L < Altura; L++)
    {
        for(C = 0; C < Largura; C++)
        {
            r = (rand() % 10) + 1; 
            M[L * Altura + C] = L * C + r;
        }
    }

}

int main(){
    
    int n = 3;

    int* Ma = (int*)malloc(sizeof(int) * n * n);
    
    PreencheMatriz(n, n, Ma);
    
    cout << "Ma address: " << Ma << endl;
    cout << "Ma 0    address: " << &Ma[0] << endl;
    cout << "Ma 8    address: " << &Ma[8] << endl;
    cout << "Ma 8000 address: " << &Ma[8000] << endl;
    
    return 0;
}