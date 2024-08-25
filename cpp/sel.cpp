#include <iostream>
using namespace std;

int main(){
    int vet[5] = {4, 3, 7, 9, 2};
    int posm, mn, aux;
    for (int i = 0; i < 5; i++){
        mn = 10;     
        for (int j = i; j < 5; j++){
            if (mn > vet[j]){ 
                mn = vet[j];
                posm = j;
            }
        aux = vet[i];
        vet[i] = vet[posm];
        vet[posm] = aux;
        }
    }
    for (int i = 0; i < 5; i++){
        cout << vet[i];
    }
}