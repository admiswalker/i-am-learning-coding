#include <bits/stdc++.h>
using namespace std;

struct ABCW{
    int a;
    int b;
    int c;
    int w;
};
struct XYZ{
    int x;
    int y;
    int z;
};

#define dp_m(i, j, k)                           \
    dp[(size*size)*(i) + (size)*(j) + (k)]

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<struct ABCW> vecABCW(N);
    vector<struct XYZ > vecXYZ (M);
    for(int i=0; i<N; ++i){ cin >> vecABCW[i].a >> vecABCW[i].b >> vecABCW[i].c >> vecABCW[i].w; }
    for(int i=0; i<M; ++i){ cin >>  vecXYZ[i].x >>  vecXYZ[i].y >>  vecXYZ[i].z; }
    
    int size=100+1;
    vector<int> dp(size*size*size, 0);
    for(unsigned int i=0; i<vecABCW.size(); ++i){
        dp_m(vecABCW[i].a, vecABCW[i].b, vecABCW[i].c) = max(vecABCW[i].w, dp_m(vecABCW[i].a, vecABCW[i].b, vecABCW[i].c));
    }
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            for(int k=0; k<size; ++k){
                if(i>=1){ dp_m(i, j, k) = max(dp_m(i-1, j, k), dp_m(i, j, k)); }
                if(j>=1){ dp_m(i, j, k) = max(dp_m(i, j-1, k), dp_m(i, j, k)); }
                if(k>=1){ dp_m(i, j, k) = max(dp_m(i, j, k-1), dp_m(i, j, k)); }
            }
        }
    }
    
    for(unsigned int i=0; i<vecXYZ.size(); ++i){
        cout << dp_m(vecXYZ[i].x, vecXYZ[i].y, vecXYZ[i].z) << endl;
    }
    
    return 0;
}

#undef dp_m
