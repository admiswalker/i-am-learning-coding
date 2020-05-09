// ref: https://img.atcoder.jp/arc096/editorial.pdf

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
    vector<int64> ret; ret.push_back( 0ll );
    int64 maxKCal=0;
    for(uint i=0; i<v.size(); ++i){
        maxKCal = max(maxKCal, v[i]);
        ret.push_back( maxKCal );
    }
    return ret;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N, C; cin >> N >> C;
    vector<int64> vDistR(N+1, 0ll); // distance
    vector<int64> vKCal (N+1, 0ll); // kcal
    for(int i=1; i<=N; ++i){ cin >> vDistR[i] >> vKCal[i]; }
    
    vector<int64> vDistL(N+1, 0ll); // distance
    for(int i=1; i<=N; ++i){ vDistL[N+1-i] = C - vDistR[i]; }
    
    printn(vDistR);
    printn(vDistL);
    printn(vKCal);
    
    // R: clockwise
    vector<int64> vR;
    int64 prevKCal=0, prevDist=0;
    for(int i=0; i<=N; ++i){
        int64 kcal = prevKCal + vKCal[i] - (vDistR[i] - prevDist);
        vR.push_back( kcal );
        prevKCal = kcal;
        prevDist = vDistR[i];
    }
    vector<int64> vR_max = v_max(vR);
    printn(vR);
    
    // L: counterclockwise
    vector<int64> vL;
    prevKCal=0, prevDist=0;
    for(int i=N; i>=0; --i){
        int64 kcal = prevKCal + vKCal[i] - (vDistL[i] - prevDist);
        vL.push_back( kcal );
        prevKCal = kcal;
        prevDist = vDistL[i];
    }
    vector<int64> vL_max = v_max(vL);
    printn(vL);
    
    
    int64 sum=0;
    // R: clockwise
    for(int i=0; i<=N; ++i){
        int64 tmp1 = vR[i];
        int64 tmp2 = vR[i] + vL_max[N-i] - vDistR[i];
        sum = max(sum, max(tmp1, tmp2));
    }
    // L: counterclockwise
    for(int i=0; i<=N; ++i){
        int64 tmp1 = vL[i];
        int64 tmp2 = vL[i] + vR_max[N-i] - vDistL[i];
        sum = max(sum, max(tmp1, tmp2));
    }
    
    cout << sum << endl;
    
    return 0;
}
