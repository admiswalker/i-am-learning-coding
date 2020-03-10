#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

tuple<vector<int>, vector<int>> split2two(const vector<int>& vA){
    const int N = vA.size();
    
    vector<int64> sumL(N, 0ll); sumL[0]=vA[0];
    for(int i=1; i<N; ++i){ sumL[i]=sumL[i-1]+vA[i]; }
    
    vector<int64> sumR(N, 0ll); sumR[N-1]=vA[N-1];
    for(int i=N-2; i>=0; --i){ sumR[i]=sumR[i+1]+vA[i]; }
    
    int64 min=INT64_MAX;
    uint minIdxL=0;
    for(int i=0; i<N-1; ++i){
        int64 diff = abs(sumL[i]-sumR[i+1]);
        if(diff<min){
            min = diff;
            minIdxL = i;
        }
    }
    
    vector<int> vFront(minIdxL+1);
    vector<int> vRear (N-minIdxL);
    copy(&vA[0], &vA[minIdxL+1], vFront.begin());
    copy(&vA[minIdxL+1], &vA[N], vRear.begin()  );
    
    return tie(vFront, vRear);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N);
    for(uint i=0; i<N; ++i){ cin>>vA[i]; }
    
    vector<int> vF, vR;
    tie(vF, vR) = split2two(vA);
    
    vector<int> vFF, vFR;
    tie(vFF, vFR) = split2two(vF);
    vector<int> vRF, vRR;
    tie(vRF, vRR) = split2two(vR);
    
    int64 P = accumulate(vFF.begin(), vFF.end(), 0ll);
    int64 Q = accumulate(vFR.begin(), vFR.end(), 0ll);
    int64 R = accumulate(vRF.begin(), vRF.end(), 0ll);
    int64 S = accumulate(vRR.begin(), vRR.end(), 0ll);
    cout << "P: " << P << endl;
    cout << "Q: " << Q << endl;
    cout << "R: " << R << endl;
    cout << "S: " << S << endl;
    
    vector<int64> vPQRS = {P, Q, R, S};
    int64 minVal = *min_element(vPQRS.begin(), vPQRS.end());
    int64 maxVal = *max_element(vPQRS.begin(), vPQRS.end());
    
    cout << maxVal-minVal << endl;
    
    /*
    if(vF.size()==1){
        // split vR to 3 pieces
    }
    if(vR.size()==1){
        // split vF to 3 pieces
    }
    //*/
    return 0;
}
