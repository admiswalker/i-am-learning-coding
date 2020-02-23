#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct edge{
    uint to;
    uint cost;
};

vector<uint64> dijkstra(const vector<vector<edge>>& vvEdge, const uint begin){
    const uint& N = vvEdge.size();
    vector<uint64> vCost(N); for(uint i=0; i<N; ++i){ vCost[i]=UINT64_MAX; } vCost[begin]=0ull;
    
    priority_queue<pair<uint64,uint>, vector<pair<uint64,uint>>, greater<pair<uint64,uint>>> que;
    que.push( pair<uint64,uint>{0, begin} );
    
    while(!que.empty()){
        pair<uint64,uint> p = que.top(); que.pop();
        const uint64& cost = p.first;
        const uint  & idx  = p.second;
        if(vCost[idx]<cost){ continue; }
        for(uint i=0; i<vvEdge[idx].size(); ++i){
            const struct edge& e = vvEdge[idx][i];
            if( vCost[e.to] <= vCost[idx] + e.cost ){ continue; }
            vCost[e.to] = vCost[idx] + e.cost;
            que.push( {vCost[e.to], e.to} );
        }
    }
    return vCost;
}

template<typename T>
T min(const vector<T>& vRhs){
    T ret = vRhs[0];
    for(uint i=1; i<vRhs.size(); ++i){ if(vRhs[i]<ret){ ret=vRhs[i]; } }
    return ret;
}
template<typename T>
T max(const vector<T>& vRhs){
    T ret = vRhs[0];
    for(uint i=1; i<vRhs.size(); ++i){ if(vRhs[i]>ret){ ret=vRhs[i]; } }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, M; cin >> N >> M;
    vector<vector<edge>> vvEdge(N);
    for(uint i=0; i<M; ++i){
        uint a, b, c; cin >> a >> b >> c; --a; --b;
        vvEdge[a].push_back( {b, c} );
        vvEdge[b].push_back( {a, c} );
    }
    
    vector<uint64> vCost_max(N);
    for(uint i=0; i<N; ++i){
        vector<uint64> vCost = dijkstra(vvEdge, i);
        vCost_max[i] = max(vCost);
    }
    cout << min(vCost_max) << endl;
    
    return 0;
}
