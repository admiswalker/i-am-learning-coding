// ref: https://img.atcoder.jp/abc119/editorial.pdf
// ref: https://drken1215.hatenablog.com/entry/2019/02/24/224100

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

int solve_rec(const int A, const int B, const int C,
              const vector<int>& vL, int i, int a, int b, int c)
{
    if(i==(int)vL.size()){
        if(a==0 || b==0 || c==0){ return INT_MAX-10000; }
        return abs(a-A) + abs(b-B) + abs(c-C) - 30;
    }
    
    int ret0 = solve_rec(A,B,C, vL, i+1, a      , b      , c      );
    int ret1 = solve_rec(A,B,C, vL, i+1, a+vL[i], b      , c      ) + 10;
    int ret2 = solve_rec(A,B,C, vL, i+1, a      , b+vL[i], c      ) + 10;
    int ret3 = solve_rec(A,B,C, vL, i+1, a      , b      , c+vL[i]) + 10;
    
    return min(min(ret0, ret1), min(ret2, ret3));
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N; int A, B, C; cin >> N >> A >> B >> C;
    vector<int> vL(N); for(int i=0; i<N; ++i){ cin>>vL[i]; }
    
    cout << solve_rec(A,B,C, vL, 0, 0, 0, 0) << endl;
    
    return 0;
}
