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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<vector<edge>> vvGraph(N);
    for(int i=0; i<M; ++i){
        int L, R, D; cin >> L >> R >> D; --L; --R;
        vvGraph[ L ].push_back( edge{R, D} );
        vvGraph[ R ].push_back( edge{L,-D} );
    }
    
    vector<int> id2cost(N, INT_MAX);
    for(int n=0; n<N; ++n){
        if(id2cost[n]!=INT_MAX){ continue; }
        id2cost[n] = 0;              // cost
        queue<int> que; que.push(n); // index (from)
        while(que.size()!=0){
            int u = que.front(); que.pop(); // index (from)
            for(int i=0; i<(int)vvGraph[u].size(); ++i){
                int v    = vvGraph[u][i].to; // u to v
                int cost = vvGraph[u][i].cost;
                
                if(id2cost[v]==INT_MAX){
                    id2cost[v] = id2cost[u]+cost; // cost of u to v.
                    que.push( v );
                }else{
                    if(id2cost[v] != id2cost[u]+cost){ cout << "No" << endl; return 0; }
                }
            }
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}
