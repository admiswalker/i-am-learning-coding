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
    int to;
    int cost;
};

uint64 solve_prime(const vector<vector<edge>>& graph){
    const uint& N = graph.size();
    vector<bool> vUsed(N, false);
    vector<int> vCost_min(N, INT_MAX); vCost_min[0]=0;
    
    int64 sum_cost=0ull;
    for(;;){
        int minIdx=-1;
        for(uint i=0; i<N; ++i){
            if(!vUsed[i] && (minIdx==-1 || vCost_min[i]<vCost_min[minIdx])){ minIdx=i; }
        }
        if(minIdx==-1){ break; }
        
        vUsed[minIdx] = true;
        sum_cost += (uint64)vCost_min[minIdx];
        
        for(uint i=0; i<graph[minIdx].size(); ++i){
            edge e = graph[minIdx][i];
            vCost_min[e.to] = min(vCost_min[e.to], e.cost);
        }
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
    
    vector<vector<edge>> graph(N);
    for(int i=0; i<N-1; ++i){
        int cost_x = costAB(vXY_x[i], vXY_x[i+1]);
        graph[ vXY_x[i  ].idx ].push_back( edge(vXY_x[i+1].idx, cost_x) );
        graph[ vXY_x[i+1].idx ].push_back( edge(vXY_x[i  ].idx, cost_x) );
        
        int cost_y = costAB(vXY_y[i], vXY_y[i+1]);
        graph[ vXY_y[i  ].idx ].push_back( edge(vXY_y[i+1].idx, cost_y) );
        graph[ vXY_y[i+1].idx ].push_back( edge(vXY_y[i  ].idx, cost_y) );
    }
    
    cout << solve_prime(graph) << endl;
    
    return 0;
}
