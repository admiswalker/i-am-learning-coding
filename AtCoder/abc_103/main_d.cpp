#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

bool isConnect(const vector<pair<int,int>>& vNC, uint& idx_inOut, const int a, const int b){
    ;
    for(uint i=0; i<vNC.size(); ++i){
        const int f = vNC[i].first;
        const int s = vNC[i].second;
        if(a<=f && f<=b){ idx_inOut=i; return true; }
        if(a<=s && s<=b){ idx_inOut=i; return true; }
    }
    return false;
}
void shrink(vector<pair<int,int>>& vNC, const uint idx, const int a, const int b){
    int& f = vNC[idx].first;
    int& s = vNC[idx].second;
    if(a<=f && f<=b){ f=a; }
    if(a<=s && s<=b){ s=b; }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<pair<int,int>> vNC; // not connected
    
    for(uint i=0; i<M; ++i){
        int a, b; cin >> a >> b;
        uint idx;
        if(isConnect(vNC, idx, a, b)){
            shrink(vNC, idx, a, b);
            continue;
        }
        vNC.push_back(pair<int,int>{a,b});
    }
    
    cout << vNC.size() << endl;
    
    return 0;
}
