//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

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

struct td{
    int t;
    int d;
};

bool cmp_d   (struct td& lhs, struct td& rhs){ return lhs.d < rhs.d; }
bool cmp_gr_d(struct td& lhs, struct td& rhs){ return lhs.d > rhs.d; }

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N, K; cin >> N >> K;
    vector<struct td> vTD(N); for(uint i=0; i<N; ++i){ cin >> vTD[i].t >> vTD[i].d; }
    sort(vTD.begin(), vTD.end(), cmp_gr_d);
    
    unordered_map<int, int> htUN; // a hash table for counting number of used types
    vector<struct td> vTD_rm;     // for remove
    vector<struct td> vTD_add;    // for add
    
    int64 sum =0ll;
    for(uint i=0; i<K; ++i){
        sum += vTD[i].d;
        ++htUN[ vTD[i].t ];
        if(htUN[ vTD[i].t ]>=2){ vTD_rm.push_back( vTD[i] ); }
    }
    sort(vTD_rm.begin(), vTD_rm.end(), cmp_d);
    
    for(uint i=K; i<N; ++i){
        if( htUN[ vTD[i].t ] != 0 ){ continue; }
        vTD_add.push_back( vTD[i] );
    }
    sort(vTD_add.begin(), vTD_add.end(), cmp_gr_d);
    
    int64 numT = K - vTD_rm.size(); // num of type
    int64 point = sum + numT*numT;
    uint ri=0, ai=0;
    while( ri<vTD_rm.size() && ai<vTD_add.size() ){
        if( htUN[ vTD_rm [ri].t ] == 1 ){ ++ri; continue; }
//        if( htUN[ vTD_add[ai].t ] != 0 ){ ++ai; continue; }
        sum -= vTD_rm [ri].d; ++ri; --htUN[ vTD_rm [ri].t ];
        sum += vTD_add[ai].d; ++ai; ++htUN[ vTD_add[ai].t ];
        
        ++numT;
        
        int64 tmp = sum + numT * numT;
        point = max(point, tmp);
    }
    cout << point << endl;
    
    return 0;
}
