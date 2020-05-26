// ref: https://web.archive.org/web/20200525161650/https://webcache.googleusercontent.com/search?q=cache:02O8gvmgmdkJ:https://dalekspritner.hatenablog.com/entry/2018/09/14/050526+&cd=1&hl=ja&ct=clnk&gl=jp
// ref: https://atcoder.jp/contests/abc087/submissions/3187335

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

struct edge{
    int to;
    int cost;
};

bool DFS(vector<int>& vDist, const vector<vector<edge>>& vGraph, int u, int d){
    // u: from
    // v: to
    
    if( vDist[u]!=INT_MAX && d!=vDist[u]){ return false; }
    if( vDist[u]!=INT_MAX && d==vDist[u]){ return true; }
    
    vDist[u] = d;
    for(uint v=0; v<vGraph[u].size(); ++v){
        if(! DFS(vDist, vGraph, vGraph[u][v].to, d + vGraph[u][v].cost) ){ return false; }
    }
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<vector<edge>> vGraph(N);
    for(int i=0; i<M; ++i){
        int L, R, D; cin >> L >> R >> D;  --L, --R;
        vGraph[ L ].push_back( edge{R, D} );
        vGraph[ R ].push_back( edge{L,-D} );
    }
    
    vector<int> vDist(N, INT_MAX);
    for(int i=0; i<N; ++i){
        if(vDist[i]!=INT_MAX){ continue; }
        if(!DFS(vDist, vGraph, i, 0)){ cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
    
    return 0;
}

// 92 ms
