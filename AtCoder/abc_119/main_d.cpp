// ref: https://drken1215.hatenablog.com/entry/2019/02/24/230900

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

int64 nearest(const vector<int64>& v, int64 dst){
    int l_idx = 0;
    int r_idx = v.size() - 1;
    
    if(dst <= v[l_idx]){ return v[l_idx]; }
    if(dst >= v[r_idx]){ return v[r_idx]; }
    while(r_idx - l_idx > 1){ // binary search
        int n_idx = (l_idx + r_idx)/2;
        if(dst < v[n_idx]){ r_idx = n_idx;
        }      else       { l_idx = n_idx; }
    }
    return (abs(v[l_idx]-dst) < abs(v[r_idx]-dst) ? v[l_idx] : v[r_idx]); // return neatest index with value.
}
pair<int,int> arg_nearest(const vector<int64>& v, int64 dst){
    int l_idx = 0;
    int r_idx = v.size() - 1;
    
    if(dst <= v[l_idx]){ return make_pair(l_idx, l_idx); }
    if(dst >= v[r_idx]){ return make_pair(r_idx, r_idx); }
    while(r_idx - l_idx > 1){ // binary search
        int n_idx = (l_idx + r_idx)/2;
        if(dst < v[n_idx]){ r_idx = n_idx;
        }      else       { l_idx = n_idx; }
    }
    return make_pair(l_idx, r_idx);
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int A, B, Q; cin >> A >> B >> Q;
    vector<int64> vS(A); for(int i=0; i<A; ++i){ cin>>vS[i]; } // sort(vS.begin(), vS.end());
    vector<int64> vT(B); for(int i=0; i<B; ++i){ cin>>vT[i]; } // sort(vT.begin(), vT.end());
    vector<int64> vX(Q); for(int i=0; i<Q; ++i){ cin>>vX[i]; }
    
    for(int i=0; i<Q; ++i){
        int idxL, idxR;
        int64 val1, val2;
        
        int64 tmp1=0ll, tmp2=0ll;
        tie(idxL, idxR) = arg_nearest(vS, vX[i]);
        val1 = nearest(vT, vS[idxL]);
        val2 = nearest(vT, vS[idxR]);
        tmp1 += abs(vS[idxL] - vX[i]   );
        tmp1 += abs( val1    - vS[idxL]);
        tmp2 += abs(vS[idxR] - vX[i]   );
        tmp2 += abs( val2    - vS[idxR]);
        tmp1 = min(tmp1, tmp2);
        
        int64 tmp3=0ll, tmp4=0ll;
        tie(idxL, idxR) = arg_nearest(vT, vX[i]);
        val1 = nearest(vS, vT[idxL]);
        val2 = nearest(vS, vT[idxR]);
        tmp3 += abs(vT[idxL] - vX[i]   );
        tmp3 += abs( val1    - vT[idxL]);
        tmp4 += abs(vT[idxR] - vX[i]   );
        tmp4 += abs( val2    - vT[idxR]);
        tmp3 = min(tmp3, tmp4);
        
        cout << min(tmp1, tmp3) << endl;
    }
    
    return 0;
}
