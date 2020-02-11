#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct edge{
private:
public:
    edge(){}
    edge(uint to_in, uint a_in, uint b_in) to(to_in), a(a_in), b(b_in) {}
    ~edge(){}
    uint to;
    uint a; // Yen
    uint b; // Snuuk
};

uint edge2cost(edge val, uint i, uint n){
    if(i<n){ return val.a;
    } else { return val.b; }
}

vector<uint64> dijkstra(uint s, uint n){
    vector<vector<uint64>> vvec;
    ;
    return ;
}
vector<vector<uint64>> dijkstra_n(uint s, uint n){
    vector<vector<uint64>> vvec(n);
    for(uint i=0; i<n; ++i){
        vvec[n] = dijkstra(s, i);
    }
    return vvec;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint n, m, s, t;
    cin >> n >> m >> s >> t;
    
    vector<edge> graph(m);
    for(uint i=0; i<m; ++i){
        uint u, v, a, b;
        cin >> u >> v >> a >> b; --u; --v;
        graph[u] = edge(v, a, b);
    }
    
    vector<vector<uint64>> vecCost = dijkstra_n(s, n);
    uint64 prev=vecCost[n-1][t];
    for(int i=n-2; i>=0; --i){
        if(prev>vecCost[i][t]){ vecCost[i][t] = prev; }
    }
    for(uint i=0; i<n; ++i){
        cout << vecCost[i][t] << endl;
    }
    
    return 0;
}
