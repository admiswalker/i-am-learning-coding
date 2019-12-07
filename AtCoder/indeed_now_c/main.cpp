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

int search(const vector<struct ABCW>& vecABCW, const struct XYZ& xyz){
    int max_w=0;
    for(unsigned int i=0; i<vecABCW.size(); ++i){
        if(   vecABCW[i].a <= xyz.x
           && vecABCW[i].b <= xyz.y
           && vecABCW[i].c <= xyz.z
           && max_w < vecABCW[i].w)
        {
            max_w = vecABCW[i].w;
        }
    }
    return max_w;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<struct ABCW> vecABCW(N);
    vector<struct XYZ > vecXYZ (M);
    for(int i=0; i<N; ++i){ cin >> vecABCW[i].a >> vecABCW[i].b >> vecABCW[i].c >> vecABCW[i].w; }
    for(int i=0; i<M; ++i){ cin >>  vecXYZ[i].x >>  vecXYZ[i].y >>  vecXYZ[i].z; }
    
    for(unsigned int i=0; i<vecXYZ.size(); ++i){
        int max_w = search(vecABCW, vecXYZ[i]);
        cout << max_w << endl;
    }
    
    return 0;
}
