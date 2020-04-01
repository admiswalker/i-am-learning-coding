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
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

int min_v(const vector<int>& vRhs){
    int ret = vRhs[0];
    for(uint i=1; i<vRhs.size(); ++i){ ret=min(ret, vRhs[i]); }
    return ret;
}
int max_v(const vector<int>& vRhs){
    int ret = vRhs[0];
    for(uint i=1; i<vRhs.size(); ++i){ ret=max(ret, vRhs[i]); }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, X, Y; cin >> N >> M >> X >> Y;
    vector<int> vX(N+1); for(int i=0; i<N; ++i){ cin >> vX[i]; } vX[N]=X;
    vector<int> vY(M+1); for(int i=0; i<M; ++i){ cin >> vY[i]; } vY[M]=Y;
    int x_max = max_v(vX);
    int y_min = min_v(vY);
    
    cout << (x_max<y_min ? "No War":"War") << endl;
    
    return 0;
}
