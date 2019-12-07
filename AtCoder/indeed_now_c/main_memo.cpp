#include <bits/stdc++.h>
using namespace std;

#define dp_m(i, j, k)                           \
    dp[(size*size)*(i) + (size)*(j) + (k)]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    
    int size=100+1;
    vector<int> dp(size*size*size, 0);
    for(int i=0; i<N; ++i){
        int a, b, c, w; cin >> a >> b >> c >> w;
        dp_m(a, b, c) = max(w, dp_m(a, b, c));
    }
    
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            for(int k=0; k<size; ++k){
                if(i>=1){ dp_m(i, j, k) = max(dp_m(i, j, k), dp_m(i-1, j, k)); }
                if(j>=1){ dp_m(i, j, k) = max(dp_m(i, j, k), dp_m(i, j-1, k)); }
                if(k>=1){ dp_m(i, j, k) = max(dp_m(i, j, k), dp_m(i, j, k-1)); }
            }
        }
    }
    
    for(int i=0; i<M; ++i){
        int x, y, z; cin >> x >> y >> z;
        cout << dp_m(x, y, z) << endl;
    }
    
    return 0;
}

#undef dp_m
