//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
using namespace std;

//---

template <typename T>
inline void print(const T& rhs){ std::cout<<" = "<<rhs<<std::endl; }
template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); ++i){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
template <typename T>
inline void print(const std::vector<std::vector<T>>& rhs){
    std::cout<<" = "<<std::endl;
    std::cout<<"[[ ";
    for(uint p=0; p<rhs.size(); ++p){
        if(p!=0){ std::cout<<" [ "; }
        for(uint q=0; q<rhs[p].size(); ++q){
            std::cout<<rhs[p][q]<<' ';
        }
        if(p!=rhs.size()-1){ std::cout<<"]"<<std::endl; }
    }
    std::cout<<"]]"<<std::endl;
}
template <typename TL, typename TR>
inline void print(const std::vector<std::pair<TR,TL>>& rhs){
    std::cout<<" = [";
    uint i=0;
    for(; i<rhs.size()-1; ++i){ std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"], "; }
    std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"]]" << endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

struct edge{
    uint64 to;
    uint64 cost;
};

vector<uint64> dijkstra(const vector<vector<edge>>& graph, uint64 s){
    using P = pair<uint64,uint64>;
    
    vector<uint64> vCost(graph.size(), UINT64_MAX); vCost[s]=0ull;
    priority_queue<P,vector<P>,greater<P>> que; que.push( P(0,s) );
    
    while(!que.empty()){
        P p=que.top(); que.pop();
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
    
    int H, W; cin >> H >> W;
    vector<vector<edge>> graph(10);
    for(uint row=0; row<10; ++row){
        for(uint col=0; col<10; ++col){
            uint c; cin >> c;
            graph[col].push_back( edge{row, c} ); // reversed direction
        }
    }
    vector<uint64> vCost = dijkstra(graph, 1); // search reversed direction
    
    int64 sum=0ll;
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            int a; cin >> a;
            if(a==-1){ continue; }
            sum += vCost[a];
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
