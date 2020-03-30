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
    
    unordered_map<string, int> ht;
    
    int N; cin >> N;
    vector<string> vS(N);
    for(int i=0; i<N; ++i){ cin >> vS[i]; }
    
    string s_prev="";
    for(int i=0; i<N; ++i){
        string s=vS[i];
        if(i!=0 && s[0] != s_prev[s_prev.size()-1]){ cout << "No" << endl; return 0; }
        
        auto itr = ht.find( s );
        if(itr!=ht.end()){ cout << "No" << endl; return 0; }
        ht.insert({s, 1});
        s_prev = s;
    }
    cout << "Yes" << endl;
    
    return 0;
}
