#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

void dps(const vector<int>& vecA, const vector<int>& vecB){
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<int> vecA(N); for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    vector<int> vecB(M); for(uint i=0; i<vecB.size(); ++i){ cin >> vecB[i]; }
    
    dps(vecA, vecB);
    
    return 0;
}
