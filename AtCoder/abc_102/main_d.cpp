#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

tuple<int64, int64> split2two(const int* vA, const int N){
    int64 sum=0ll; sum=vA[0];
    vector<int64> vSum(N); vSum[0]=vA[0];
    for(int i=1; i<N; ++i){
        sum += vA[i];
        vSum[i] = vSum[i-1]+vA[i];
    }
    
    int64 min=INT64_MAX;
    uint minIdxL=0;
    for(int i=0; i<N-1; ++i){
        int64 diff = abs(vSum[i]-(sum-vSum[i]));
        if(diff<min){
            min = diff;
            minIdxL = i;
        }
    }
    
    int64 sumL = accumulate(&vA[0], &vA[minIdxL+1], 0ll);
    int64 sumR = accumulate(&vA[minIdxL+1], &vA[N], 0ll);
    return tie(sumL, sumR);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N);
    for(uint i=0; i<N; ++i){ cin>>vA[i]; }
    
    int64 min=INT64_MAX;
    for(uint c=2; c<N-2; ++c){ // c: center
        int64 sumLL, sumLR;
        tie(sumLL, sumLR) = split2two(&vA[0], c); // [0, C) // size==C
        
        int64 sumRL, sumRR;
        tie(sumRL, sumRR) = split2two(&vA[c], N-c); // [C, N) // size==N-C
        
        vector<int64> vPQRS = {sumLL, sumLR, sumRL, sumRR};
        int64 minVal = *min_element(vPQRS.begin(), vPQRS.end());
        int64 maxVal = *max_element(vPQRS.begin(), vPQRS.end());
        if(maxVal-minVal<min){
            min = maxVal-minVal;
        }
    }
    cout << min << endl;
    
    return 0;
}
