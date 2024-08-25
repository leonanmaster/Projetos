#include <iostream>
using namespace std;

int main() {
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x, de = 0, ate = 9, m;
    cin >> x;
    while (de <= ate) { 
        m = (de + ate) / 2;
        if (vet[m] > x) {
            ate = m - 1;
        } else if (vet[m] < x) {
            de = m + 1;
        } else {
            break; 
        }
    }
    if (vet[m] == x) {
        cout << m; 
    } else {
        cout << "-1"; 
    }
}