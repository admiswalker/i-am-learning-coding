#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<std::string, int64> hashT(100);
    uint N; cin >> N;
    for(uint i=0; i<N; ++i){
        string s; cin >> s;
        auto itr = hashT.find(s);
        if(itr==hashT.end()){ hashT[s]=1; continue; }
        ++(itr->second);
    }
    uint M; cin >> M;
    for(uint i=0; i<M; ++i){
        string s; cin >> s;
        auto itr = hashT.find(s);
        if(itr==hashT.end()){ hashT[s]=-1; continue; }
        --(itr->second);
    }
    
    int64 max=0;
    for(auto itr=hashT.begin(); itr!=hashT.end(); ++itr){
        if(max < itr->second){ max=itr->second; }
    }
    
    cout << max << endl;
    
    return 0;
}
