#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int min(const vector<int>& v){
    int ret = v[0];
    for(uint i=1; i<v.size(); ++i){
        if(ret < v[i]){ ret=v[i]; }
    }
    return ret;
}

int64 gcd(int64 u, int64 v){
    while(u!=0&&v!=0){
        u = u%v;
        swap(u, v);
    }
    return max(u, v);
}

int64 fn(const vector<int>& v, const int mod){
    int64 sum=0ll;
    for(uint i=0; i<v.size(); ++i){
        sum += mod % v[i];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vA(N);
    for(uint i=0; i<N; ++i){ cin>>vA[i]; }
    
    int min_m1 = min(vA) - 1;
    
    int64 lcmn=1ll;
    for(uint i=0; i<N; ++i){
        int64 gcdn = gcd(lcmn, vA[i]);
        lcmn = lcmn/gcdn*vA[i];
    }
    cout << min_m1 << endl;
    cout << lcmn << endl;
    
    int64 ans=0ll;
    for(int64 mod=min_m1; mod<lcmn; ++mod){
        ans = fn(vA, mod);
    }
    cout << ans << endl;
    
    return 0;
}
