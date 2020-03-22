#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); i++){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N, K; cin >> N >> K;
    
    vector<int> vXm, vXp; // minus, plus
    vXp.push_back(0);
    for(uint i=0; i<N; ++i){
        int x; cin>>x;
        if(x<0){ vXm.push_back(abs(x));
        } else { vXp.push_back(x);
        }
    }
    vXm.push_back(0);
    reverse(vXm.begin(), vXm.end());
    printn(vXm);
    printn(vXp);
    
    vector<int64> vXms(vXm.size()); vXms[0]=0ll; // sum
    for(uint i=1; i<vXms.size(); ++i){ vXms[i] = vXm[i] + vXms[i-1]; }
    vector<int64> vXps(vXp.size()); vXps[0]=0ll; // sum
    for(uint i=1; i<vXps.size(); ++i){ vXps[i] = vXp[i] + vXps[i-1]; }
    printn(vXms);
    printn(vXps);
    
    int64 time=INT64_MAX;
    for(uint i=0; i<K; ++i){
        if(i>=vXms.size()){ continue; }
        if(K-i>=vXps.size()){ continue; }
        cout << i << endl;
        int64 time_m=0;
        int64 time_p=0;
        if(i<vXms.size()){ time_m = vXms[i] - vXms[0]; }
        time_p = vXps[K-i] - vXps[0];
        time = min(time, time_m*2 + time_p);
        cout << i << ", " << time << endl;
    }
    cout << time << endl;
    for(uint i=0; i<K; ++i){
        if(i>=vXps.size()){ continue; }
        if(K-i>=vXms.size()){ continue; }
        int64 time_p=0;
        int64 time_m=0;
        if(i<vXps.size()){ time_p = vXps[i] - vXps[0]; }
        time_p = vXms[K-i] - vXms[0];
        time = min(time, time_p*2 + time_m);
    }
    cout << time << endl;
    
    return 0;
}
