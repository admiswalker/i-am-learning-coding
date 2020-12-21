#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

typedef pair<uint64,uint64> P;

struct edge{
private:
public:
    edge(){}
    edge(uint64 to_in, uint64 cost_in): to(to_in), cost(cost_in) {}
    ~edge(){}
    uint64 to;
    uint64 cost;
};

vector<uint64> dijkstra(const vector<vector<edge>>& graph, uint64 s){
    vector<uint64> vCost(graph.size(), UINT64_MAX); vCost[s]=0ull;
    priority_queue<P,vector<P>,greater<P>> que; que.push( P(0,s) );
    
    while(!que.empty()){
        P p = que.top(); que.pop();
        uint64 cost = p.first;
        uint64 idx  = p.second;
        if(vCost[idx] < cost){ continue; }
        for(uint i=0; i<graph[idx].size(); ++i){
            edge e = graph[idx][i];
            if(vCost[e.to] <= vCost[idx] + e.cost){ continue; }
            vCost[e.to] = vCost[idx] + e.cost;
            que.push( P(vCost[e.to], e.to) );
        }
    }
    return vCost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint64 n, m, s, t;
    cin >> n >> m >> s >> t; --s; --t;
    
    vector<vector<edge>> graph_a(n), graph_b(n);
    for(uint64 i=0; i<m; ++i){
        uint64 u, v, a, b;
        cin >> u >> v >> a >> b; --u; --v;
        
        graph_a[u].push_back( edge(v, a) );
        graph_b[u].push_back( edge(v, b) );
        
        graph_a[v].push_back( edge(u, a) );
        graph_b[v].push_back( edge(u, b) );
    }
    
    vector<uint64> vCost_a = dijkstra(graph_a, s); // cost of s to i as vCost_a[i].
    vector<uint64> vCost_b = dijkstra(graph_b, t); // cost of t to i as vCost_b[i].
    
    vector<uint64> vCost(n);
    vCost[n-1] = vCost_a[n-1] + vCost_b[n-1];
    for(uint i=n-2; i!=UINT_MAX; --i){
        vCost[i] = vCost_a[i] + vCost_b[i];
        if(vCost[i] > vCost[i+1]){ vCost[i] = vCost[i+1]; }
    }
    
    for(uint i=0; i<n; ++i){
        cout << (uint64)1e15 - vCost[i] << endl;
    }
    
    return 0;
}
