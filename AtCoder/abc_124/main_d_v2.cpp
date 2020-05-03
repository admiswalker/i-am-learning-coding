// ref: https://drken1215.hatenablog.com/entry/2019/04/14/222900

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
    
    int N, K; cin >> N >> K;
    string s; cin >> s;
    
    vector<int> vCL; // continuous length
    if(s[0]=='0'){ vCL.push_back(0); } // while the head is '0'.
    for(int i=0; i<N; ++i){
        int len=1;
        while(i<N-1 && s[i]==s[i+1]){ ++len; ++i; }
        vCL.push_back(len);
    }
    if(s.back()=='0'){ vCL.push_back(0); } // while the tail is '0'.
    
    vector<int> vCSum(vCL.size()+1, 0); // cumulative sum
    for(int i=0; i<(int)vCL.size(); ++i){ vCSum[i+1] = vCSum[i] + vCL[i]; }
    
    int maxLen;
    for(int begin=0; begin<(int)vCSum.size(); begin+=2){
        int end = begin + 2*K+1; end=min(end, (int)vCSum.size()-1);
        maxLen = max(maxLen, vCSum[end] - vCSum[begin]);
    }
    cout << maxLen << endl;
    
    return 0;
}
