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

int64 div_ceil(int64 lhs, int64 rhs){ return (lhs-1)/rhs + 1; }

void solve(const int64 C, const int64 S, const int64 F, int64& now){
    int64 diff = now - S;
    if(diff > 0ll){
        now += F * div_ceil(diff, F) - diff;
    }else{
        now += abs(diff);
    }
    now += C;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<int> vC(N-1), vS(N-1), vF(N-1);
    for(int i=0; i<N-1; ++i){
        cin >> vC[i] >> vS[i] >> vF[i];
    }
    
    for(int b=0; b<N-1; ++b){
        int64 now = 0ll;
        for(int i=b; i<N-1; ++i){
            solve(vC[i], vS[i], vF[i], now);
        }
        cout << now << endl;
    }
    cout << '0' << endl;
    
    return 0;
}
