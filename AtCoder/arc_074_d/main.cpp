#include <bits/stdc++.h>
using namespace std;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<uint> vecA(3*N);
    for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }

    // head
    uint64 sumH=0ull;
    priority_queue<uint64,vector<uint64>,greater<uint64>> queH; // head
    for(uint i=0; i<N; ++i){ queH.push(vecA[i]); sumH+=vecA[i]; }
    
    vector<uint64> vecH(N); vecH.resize(0);
    vecH.push_back( sumH );
    for(uint i=N+1; i<2*N; ++i){
        queH.push(vecA[i]);
        sumH -= queH.top(); queH.pop();
        vecH.push_back( sumH );
    }
    
    // tail
    uint64 sumT=0ull;
    priority_queue<uint64> queT; // head
    for(uint i=2*N; i<3*N; ++i){ queT.push(vecA[i]); sumT+=vecA[i]; }
    
    vector<uint64> vecT(N); vecT.resize(0);
    vecT.push_back( sumT );
    for(uint i=N+1; i<2*N; ++i){
        queT.push(vecA[i]);
        sumT -= queT.top();
        vecT.push_back( sumT );
    }
    
    uint64 max=0ull;
    for(uint i=1; i<vecT.size()-1; ++i){
        uint64 buf = vecH[i] - vecT[i+1];
        if(buf>max){ max=buf; }
    }
    cout << max << endl;
    
    return 0;
}
