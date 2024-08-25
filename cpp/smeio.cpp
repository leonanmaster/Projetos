#include <iostream>
using namespace std;

int main() {
    
    int h, m, z, l, ma = 0, mn = 1000;
    
    cin >> h >> z >> l;

    int idds[3] = {h, z, l};
    
    for(int i : idds){
        if (ma < i){ ma = i;}
        if (mn > i){ mn = i;}
    }
    for(int i : idds){
        if (i != ma && i != mn ){m = i;}
    }
    if (m == h){cout << "huguinho\n";}
    if (m == z){cout << "zezinho\n";}
    if (m == l){cout << "luizinho\n";}
    
    return 0;
}