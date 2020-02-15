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
    edge(uint to_in, uint a_in, uint b_in): to(to_in), a(a_in), b(b_in) {}
    ~edge(){}
    uint to;
    uint a; // Yen
    uint b; // Snuuk
};

uint edge2cost(edge val, bool ab){ return ab ? val.a : val.b; }

vector<uint64> dijkstra(const vector<vector<edge>>& graph, uint s, bool ab){
    vector<uint64> vCost(graph.size(), UINT64_MAX); vCost[s]=0ull;
    priority_queue<P,vector<P>,greater<P>> que; que.push( P(0,s) );
    
    while(!que.empty()){
        P p = que.top(); que.pop();
        uint64 cost = p.first;
        uint64 idx  = p.second;
        if(vCost[idx] < cost){ continue; }
        for(uint i=0; i<graph[idx].size(); ++i){
            edge e = graph[idx][i];
            if(vCost[e.to] <= vCost[idx] + edge2cost(e, ab)){ continue; }
            vCost[e.to] = vCost[idx] + edge2cost(e, ab);
            que.push( P(vCost[e.to], e.to) );
        }
    }
    return vCost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint n, m, s, t;
    cin >> n >> m >> s >> t; --s; --t;
    
    vector<vector<edge>> graph(n);
    for(uint i=0; i<m; ++i){
        uint u, v, a, b;
        cin >> u >> v >> a >> b; --u; --v;
        graph[u].push_back( edge(v, a, b) );
        graph[v].push_back( edge(u, a, b) );
    }
    
    vector<uint64> ret = dijkstra(graph, s, true);
    cout << ret[t] << endl;
    
    return 0;
}
