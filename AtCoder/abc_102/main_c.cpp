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
    
    int N; cin >> N;
    
    vector<int> vA(N);
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        vA[i] = a-(i+1);
    }
    
    int64 max=v_max(vA);
    int64 min=v_min(vA);
    /*
    int64 min_sad=sad(vA, minn);
    for(int64 i=min+1; i<=max; ++i){
        int64 tmp=sad(vA, i);
        if(tmp < min_sad){ min_sad=tmp; }
    }
    cout << min_sad << endl;
    //*/
    
    // binary search
    int64 sadVal_prev=sad(vA, min);
    while(max-min>1){
        int64 mid = (max+min)/2;
        int64 sadVal=sad(vA, mid);
        if(sadVal<sadVal_prev){
            min = mid;
            sadVal_prev = sadVal;
        }else{
            max = mid;
        }
    }
    cout << sadVal_prev << endl;
    
    return 0;
}
