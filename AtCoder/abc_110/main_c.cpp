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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    string S; cin >> S;
    string T; cin >> T;
    uint N = S.size();
    
    vector<pair<int, vector<int>>> vAZ_s( 'z'-'a'+1 );
    vector<pair<int, vector<int>>> vAZ_t( 'z'-'a'+1 );
    for(uint i=0; i<N; ++i){ vAZ_s[i].first = -1; }
    for(uint i=0; i<N; ++i){ vAZ_t[i].first = -1; }
    
    for(uint i=0; i<N; ++i){
        int idx = S[i]-'a';
        if(vAZ_s[idx].first==-1){ vAZ_s[idx].first = idx;
        }          else         { vAZ_s[idx].second.push_back( idx ); }
    }
    for(uint i=0; i<N; ++i){
        int idx = T[i]-'a';
        if(vAZ_t[idx].first==-1){ vAZ_t[idx].first = idx;
        }          else         { vAZ_t[idx].second.push_back( idx ); }
    }
    sort(vAZ_s.begin(), vAZ_s.end());
    sort(vAZ_t.begin(), vAZ_t.end());
    
    for(uint i=0; i<N; ++i){
        if(vAZ_s[i].first != vAZ_t[i].first){ cout << "No" << endl; return 0; }
        
        if(vAZ_s[i].second.size() != vAZ_t[i].second.size()){ cout << "No" << endl; return 0; }
        uint size = vAZ_s[i].second.size();
        for(uint ci=0; ci<size; ++ci){
            if(vAZ_s[i].second[ci]!=vAZ_s[i].second[ci]){ cout << "No" << endl; return 0; }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}
