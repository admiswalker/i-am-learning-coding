#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<uint> vecA(3*N);
    for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    
    // head
    int64 sumH=0ull;
    priority_queue<int64,vector<int64>,greater<int64>> queH;
    for(uint i=0; i<N; ++i){ queH.push(vecA[i]); sumH+=vecA[i]; }
    
    vector<int64> vecH(N+1); vecH.resize(0);
    vecH.push_back( sumH );
    for(uint i=N; i<2*N; ++i){
        queH.push(vecA[i]);
        sumH += vecA[i];
        sumH -= queH.top(); queH.pop();
        vecH.push_back( sumH );
    }
    
    // tail
    int64 sumT=0ull;
    priority_queue<int64> queT;
    for(uint i=2*N; i<3*N; ++i){ queT.push(vecA[i]); sumT+=vecA[i]; }
    
    vector<int64> vecT(N+1); vecT.resize(0);
    vecT.push_back( sumT );
    for(uint i=2*N-1; i>=N; --i){
        queT.push(vecA[i]);
        sumT += vecA[i];
        sumT -= queT.top(); queT.pop();
        vecT.push_back( sumT );
    }
    
    // solve
    int64 max=INT64_MIN;
    for(uint i=0; i<N+1; ++i){
        int64 buf = vecH[i] - vecT[N-i];
        if(buf>max){ max=buf; }
    }
    
    cout << max << endl;
    return 0;
}
