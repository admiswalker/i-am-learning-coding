#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;

int dps(const vector<int>& vecA, uint cur){
    if(cur==vecA.size()){ return 0; }
    
    uint i1=cur+1;
    bool TF1=false;
    for(; i1<vecA.size(); ++i1){
        if(vecA[cur]<vecA[i1]){ TF1=true; break; }
    }
    
    uint i2=i1+1;
    bool TF2=false;
    for(; i2<vecA.size(); ++i2){
        if(vecA[cur]<vecA[i2]){ TF2=true; break; }
    }
    
    if(TF1==false && TF2==false){ return 0; }
    if(TF1==true  && TF2==false){ return 1; }
    
    return max(dps(vecA, i1)+1, dps(vecA, i2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vecA(N);
    for(uint i=0; i<vecA.size(); ++i){ cin >> vecA[i]; }
    
    int maxLen = dps(vecA, 0)+1;
    cout << (N-maxLen) << endl;
    
    return 0;
}
