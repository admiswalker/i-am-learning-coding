#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
int main(){
    uint N,M;cin>>N>>M;
    vector<int64> X(N),Y(N),Z(N);
    for(uint i=0;i<N;++i){cin>>X[i]>>Y[i]>>Z[i];}
    int64 m=0;
    vector<int64> v(N);
    for(uint i=0;i<8;++i){
        int x=(i&0b001)?1:-1;
        int y=(i&0b010)?1:-1;
        int z=(i&0b100)?1:-1;
        for(uint i=0; i<N; ++i){v[i]=x*X[i]+y*Y[i]+z*Z[i];}
        sort(&v[0],&v[0]+N,greater<int64>());
        int64 s=accumulate(&v[0],&v[0]+M,0ll);
        m=max(m,s);
    }
    cout<<m<<endl;
    return 0;
}
