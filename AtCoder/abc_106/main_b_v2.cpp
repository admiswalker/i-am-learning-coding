#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

vector<pair<int64, int>> factor(int64 n){
    vector<pair<int64, int>> vPN;
    for(int64 p=2; p*p<=n; ++p){
        if(n % p != 0){ continue; }
        
        int num=1; n/=p;
        while(n % p == 0){ ++num; n/=p; }
        vPN.push_back( make_pair(p, num) );
    }
    if(n != 1ll){ vPN.push_back( make_pair(n, 1) ); }
    return vPN;
}

int numDivs(int64 N){
    vector<pair<int64, int>> vPN = factor(N);
    
    uint divs=1;
    for(uint i=0; i<vPN.size(); ++i){
        divs *= (vPN[i].second + 1);
    }
    return divs;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    uint num=0;
    for(uint i=1; i<=N; i+=2){
        if(numDivs(i)==8){ ++num; }
    }
    cout << num << endl;
    
    return 0;
}
