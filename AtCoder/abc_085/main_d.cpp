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

int max(const vector<int>& v){
    int ret = v[0];
    for(uint i=1; i<v.size(); ++i){
        if(v[i] > ret){ ret = v[i]; }
    }
    return ret;
}
int64 div_ceil(int64 lhs, int64 rhs){ return (lhs-1)/rhs + 1; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, H; cin >> N >> H;
    vector<int> vA(N), vB(N); for(int i=0; i<N; ++i){ cin >> vA[i] >> vB[i]; }
    
    int vA_max = max(vA);
    
    vector<int> vB_g; // greater than vA_max.
    for(uint i=0; i<vB.size(); ++i){ if(vB[i]>vA_max){ vB_g.push_back(vB[i]); } }
    sort(vB_g.begin(), vB_g.end(), greater<int>());
    
    int cnt=0;
    for(uint i=0; i<vB_g.size(); ++i){
        H -= vB_g[i]; ++cnt;
        if(H<=0){ cout << cnt << endl; return 0; }
    }
    
    cout << cnt + div_ceil(H, vA_max) << endl;
    
    return 0;
}
