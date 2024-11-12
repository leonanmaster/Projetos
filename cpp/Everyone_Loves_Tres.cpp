#include "bits/stdc++.h"

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
 
using ll = long long;
using f64 = double;
using ii = pair<int, int>;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;


const string ENDL = "\n";

string comb(string current, int n) {
    int val;
    if (current.length() == n) {
        val = stoi(current);
        if (val % 33 == 0 && val % 66 == 0){
            return current;
        }
        return "-1";
    }
    string res = comb(current + "3", n);
    if(res != "-1"){
        return res;
    }
    res = comb(current + "6", n);
    if(res != "-1"){
        return res;
    }
    return "-1";
}


void solve()
{   
    int n;
    cin >> n;
    //string num_to_str = to_string(n);

    string resultado = comb("", n);
    
    cout << ENDL;
    cout << resultado;

}


int main() {
    //ios_base :: sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
     return 0;
}