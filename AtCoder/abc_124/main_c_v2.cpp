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

int64 div_ceil(int64 lhs, int64 rhs){ return (lhs-1)/rhs + 1; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    uint oddN =div_ceil(s.size(), 2);
    uint evenN=s.size()/2;
    
    int odd0=0, odd1=0;
    int even0=0, even1=0;
    for(uint i=0; i<s.size(); ++i){
        if(i & 1){ if(s[i]=='0'){ ++odd0;  }else{ ++odd1;  }
        }  else  { if(s[i]=='0'){ ++even0; }else{ ++even1; } }
    }
    cout << min(oddN-odd0 + evenN-even1, oddN-odd1 + evenN-even0) << endl;
    
    return 0;
}
