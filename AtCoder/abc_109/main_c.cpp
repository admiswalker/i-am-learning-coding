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

int64 gcd(int64 a, int64 b){
    if(b==0ll){ return a; }
    return gcd(b, a%b);
}
int64 lcm(int64 a, int64 b){
    return a / gcd(a, b) * b;
}

int64 min(int64 lhs, int64 rhs){ return rhs<lhs ? rhs:lhs; }

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int N, X; cin >> N >> X;
    
    vector<int> vX(N);
    for(int i=0; i<N; ++i){ cin >> vX[i]; }
    
    if(N==1){ cout << abs(vX[0]-X) << endl; return 0; }

    vX.push_back(X);
    sort(vX.begin(), vX.end());
    
    int64 gcd_val=gcd(vX[1]-vX[0], vX[2]-vX[1]);
    for(int i=3; i<N; ++i){
        gcd_val = gcd(vX[i]-vX[i-1], gcd_val);
    }
    cout << gcd_val << endl;
    
    return 0;
}
