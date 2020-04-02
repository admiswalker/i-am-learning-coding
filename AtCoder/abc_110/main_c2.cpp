// ref: https://drken1215.hatenablog.com/entry/2018/09/23/232100


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
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S; cin >> S;
    string T; cin >> T;
    uint N=S.size();
    
    unordered_map<char, char> cnv_s2t('z'-'a'+1);
    unordered_map<char, char> cnv_t2s('z'-'a'+1);
    
    bool TF=true;
    for(uint i=0; i<N; ++i){
        char s = S[i];
        char t = T[i];
        
        auto itr_s = cnv_s2t.find(s);
        auto itr_t = cnv_t2s.find(t);
        if(itr_s!=cnv_s2t.end() && cnv_s2t[s]!=t){ TF=false; break; }
        if(itr_t!=cnv_t2s.end() && cnv_t2s[t]!=s){ TF=false; break; }
        cnv_s2t[s] = t;
        cnv_t2s[t] = s;
    }
    cout << (TF ? "Yes":"No") << endl;
    
    return 0;
}
