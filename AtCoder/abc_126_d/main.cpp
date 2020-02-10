#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct edge{
private:
public:
    edge(){}
    edge(uint to_in, uint cost_in): to(to_in), cost(cost_in) {}
    ~edge(){}
    uint to;
    uint cost;
};

int invColor(int c){
    if(c==0){ return 1;
    } else  { return 0; }
}
void dfs(vector<int>& vecColor, vector<vector<edge>>& graph, int v, int c){
    if(vecColor[v]!=-1){ return; }
    vecColor[v] = c;
    for(uint i=0; i<graph[v].size(); ++i){
        uint i_next = graph[v][i].to;
        uint w_next = graph[v][i].cost;
        if(w_next % 2 == 0){ dfs(vecColor, graph, i_next,          c );
        }       else       { dfs(vecColor, graph, i_next, invColor(c)); }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<vector<edge>> graph(N);
    for(uint i=0; i<N-1; ++i){
        uint u, v, w; cin >> u >> v >> w;
        --u; --v;
        graph[u].push_back( edge(v, w) );
        graph[v].push_back( edge(u, w) );
    }
    
    vector<int> vecColor(N, -1); // not used: -1,  white: 0,  black: 1
    dfs(vecColor, graph, 0, 0);
    
    for(uint i=0; i<N; ++i){
        cout << vecColor[i] << endl;
    }
    return 0;
}
