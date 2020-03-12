#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

vector<int64> gen_vSum(const vector<int>& vA){
    const int N = vA.size();
    vector<int64> vSum(N); vSum[0]=vA[0];
    for(int i=1; i<N; ++i){ vSum[i] = vSum[i-1]+vA[i]; }
    return vSum;
}

int64 min(int64 i1, int64 i2, int64 i3, int64 i4){
    if(i2<i1){ i1=i2; }
    if(i4<i3){ i3=i4; }
    if(i3<i1){ i1=i3; }
    return i1;
}
int64 max(int64 i1, int64 i2, int64 i3, int64 i4){
    if(i2>i1){ i1=i2; }
    if(i4>i3){ i3=i4; }
    if(i3>i1){ i1=i3; }
    return i1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N); for(uint i=0; i<N; ++i){ cin>>vA[i]; }
    vector<int64> vSum = gen_vSum(vA);
    
    int64 ans_min=INT64_MAX;
    uint li=0;
    uint ri=2;
    for(uint c=1; c<N-2; ++c){ // c: center
        
        int64 minPQ = INT64_MAX;
        for(; li<c; ++li){
            int64 P = vSum[li];
            int64 Q = vSum[c] - vSum[li];
            int64 diff = abs(P-Q);
            if(diff<minPQ){ minPQ = diff; continue; }
            break;
        }
        --li;
        
        int64 minRS = INT64_MAX;
        if(ri<=c){ ri=c+1; }
        for(; ri<N; ++ri){
            int64 R = vSum[ri] - vSum[c];
            int64 S = vSum[N-1] - vSum[ri];
            int64 diff = abs(R-S);
            if(diff<minRS){ minRS = diff; continue; }
            break;
        }
        --ri;
        
        int64 P = vSum[li];
        int64 Q = vSum[c] - vSum[li];
        int64 R = vSum[ri] - vSum[c];
        int64 S = vSum[N-1] - vSum[ri];
        int64 minVal = min(P, Q, R, S);
        int64 maxVal = max(P, Q, R, S);
        if(maxVal-minVal<ans_min){
            ans_min = maxVal-minVal;
        }
    }
    cout << ans_min << endl;
    
    return 0;
}

/*
4
1 2 3 4
*/
