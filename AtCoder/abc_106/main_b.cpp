#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

vector<pair<int64, int>> factor(int64 rhs){
    vector<pair<int64, int>> ret;
    
    int64 i=2;
    while(rhs!=1){
        int num = 0;
        while(rhs%i==0){
            rhs/=i;
            ++num;
        }
        if(num!=0){ ret.push_back({i, num}); }
        ++i;
    }
    return ret;
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
