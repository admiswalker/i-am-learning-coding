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

vector<vector<int>> split(vector<int>& vP){
    vector<vector<int>> vvNew;
    
    uint i=0;
    while(i<vP[i].size()){
        while(i<vP[i].size() && vP[i]==0){ ++i; } // pass empty
        
        vector<int> vNew;
        while( vP[i]!=0 ){ vNew.push_back( vP[i] ); ++i; } // copy
        vvNew.push_back( vNew );
    }
    return vvNew;
}
vector<vector<int>> split(vector<vector<int>>& vvP){
    vector<int> vvNew;
    for(uint vi=0; vi<vvP.size(); ++vi){
        vector<vector<int>> vvTmp = split(vector<int>& vP);
        
        for(uint i=0; i<vvTmp.size(); ++i){
            vvNew.push_back( move(vvTmp[i]) );
        }
    }
    return vvNew;
}

void minus_min(vector<int> & vvP){
    return ;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vH(N);
    for(uint k=1; k<=N; ++k){ int tmp; cin>>tmp; vH[k]=k-tmp; }
    
    vector<struct pm> vPM = split(vPM);
    
    int64 cnt=0;
    while(vPM.size()!=0){
        vvPN = minus_min(vPM);
        vvPN = split(vvPN);
        for(){
            cnt += XXXXXXXXXXXXX;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
