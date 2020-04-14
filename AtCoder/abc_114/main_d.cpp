// ref: https://drken1215.hatenablog.com/entry/2019/05/13/112000
// ref: https://img.atcoder.jp/abc114/editorial.pdf

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

vector<pair<int64, uint>> factor(int64 n){
    vector<pair<int64, uint>> vPN;
    for(int64 p=2; p*p<=n; ++p){
        if(n % p != 0){ continue; }
        
        int num=1; n/=p;
        while(n % p == 0){ ++num; n/=p; }
        vPN.push_back( make_pair(p, num) );
    }
    if(n != 1ll){ vPN.push_back( make_pair(n, 1) ); }
    return vPN;
}

int solver(const unordered_map<int64, uint>& ht, unordered_map<int64, uint>::iterator itr, int64 num){
    if(itr==ht.end()){
        return ( num==1 ? 1:0 );
    }
    
    int64 sum=0;
    for(uint i=1; i <=(itr->second +1); ++i){
        if(num % i !=0){ continue; }
        auto itr_buf = itr;
        sum += solver(ht, ++itr_buf, num/i);
    }
    return sum;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    unordered_map<int64, uint> ht;
    
    uint N; cin >> N;
    for(uint i=2; i<=N; ++i){
        vector<pair<int64, uint>> vPN = factor(i);
        for(uint i=0; i<vPN.size(); ++i){
            ht[ vPN[i].first ] += vPN[i].second;
        }
    }
    cout << solver(ht, ht.begin(), 75) << endl;
    
    
    return 0;
}
