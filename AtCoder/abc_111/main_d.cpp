// ref: https://drken1215.hatenablog.com/entry/2018/09/30/002900

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

struct xy{
    int x;
    int y;
};

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<struct xy> vXY(N);
    for(uint i=0; i<N; ++i){ cin >> vXY[i].x >> vXY[i].y; }
    
    int mod2 = (abs(vXY[0].x) + abs(vXY[0].y)) % 2;
    for(uint i=1; i<N; ++i){
        int mod2_tmp = (abs(vXY[i].x) + abs(vXY[i].y)) % 2;
        if(mod2!=mod2_tmp){ cout << -1 << endl; return 0; }
    }
    
    vector<int> vD; for(int i=5; i>=0; --i){ vD.push_back( 1<<i ); }
    if(mod2==0){ vD.push_back(1); }
    cout << vD.size() << endl; for(uint i=0; i<vD.size(); ++i){ cout << vD[i] << ' '; } cout << endl;
    
    for(uint i=0; i<N; ++i){
        int xt = vXY[i].x; // t: target
        int yt = vXY[i].y;
        int xs=0, ys=0; // s: sum
        for(uint di=0; di<vD.size(); ++di){
            if(abs(xt-xs) > abs(yt-ys)){
                if(xt-xs>=0){ xs+=vD[di]; cout << 'R';
                }    else   { xs-=vD[di]; cout << 'L'; }
            }else{
                if(yt-ys>=0){ ys+=vD[di]; cout << 'U';
                }    else   { ys-=vD[di]; cout << 'D'; }
            }
        }
        cout << endl;
    }
    
    return 0;
}

