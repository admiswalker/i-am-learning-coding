// ref: https://img.atcoder.jp/arc092/editorial.pdf

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
using namespace std;

//---

template <typename T>
inline void print(const T& rhs){ std::cout<<" = "<<rhs<<std::endl; }
template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); ++i){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
template <typename T>
inline void print(const std::vector<std::vector<T>>& rhs){
    std::cout<<" = "<<std::endl;
    std::cout<<"[[ ";
    for(uint p=0; p<rhs.size(); ++p){
        if(p!=0){ std::cout<<" [ "; }
        for(uint q=0; q<rhs[p].size(); ++q){
            std::cout<<rhs[p][q]<<' ';
        }
        if(p!=rhs.size()-1){ std::cout<<"]"<<std::endl; }
    }
    std::cout<<"]]"<<std::endl;
}
template <typename TL, typename TR>
inline void print(const std::vector<std::pair<TR,TL>>& rhs){
    std::cout<<" = [";
    uint i=0;
    for(; i<rhs.size()-1; ++i){ std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"], "; }
    std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"]]" << endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

vector<int> mask(const vector<int>& vB, const int k){
    int m=1; for(int i=0; i<k; ++i){ m<<=1; m+=1; }
    vector<int> v_ret=vB; for(uint i=0; i<v_ret.size(); ++i){ v_ret[i]&=m; }
    return v_ret;
}

int cnt_range(const vector<int>& v, const int a, const int b){ // [a, b)
    int lo = lower_bound(v.begin(), v.end(), a) - v.begin();
    int hi = lower_bound(v.begin(), v.end(), b) - v.begin() - 1;
    return hi-lo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int digs=28+1;
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    vector<int> vB(N); for(int i=0; i<N; ++i){ cin >> vB[i]; }
    
    int ans=0;
    for(int k=digs-1; k>=0; --k){
        ans <<= 1;
        vector<int> vA_m = mask(vA, k);
        vector<int> vB_m = mask(vB, k);
        sort(vB_m.begin(), vB_m.end());
        vB_m.push_back( INT_MAX );
        
        int cnt = 0;
        int T=1<<k; // pow(2, k)
        for(int i=0; i<N; ++i){
            cnt += cnt_range(vB_m, 1*T-vA_m[i], 2*T-vA_m[i]); // [ T, 2T)
            cnt += cnt_range(vB_m, 3*T-vA_m[i], 4*T-vA_m[i]); // [3T, 4T)
        }
        if(cnt & 1){ ans+=1; }
    }
    
    cout << ans << endl;
    
    return 0;
}
