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
    edge(uint to_in, uint cost_in): to(to_in), cost(cost_in) {}
    ~edge(){}
    uint to;
    uint cost;
};

vector<uint64> dijkstra(const vector<vector<edge>>& graph, uint s){
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

uint cost_u2v(const vector<vector<edge>>& graph_a, uint u, uint v){
    vector<uint64> vCost = dijkstra(graph_a, u);
    return vCost[v];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint n, m, s, t;
    cin >> n >> m >> s >> t; --s; --t;
    
    vector<vector<edge>> graph_a(n), graph_b(n);
    for(uint i=0; i<m; ++i){
        uint u, v, a, b;
        cin >> u >> v >> a >> b; --u; --v;
        
        graph_a[u].push_back( edge(v, a) );
        graph_b[u].push_back( edge(v, b) );
        
        graph_a[v].push_back( edge(u, a) );
        graph_b[v].push_back( edge(u, b) );
    }
    
    for(uint i=0; i<n; ++i){
        uint ret;
        if(i<){
            ret = cost_u2v(graph_a, s, t);
        }else{
        }
        cout << ret << endl;
    }
    
    return 0;
}
