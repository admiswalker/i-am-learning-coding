// ref: https://img.atcoder.jp/abc112/editorial.pdf

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

int height(int H, int x, int cx, int y, int cy){
//    return max(H-abs(x-cx)-abs(y-cy), 0);
    return H-abs(x-cx)-abs(y-cy);
}

bool isSameH(int cx, int cy, int ch,
             const vector<int>& vX, const vector<int>& vY, const vector<int>& vH){
    for(uint i=0; i<vH.size(); ++i){
        int htmp = height(0, vX[i], cx, vY[i], cy);
//        printn(vH[i]+htmp);
//        printn(cx);
//        printn(cy);
        if(htmp != vH[i]){ return false; }
//        int htmp =  height(ch, vX[i], cx, vY[i], cy);
//        if(htmp != vH[i]){ return false; }
    }
    return true;
}
void solver(int& cx, int& cy, int& ch, 
            const vector<int>& vX, const vector<int>& vY, const vector<int>& vH){
    for(; cx<=100; ++cx){
        for(; cy<=100; ++cy){
            printf("cx, cy = %d %d\n", cx, cy);
//            if( isSameH(cx, cy, ch, vX, vY, vH) ){ printf("break\n"); return; }
            
//            for(; ch<=100; ++ch){
//                if( isSameH(cx, cy, ch, vX, vY, vH) ){ printf("break\n"); return; }
//            }
        }
    }
    printf("imh\n");
    return;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vX(N), vY(N), vH(N);
    for(uint i=0; i<N; ++i){ cin >> vX[i] >> vY[i] >> vH[i]; }
    
    int cx=0, cy=0, ch=0; solver(cx, cy, ch, vX, vY, vH);
    cout << cx << ' ' << cy << ' ' << ch << endl;
    
    return 0;
}
