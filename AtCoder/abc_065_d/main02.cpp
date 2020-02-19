#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct edge{
private:
public:
    edge(){}
    edge(uint u_in, uint v_in, uint cost_in): u(u_in), v(v_in), cost(cost_in) {}
    ~edge(){}
    int u; // from
    int v; // to
    int cost;
};
bool cmp(const struct edge& lhs, const struct edge& rhs){ return lhs.cost < rhs.cost; }

class unionFind{
private:
    vector<uint> vParent;
    vector<uint> vRank;
public:
    unionFind(uint size){
        vParent.resize(size); for(uint i=0; i<size; ++i){ vParent[i]=i; }
        vRank.resize(size, 0);
    }
    ~unionFind(){}
    
    uint find(uint rhs){
        if(rhs == vParent[rhs]){ return rhs;
        }          else        { return vParent[rhs] = find( vParent[rhs] ); }
    }
    void unite(const uint& lhs, const uint& rhs){
        uint root_l = find(lhs);
        uint root_r = find(rhs);
        if(root_l == root_r){ return; }
        
        if(vRank[root_l] < vRank[root_r]){ vParent[root_l]=root_r;
        }              else              { vParent[root_r]=root_l; if(vRank[root_l] == vRank[root_r]){ ++vRank[root_l]; } }
    }
    bool same(const uint& lhs, const uint& rhs){ return find(lhs)==find(rhs); }
};

uint64 solve_kruskal(vector<edge>& vEdge){
    sort(vEdge.begin(), vEdge.end(), cmp);
    
    class unionFind uf(vEdge.size());
    uint64 sum_cost=0ull;
    
    for(uint i=0; i<vEdge.size(); ++i){
        struct edge e = vEdge[i];
        if(uf.same(e.u, e.v)){ continue; }
        uf.unite(e.u, e.v);
        sum_cost += e.cost;
    }
    return sum_cost;
}

struct vertex{
private:
public:
    vertex(){}
    vertex(uint idx_in, uint x_in, uint y_in): idx(idx_in), x(x_in), y(y_in) {}
    ~vertex(){}
    int idx;
    int x;
    int y;
};
bool cmp_x(const struct vertex& lhs, const struct vertex& rhs){ return lhs.x < rhs.x; }
bool cmp_y(const struct vertex& lhs, const struct vertex& rhs){ return lhs.y < rhs.y; }
int costAB(const struct vertex& lhs, const struct vertex& rhs){ return min(abs(lhs.x-rhs.x), abs(lhs.y-rhs.y)); }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<vertex> vXY(N);
    for(int i=0; i<N; ++i){
        int x, y; cin >> x >> y;
        vXY[i].idx = i;
        vXY[i].x   = x;
        vXY[i].y   = y;
    }
    
    vector<vertex> vXY_x=vXY; sort(vXY_x.begin(), vXY_x.end(), cmp_x);
    vector<vertex> vXY_y=vXY; sort(vXY_y.begin(), vXY_y.end(), cmp_y);
    
    vector<edge> vEdge(4*N); vEdge.resize(0);
    for(int i=0; i<N-1; ++i){
        int cost_x = costAB(vXY_x[i], vXY_x[i+1]);
        vEdge.push_back( edge(vXY_x[i  ].idx, vXY_x[i+1].idx, cost_x) );
        vEdge.push_back( edge(vXY_x[i+1].idx, vXY_x[i  ].idx, cost_x) );
        
        int cost_y = costAB(vXY_y[i], vXY_y[i+1]);
        vEdge.push_back( edge(vXY_y[i  ].idx, vXY_y[i+1].idx, cost_y) );
        vEdge.push_back( edge(vXY_y[i+1].idx, vXY_y[i  ].idx, cost_y) );
    }
    
    cout << solve_kruskal(vEdge) << endl;
    
    return 0;
}
