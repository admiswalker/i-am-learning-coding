#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

struct vertex{
private:
public:
    vertex(){}
    vertex(uint idx_in, uint x_in, uint y_in): idx(idx_in), x(x_in) y(y_in) {}
    ~edge(){}
    uint idx;
    uint x;
    uint y;
};

struct edge{
private:
public:
    edge(){}
    edge(uint to_in, uint cost_in): to(to_in), cost(cost_in) {}
    ~edge(){}
    uint to;
    uint cost;
};
/*
uint64 solve_prime(const vector<vector<edge>>& graph){
    const uint& N = graph.size();
    vector<bool> vUsed(N, false);
    vector<uint64> vCost_min(N, INT64_MAX); vCost_min[0]=0ull;
    
    uint64 sum_cost=0ull;
    for(;;){
        int minIdx=-1;
        for(uint i=0; i<N; ++i){
            if(!vUsed[i] && (minIdx==-1 || vCost_min[i]<vCost_min[minIdx])){ minIdx=i; }
        }
        if(minIdx==-1){ break; }
        
        vUsed[minIdx] = true;
        sum_cost += vCost_min[minIdx];
        
        for(uint i=0; i<N; ++i){
            vector<uint64> vCost_u2v = vXY2vCost_u2v(vXY, minIdx);
            vCost_min[i] = min(vCost_min[i], vCost_u2v[i]);
        }
    }
    return sum_cost;
}
//*/

template<typename T>
bool cmp_by_second(const std::pair<T, T>& lhs, const std::pair<T, T>& rhs) {
    if(lhs.second != rhs.second){ return lhs.second < rhs.second;
    }            else           { return lhs.first  < rhs.first;  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<pair<int,int>> vXY(N);
    for(uint i=0; i<N; ++i){
        uint x, y; cin >> x >> y;
        vXY[i].first  = x;
        vXY[i].second = y;
    }
    
    vector<pair<int,int>> vXY_x = vXY; sort(vXY_x.begin(), vXY_x.end());
    vector<pair<int,int>> vXY_y = vXY; sort(vXY_y.begin(), vXY_y.end(), cmp_by_second<int>);
    
    vector<vector<edge>> graph(N);
    vXY_x[i].first  = ;
    vXY_x[i].second = ;
    graph[0].emplace_back(0, vXY_x[i].first);
    for(uint i=0; i<N; ++i){
        struct edghe buf;
        buf.to   = ;
        buf.cost = ;
        graph[i].emplace_back(buf);
    }
    
    /*
    for(uint i=0; i<N; ++i){
        cout << vXY[i].first  << endl;
        cout << vXY[i].second << endl;
        cout << endl;
    }
    //*/
//    uint64 ret = solve_prime(vXY);
//    cout << ret << endl;
    
    return 0;
}
