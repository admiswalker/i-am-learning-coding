#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

tuple<int64, int64> split2two(const vector<int64>& vSum, const int* vA, const int N){
    int64 sum=vSum[N-1];
    
    int64 min=INT64_MAX;
    uint minIdxL=0;
    for(int i=0; i<N-1; ++i){
        int64 diff = abs(vSum[i]-(sum-vSum[i]));
        if(diff<min){
            min = diff;
            minIdxL = i;
        }
    }
    
    int64 sumL = vSum[minIdxL];
    int64 sumR = sum - vSum[minIdxL];
    return tie(sumL, sumR);
}

vector<int64> gen_vSum(const vector<int>& vA){
    const int N = vA.size();
    vector<int64> vSum(N); vSum[0]=vA[0];
    for(int i=1; i<N; ++i){ vSum[i] = vSum[i-1]+vA[i]; }
    return vSum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N); for(uint i=0; i<N; ++i){ cin>>vA[i]; }
    vector<int> vA_re=vA; reverse(vA_re.begin(), vA_re.end());
    
    vector<int64> vSum    = gen_vSum(vA   );
    vector<int64> vSum_re = gen_vSum(vA_re);
    
    int64 min=INT64_MAX;
    for(uint c=2; c<N-2; ++c){ // c: center
        int64 sumLL, sumLR;
        tie(sumLL, sumLR) = split2two(vSum, &vA[0], c); // [0, c) // size==c
        
        int64 sumRL, sumRR;
        tie(sumRL, sumRR) = split2two(vSum_re, &vA_re[0], N-c); // [0, N-c) // size==N-c
        
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
