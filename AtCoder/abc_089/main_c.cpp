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
    vector<unordered_map<string,int>> ht(5);
    
    for(int i=0; i<N; ++i){
        string s; cin >> s;
        if(s[0]=='M'){ ht[0][s]+=1; continue; }
        if(s[0]=='A'){ ht[1][s]+=1; continue; }
        if(s[0]=='R'){ ht[2][s]+=1; continue; }
        if(s[0]=='C'){ ht[3][s]+=1; continue; }
        if(s[0]=='H'){ ht[4][s]+=1; continue; }
    }
    
    int64 sum=0ll;
    for(uint i=0; i<(uint)1<<ht.size(); ++i){
        uint bit=i;
        if(__builtin_popcount(bit)!=3){ continue; }
        
        int64 mul=1ll;
        for(uint i=0; i<ht.size(); ++i, bit>>=1){
            if(bit & 1){ mul*=ht[i].size(); }
        }
        sum+=mul;
    }
    
    cout << sum << endl;
    
    return 0;
}
