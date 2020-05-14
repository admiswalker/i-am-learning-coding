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

vector<int> digSum(const int digs, const vector<int>& v){
    vector<int> v_dsum(digs, 0);
    for(int i=0; i<(int)v.size(); ++i){
        int tmp=v[i];
        for(int d=0; d<digs; ++d){
            if(tmp & 1){ ++(v_dsum[d]); }
            tmp >>= 1;
        }
    }
    return v_dsum;
}

vector<int> digMul(const int digs, int a, const int N){
    vector<int> v_dmul(digs, 0);
    for(int i=0; i<digs; ++i){
        if(a & 1){ v_dmul[i] = 1*N; }
        a >>= 1;
    }
    return v_dmul;
}

vector<int> dig_shift(const int digs, vector<int> v, const vector<int>& v_shiftNum){
//    vector<int> v_ret(digs);
    for(int i=0; i<(int)v.size()-1; ++i){
        int numShift = min(v[i], v_shiftNum[i]);
        v[i  ] = v[i  ] - numShift;
        v[i+1] = v[i+1] + numShift;
    }
    return v;
//    return v_ret;
}
int vec2int(const vector<int>& v){
    int ret=0;
    for(int i=v.size()-1; i>=1; --i){
        if(v[i] & 1){ ret += 1; }
        ret <<= 1;
    }
    if(v[0] & 1){ ret += 1; }
    return ret;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int digs=32;
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    vector<int> vB(N); for(int i=0; i<N; ++i){ cin >> vB[i]; }
    
    vector<int> vTmp(N);
    vector<int> vB_dsum = digSum(digs, vB);
    printn(vB_dsum); // ok
    for(int i=0; i<N; ++i){
        vector<int> vA_dmul = digMul(digs, vA[i], N);
        printn(vA_dmul); // ok
        vector<int> vS = dig_shift(digs, vB_dsum, vA_dmul);
        printn(vS); // ok ???
        vTmp[i] = vec2int( vS );
        printn(vTmp[i]); // 
    }
    
    int ans=0; for(int i=0; i<N; ++i){ ans^=vTmp[i]; }
    cout << ans << endl;
    
    return 0;
}
