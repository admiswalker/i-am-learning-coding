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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vA1(N+2, 0); for(int i=1; i<=N; ++i){ int tmp;cin>>tmp; vA1[i]=vA1[i-1]+tmp; } vA1[N+1]=vA1[N];
    vector<int> vA2(N+2, 0); for(int i=1; i<=N; ++i){ int tmp;cin>>tmp; vA2[i]=vA2[i-1]+tmp; } vA2[N+1]=vA2[N];
    
    int sum=0;
    for(int i=1; i<=N; ++i){
        int s1 = vA1[i]-vA1[0];   // (0, i] -> [1, i]
        int s2 = vA2[N]-vA2[i-1]; // (i-1, N] -> [i, N]
        sum = max(sum, s1+s2);
    }
    
    cout << sum << endl;
    
    return 0;
}
