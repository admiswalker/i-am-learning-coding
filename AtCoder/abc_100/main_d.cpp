// ref: https://img.atcoder.jp/abc100/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct xyz{
    uint64 x;
    uint64 y;
    uint64 z;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<xyz> vXYZ(N);
    
    for(uint i=0; i<N; ++i){
        cin >> vXYZ[i].x >> vXYZ[i].y >> vXYZ[i].z;
    }
    
    int64 maxn=0;
    vector<int64> vec(N);
    for(uint i=0; i<8; ++i){
        int sign_x = (i & 0b001) ? 1:-1;
        int sign_y = (i & 0b010) ? 1:-1;
        int sign_z = (i & 0b100) ? 1:-1;
        for(uint i=0; i<N; ++i){
            vec[i] = sign_x*vXYZ[i].x + sign_y*vXYZ[i].y + sign_z*vXYZ[i].z;
        }
        sort(vec.begin(), vec.end(), greater<int64>());
        int64 sum = accumulate(&vec[0], &vec[0]+M, 0ll);
        maxn = max(maxn, sum);
    }
    cout << maxn << endl;
    
    return 0;
}
