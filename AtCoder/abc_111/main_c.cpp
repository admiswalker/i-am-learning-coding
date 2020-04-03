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

template<typename T>
vector<pair<int, T>> continuousLen(const vector<T>& v){
    
    vector<pair<int, T>> vRet; vRet.push_back(make_pair(1, v[0]));
    T prev = v[0];
    for(uint i=1; i<v.size(); ++i){
        if(prev!=v[i]){ vRet.push_back(make_pair(1, v[i])); prev=v[i]; continue; }
        ++(vRet[vRet.size()-1].first);
    }
    sort(vRet.begin(), vRet.end());
    return vRet;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n;
    int nd2 = n/2; // n div 2
    
    vector<int> vO(nd2); // odd
    vector<int> vE(nd2); // even
    for(int i=0; i<nd2; ++i){
        cin >> vO[i];
        cin >> vE[i];
    }
    sort(vO.begin(), vO.end());
    sort(vE.begin(), vE.end());
    
    vector<pair<int, int>> vCL_o = continuousLen(vO);
    vector<pair<int, int>> vCL_e = continuousLen(vE);
    
    int len_o = vCL_o[0].first;
    int len_e = vCL_e[0].first;
    int val_o = vCL_o[0].second;
    int val_e = vCL_e[0].second;
    if(val_o == val_e){
        if(vCL_o.size()==1 && len_o < len_e){ len_o = vCL_o[1].first; }
        if(vCL_e.size()==1 && len_o >=len_e){ len_e = vCL_e[1].first; }
    }
    cout << n - len_o - len_e << endl;
    
    return 0;
}
