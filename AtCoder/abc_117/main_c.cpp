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

vector<vector<int>> split_by_val(const vector<int>& vD, int val){
    vector<vector<int>> vvD;
    vector<int> tmp;
    for(uint i=0; i<vD.size(); ++i){
        if(vD[i]==val){
            vvD.push_back( tmp );
            tmp.resize(0);
            continue;
        }
        tmp.push_back( vD[i] );
    }
    vvD.push_back( tmp );
    return vvD;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<int> vX(M);
    for(uint i=0; i<M; ++i){ cin >> vX[i]; }
    sort(vX.begin(), vX.end());
    
    vector<int> vD(M-1); // val, idx
    for(uint i=0; i<M-1; ++i){ vD[i] = vX[i+1]-vX[i]; }
    
    vector<pair<int, int>> vDiff(M-1); // val, idx
    for(uint i=0; i<M-1; ++i){ vDiff[i] = make_pair(vX[i+1]-vX[i], i); }
    sort(vDiff.begin(), vDiff.end(), greater<pair<int, int>>());
    
    for(uint i=0; i<min(N-1, M-1); ++i){
        vD[ vDiff[i].second ] = INT_MAX;
    }
    vector<vector<int>> vvD = split_by_val(vD, INT_MAX);
    
    int sum=0ll;
    for(uint i=0; i<vvD.size(); ++i){
//        sum += vvX[i][ vvX[i].size()-1 ] - vvX[i][0];
        sum += std::accumulate(vvD[i].begin(), vvD[i].end(), 0);
    }
    cout << sum << endl;
    
    return 0;
}
