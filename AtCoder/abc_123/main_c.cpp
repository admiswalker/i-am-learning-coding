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

/*
// WA

int64 div_ceil(int64 lhs, int64 rhs){ return (lhs-1)/rhs + 1; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64 N; cin >> N;
    
    uint num=5;
    vector<int64> v(num); for(uint i=0; i<5; ++i){ cin >> v[i]; }
    
    int64 sum=0;
    int64 min_v=N;
    for(uint i=0; i<num; ++i){
        sum += (v[i] < min_v) ? div_ceil(min_v, v[i]) : 1ull;
        min_v = min(min_v, v[i]);
    }
    
    cout << sum << endl;
    
    return 0;
}
*/

int64 div_ceil(int64 lhs, int64 rhs){ return (lhs-1)/rhs + 1; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64 N; cin >> N;
    
    uint num=5;
    vector<int64> v(num); for(uint i=0; i<5; ++i){ cin >> v[i]; }
    int minIdx  = min_element(v.begin(), v.end()) - v.begin();
    int minIdx2 = min_element(v.begin(), v.begin() + minIdx) - v.begin();
    
    int64 v_min1 = v[minIdx ];
    int64 v_min2 = v[minIdx2];
    int64 sum = 3 + div_ceil(N, v_min1) + div_ceil(v_min1, v_min2);
    
    cout << sum << endl;
    
    return 0;
}
