#include <iostream>
using namespace std;

int main() {
    
    int x, y, z, m, m1;
    cin >> x >> y >> z;
    
    m1 = (x + y + abs(x - y))/2;
    m = (m1 + z + abs(m1 - z))/2;
    
    cout << m << " eh o maior";
    
    return 0;
}