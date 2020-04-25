//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

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

int arg_nearest(const vector<int64>& v, int64 dst){
    int l_idx = 0;
    int r_idx = v.size() - 1;
    
    if(dst <= v[l_idx]){ return l_idx; }
    if(dst >= v[r_idx]){ return r_idx; }
    while(r_idx - l_idx > 1){ // binary search
        int n_idx = (l_idx + r_idx)/2;
        if(dst <= v[n_idx]){ r_idx = n_idx;
        }      else       { l_idx = n_idx; }
    }
    return (abs(v[l_idx]-dst) < abs(v[r_idx]-dst) ? l_idx : r_idx); // return neatest index with value.
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int A, B, Q; cin >> A >> B >> Q;
    vector<int64> vS(A); for(int i=0; i<A; ++i){ cin>>vS[i]; } sort(vS.begin(), vS.end());
    vector<int64> vT(B); for(int i=0; i<B; ++i){ cin>>vT[i]; } sort(vT.begin(), vT.end());
    vector<int64> vX(Q); for(int i=0; i<Q; ++i){ cin>>vX[i]; }
    
    for(int i=0; i<Q; ++i){
        int idx1, idx2;
        
        int64 tmp1=0;
        idx1 = arg_nearest(vS, vX[i]   ); tmp1 += abs(vS[idx1] - vX[i]   );
        idx2 = arg_nearest(vT, vS[idx1]); tmp1 += abs(vT[idx2] - vS[idx1]);
        
        int64 tmp2=0;
        idx1 = arg_nearest(vT, vX[i]   ); tmp2 += abs(vT[idx1] - vX[i]   );
        idx2 = arg_nearest(vS, vT[idx1]); tmp2 += abs(vS[idx2] - vT[idx1]);
        
        cout << min(tmp1, tmp2) << endl;
    }
    
    return 0;
}
