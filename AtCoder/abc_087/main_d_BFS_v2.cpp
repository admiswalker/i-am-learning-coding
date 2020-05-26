// ref: https://yamakasa.net/atcoder-abc-087-d/

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

bool BFS(vector<int>& vDist, const vector<vector<edge>>& vGraph, int begin){
    vDist[begin] = 0; // cost
    queue<int> que; que.push(begin); // index (from)
    while(que.size()!=0){
        int u = que.front(); que.pop(); // index (from)
        for(int i=0; i<(int)vGraph[u].size(); ++i){
            int v    = vGraph[u][i].to; // u to v
            int cost = vGraph[u][i].cost;
            
            if(vDist[v]!=INT_MAX && vDist[v]!=vDist[u]+cost){ return false; }
            if(vDist[v]==INT_MAX){
                vDist[v] = vDist[u]+cost; // cost of u to v.
                que.push( v );
            }
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<vector<edge>> vGraph(N);
    for(int i=0; i<M; ++i){
        int L, R, D; cin >> L >> R >> D; --L; --R;
        vGraph[ L ].push_back( edge{R, D} );
        vGraph[ R ].push_back( edge{L,-D} );
    }
    
    vector<int> vDist(N, INT_MAX);
    for(int i=0; i<N; ++i){
        if(vDist[i]!=INT_MAX){ continue; }
        if(! BFS(vDist, vGraph, i)){ cout << "No" << endl; return 0; }
    }
    cout << "Yes" << endl;
    
    return 0;
}

// 97 ms
