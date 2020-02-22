#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct edge{
private:
public:
    edge(){}
    edge(uint u_in, uint v_in, uint c_in): u(u_in), v(v_in), cost(c_in) {}
    ~edge(){}
    int u; // from
    int v; // to
    int cost;
};

void negCost_ow(vector<edge>& vEdge){
    for(uint i=0; i<vEdge.size(); ++i){
        vEdge[i].cost = -1 * vEdge[i].cost;
    }
}
void neg_ow(vector<int64>& vRhs){
    for(uint i=0; i<vRhs.size(); ++i){
        vRhs[i] = -1 * vRhs[i];
    }
}

vector<int64> bellmanFord(bool& cycleTF_out, const uint V, const uint E, const vector<edge>& vEdge, const uint begin){
    cycleTF_out = false;
    vector<int64> vCost(V); for(uint i=0; i<V; ++i){ vCost[i]=INT64_MAX; } vCost[begin]=0ll;
    uint V_m1 = V-1;
    
    for(uint vi=0; vi<V; ++vi){
        bool isUpdate = false;
        for(uint ei=0; ei<E; ++ei){
            const struct edge& e = vEdge[ei];
            
            if(vCost[e.u]==INT64_MAX){ continue; }
            if(vCost[e.v] <= vCost[e.u] + e.cost){ continue; }
            vCost[e.v] = vCost[e.u] + e.cost;
            isUpdate = true;
            
            if(vi==V_m1){ cycleTF_out=true; break; }
        }
        if(!isUpdate){ break; }
    }
    return vCost;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint V, E; cin >> V >> E;
    vector<edge> vEdge(E);
    for(uint i=0; i<E; ++i){
        uint a, b, c; cin >> a >> b >> c; --a; --b;
        vEdge[i].u    = a;
        vEdge[i].v    = b;
        vEdge[i].cost = c;
    }
    negCost_ow(vEdge);
    
    bool cycleTF; vector<int64> vCost = bellmanFord(cycleTF, V, E, vEdge, 0);
    if(cycleTF){ cout << "inf" << endl; return 0; }
    neg_ow(vCost);
    
    cout << vCost[V-1] << endl;
    
    return 0;
}
