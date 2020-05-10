// v3
// ref: https://img.atcoder.jp/arc096/editorial.pdf
// ref: https://atcoder.jp/contests/abc095/submissions/12788641

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

vector<int64> v_max(const vector<int64>& v){
    vector<int64> ret;
    int64 maxKCal=INT_MIN;
    for(uint i=0; i<v.size(); ++i){
        maxKCal = max(maxKCal, v[i]);
        ret.push_back( maxKCal );
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // R: clockwise
    // L: counterclockwise
    
    int64 N, C; cin >> N >> C;
    vector<int64> vDistR(N+1), vKCal(N+1); // distance, kcal
    for(int i=1; i<=N; ++i){ cin >> vDistR[i] >> vKCal[i]; }
    
    vector<int64> vR(N+1); vR[0]=0ll; for(int i=1; i<=N; ++i){ vR[i] = vR[i-1] + vKCal[i]; }
    vector<int64> vL(N+1); vL[0]=0ll; for(int i=1; i<=N; ++i){ vL[i] = vL[i-1] + vKCal[N+1-i]; }
    vector<int64> vR_max(N+1); vR_max[0]=0ll; for(int i=1; i<=N; ++i){ vR_max[i]=max(vR_max[i-1], vR[i]-vDistR[i]); } // kcal - dist
    vector<int64> vL_max(N+1); vL_max[0]=0ll; for(int i=1; i<=N; ++i){ vL_max[i]=max(vL_max[i-1], vL[i]-(C-vDistR[N+1-i])); } // kcal - dist
    
    int64 sum=0ll;
    // R: clockwise
    for(int i=1; i<=N; ++i){
        sum = max(sum, vR[i] -   vDistR[i]              );
        sum = max(sum, vR[i] - 2*vDistR[i] + vL_max[N-i]);
    }
    // L: counterclockwise
    for(int i=1; i<=N; ++i){
        sum = max(sum, vL[i] -   (C-vDistR[N+1-i])              );
        sum = max(sum, vL[i] - 2*(C-vDistR[N+1-i]) + vR_max[N-i]);
    }
    
    cout << sum << endl;
    
    return 0;
}
