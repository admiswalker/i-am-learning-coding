#define _GLIBCXX_DEBUG
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

vector<vector<int>> split(const vector<int>& vP){
    vector<vector<int>> vvNew;
    
    uint i=0;
    while(i<vP.size()){
        while(i<vP.size() && vP[i]==0){ ++i; } // pass empty
        
        vector<int> vNew;
        while(i<vP.size() && vP[i]!=0 ){ vNew.push_back( vP[i] ); ++i; } // copy
        vvNew.push_back( move(vNew) );
    }
    return vvNew;
}
vector<vector<int>> split(const vector<vector<int>>& vvP){
    vector<vector<int>> vvNew;
    for(uint vi=0; vi<vvP.size(); ++vi){
        vector<vector<int>> vvTmp = split( vvP[vi] );
        
        /*
        vvNew.reserve(vvNew.size() + vvTmp.size());
        std::copy(vvTmp.begin(), vvTmp.end(), std::back_inserter(vvNew));
        //*/
        for(uint i=0; i<vvTmp.size(); ++i){
            if( vvTmp[i].size()==0 ){ continue; } // rm empty
            vvNew.push_back( move(vvTmp[i]) );
        }
    }
    return vvNew;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<vector<int>> vvP(1, vector<int>(N));
    for(uint i=0; i<N; ++i){ cin>>vvP[0][i]; }
    
    int64 cnt=0ll;
    while(vvP.size()!=0){
        for(uint vi=0; vi<vvP.size(); ++vi){
            vector<int>& vP = vvP[vi];
//            if( vP.size()==0 ){ continue; } // rm empty
            
            int minVal = *std::min_element(vP.begin(), vP.end());
            cnt += minVal;
            
            for(uint i=0; i<vP.size(); ++i){ vP[i] -= minVal; }
        }
        
        vvP = split( vvP );
    }
    cout << cnt << endl;
    
    return 0;
}
