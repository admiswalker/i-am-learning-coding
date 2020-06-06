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
uint argnearest_up(const vector<T>& v, const T& value){
    uint idx = lower_bound(v.begin(), v.end(), value) - v.begin();
    return (idx!=v.size() ? idx:v.size()-1);
}

int max(const vector<int>& v){
    int m = v[0];
    for(uint i=0; i<v.size(); ++i){ m = (v[i]<m ? m : v[i]); }
    return m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    
    vector<pair<int,int>> vFT;
    if(max(vA) > 0){
        for(int i=1; i<N; ++i){
            while(!(vA[i-1]<=vA[i])){
                vector<int> vA_s = vA; sort(vA_s.begin(), vA_s.end());
            
                vector<pair<int,int>> vA_sp(N);
                for(int i=0; i<N; ++i){
                    vA_sp[i].first  = vA[i];
                    vA_sp[i].second = i;
                }
                sort(vA_sp.begin(), vA_sp.end());
                
                int val = vA[i-1] - vA[i];
                int from_s = argnearest_up(vA_s, val);
                int from = vA_sp[ from_s ].second;
                int to   = i;
                vFT.push_back(make_pair(from+1, to+1));
            
                vA[to] += vA[from];
            }
        }
    }else{
        for(int i=N-1; i>=1; --i){
            while(!(vA[i-1]<=vA[i])){
                vector<int> vA_s = vA; sort(vA_s.begin(), vA_s.end());
                
                vector<pair<int,int>> vA_sp(N);
                for(int i=0; i<N; ++i){
                    vA_sp[i].first  = vA[i];
                    vA_sp[i].second = i;
                }
                sort(vA_sp.begin(), vA_sp.end());
                
                int val = vA[i] - vA[i-1];
                int from_s = argnearest_up(vA_s, val);
                int from = vA_sp[ from_s ].second;
                int to   = i;
                vFT.push_back(make_pair(to+1, from+1));
                
                vA[from] += vA[to];
            }
        }
    }
    
    cout << vFT.size() << endl;
    for(uint i=0; i<vFT.size(); ++i){
        cout << vFT[i].first  << ' ' << vFT[i].second << endl;
    }

//    printn(vA);
    
    return 0;
}
