#include <bits/stdc++.h>
typedef int64_t int64;
using namespace std;

int main(){
    double sum=0.0;
    
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        double x; string s; cin >> x >> s;
        if(s=="BTC"){ x *= 380000.0; }
        sum += x;
    }
    cout << sum << endl;
    
    return 0;
}
