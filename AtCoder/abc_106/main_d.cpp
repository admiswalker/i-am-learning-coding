#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> vvLR(N+1, vector<int>(N+1, 0));
    vector<vector<int>> vvS (N+1, vector<int>(N+1, 0));
    
    for(int i=0; i<M; ++i){
        int l, r; cin >> l >> r;
        ++vvLR[l][r];
    }
    
    for(int p=1; p<=N; ++p){
        for(int q=1; q<=N; ++q){
            vvS[p][q] = vvLR[p][q] + vvS[p-1][q] + vvS[p][q-1] - vvS[p-1][q-1];
        }
    }
    
    for(int i=0; i<Q; ++i){
        int p, q; cin >> p >> q;
        int num = vvS[q][q] - vvS[p-1][q] - vvS[q][p-1] + vvS[p-1][p-1];
        cout << num << endl;
    }
    
    return 0;
}
