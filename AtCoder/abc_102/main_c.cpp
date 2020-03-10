#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

template<typename T>
T v_max(const vector<T>& vec){
    T max=vec[0];
    for(uint i=1; i<vec.size(); ++i){
        if(vec[i]>max){ max=vec[i]; }
    }
    return max;
}
template<typename T>
T v_min(const vector<T>& vec){
    T min=vec[0];
    for(uint i=1; i<vec.size(); ++i){
        if(vec[i]<min){ min=vec[i]; }
    }
    return min;
}

int64 sad(const vector<int>& vA, int b){
    int64 sum=0ll;
    for(uint vi=0; vi<vA.size(); ++vi){
        sum += abs(vA[vi] - b);
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    
    vector<int> vA(N);
    for(uint i=0; i<N; ++i){
        int a; cin >> a;
        vA[i] = a-(i+1);
    }
    
    sort(vA.begin(), vA.end());
    int median = vA[N/2];

    int64 sum=0;
    for(uint i=0; i<N; ++i){
        sum += abs(vA[i]-median);
    }
    cout << sum << endl;
    
    return 0;
}
