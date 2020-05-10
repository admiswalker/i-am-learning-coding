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

template<typename T>
T nearest_down(const vector<T>& v, const T& value){
    uint idx = upper_bound(v.begin(), v.end(), value) - v.begin();
    return v[ (idx!=0 ? idx-1:0) ];
}
template<typename T>
T nearest_up  (const vector<T>& v, const T& value){
    uint idx = lower_bound(v.begin(), v.end(), value) - v.begin();
    return v[ (idx!=v.size() ? idx:v.size()-1) ];
}
template<typename T>
T nearest(const vector<T>& v, const T& value){
    T val1 = nearest_down(v, value);
    T val2 = nearest_up  (v, value);
    return (abs(val1-value)<abs(val2-value) ? val1 : val2);
}
template<typename T>
uint argnearest_down(const vector<T>& v, const T& value){
    uint idx = upper_bound(v.begin(), v.end(), value) - v.begin();
    return (idx!=0 ? idx-1:0);
}
template<typename T>
uint argnearest_up(const vector<T>& v, const T& value){
    uint idx = lower_bound(v.begin(), v.end(), value) - v.begin();
    return (idx!=v.size() ? idx:v.size()-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    sort(vA.begin(), vA.end());

    int maxVal = vA[vA.size()-1];
    int nHalf = nearest(vA, maxVal/2);
    if(maxVal==nHalf){ nHalf=vA[0]; }
    
    cout << maxVal << ' ' << nHalf << endl;
    
    return 0;
}
