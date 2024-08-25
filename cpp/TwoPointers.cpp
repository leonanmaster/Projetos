#include <iostream>
using namespace std;

int main() {
    int vet[7] = {1, 5, 3, 9, 10, 13, 19};
    int x, i = 0, j = 6, soma;
    cin >> x;
    while (i < 7) { 
        soma = vet[i] + vet[j];
        if (soma > x){j--;}
        else if (soma < x){i++;}
        else if (soma == x){
            cout << i << " " << j << "\n";
            break;
        }
    }
    if (x != soma){
        cout << "não há valores que somados dá: " << x << "\n";
    }

}