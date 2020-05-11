// ref: https://img.atcoder.jp/arc094/editorial.pdf
// ref: https://drken1215.hatenablog.com/entry/2018/09/08/195000

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

int64 solve(int64 a, int64 b){
    if(a==b){ return (a-1)*2; }
    int64 lim = a*b-1;
    int64 low=1, high=INT_MAX; // INT_MAX is int32 max.
    while(high - low > 1){
        int64 mid = (low+high)/2;
        int64 val = ( (mid+1)/2 )*( (mid+1) - (mid+1)/2 );
        if(val > lim){ high=mid;
        }    else    { low =mid; }
    }
    return low-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q; cin >> Q;
    for(int i=0; i<Q; ++i){
        int A, B; cin >> A >> B;
        cout << solve(A, B) << endl;
    }
    
    return 0;
}
