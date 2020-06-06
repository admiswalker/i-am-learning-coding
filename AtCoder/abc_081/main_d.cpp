// ref: https://img.atcoder.jp/arc086/editorial.pdf

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

int max(const vector<int>& v){
    int m = v[0];
    for(uint i=0; i<v.size(); ++i){ m = (v[i]>m ? v[i] : m); }
    return m;
}
int min(const vector<int>& v){
    int m = v[0];
    for(uint i=0; i<v.size(); ++i){ m = (v[i]<m ? v[i] : m); }
    return m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vA(N); for(int i=0; i<N; ++i){ cin >> vA[i]; }
    
    int minIdx = min_element(vA.begin(), vA.end()) - vA.begin();
    int maxIdx = max_element(vA.begin(), vA.end()) - vA.begin();
    
    if(abs(vA[maxIdx]) >= abs(vA[minIdx])){
        for(int i=0; i<N; ++i){
            if(i==maxIdx){ continue; }
            cout << maxIdx+1 << ' ' << i+1 << endl;
        }
        cout << maxIdx+1 << ' ' << maxIdx+1 << endl;
        
        for(int i=1; i<N; ++i){
            cout << (i-1)+1 << ' ' << (i)+1 << endl;
        }
    }else{
        for(int i=0; i<N; ++i){
            if(i==minIdx){ continue; }
            cout << minIdx+1 << ' ' << i+1 << endl;
        }
        cout << minIdx+1 << ' ' << minIdx+1 << endl;
        
        for(int i=N-1; i>=1; --i){
            cout << (i)+1 << ' ' << (i-1)+1 << endl;
        }
    }
    
    return 0;
}
