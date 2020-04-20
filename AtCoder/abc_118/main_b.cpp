#include <bits/stdc++.h>
using namespace std;

int main(){
    
    uint N, M; cin >> N >> M;
    vector<uint> vType(M, 0);
    
    for(uint ni=0; ni<N; ++ni){
        uint K; cin >> K;
        for(uint ki=0; ki<K; ++ki){
            int A; cin >> A; --A;
            ++vType[ A ];
        }
    }
    
    int numT=0;
    for(uint i=0; i<vType.size(); ++i){
        if(vType[i]==N){ ++numT; }
    }
    
    cout << numT << endl;
    
    return 0;
}
