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

//     vH[i] = ch-abs(vX[i]-cx)-abs(vY[i]-cy)
// <=> vH[i] = ch-abs(vX[i]-cx)-abs(vY[i]-cy)
// <=> vH[i]     +abs(vX[i]-cx)+abs(vY[i]-cy) = ch
// <=> ch = vH[i]+abs(vX[i]-cx)+abs(vY[i]-cy)

tuple<bool,int> isSameH(int cx, int cy,
             const vector<int>& vX, const vector<int>& vY, const vector<int>& vH){
    int ch;
    for(uint i=0; i<vH.size(); ++i){
        if(vH[i]<=0){ continue; }
        ch = max(vH[i]+abs(vX[i]-cx)+abs(vY[i]-cy), 0);
        break;
    }
    
    for(uint i=0; i<vH.size(); ++i){
        int htmp = max(ch-abs(vX[i]-cx)-abs(vY[i]-cy), 0);
        if(vH[i]!=htmp){ return make_pair(false, ch); }
    }
    return make_pair(true, ch);
}
tuple<int, int, int> solver(const vector<int>& vX, const vector<int>& vY, const vector<int>& vH){
    for(int cx=0; cx<=100; ++cx){
        for(int cy=0; cy<=100; ++cy){
            bool TF; int ch;
            tie(TF, ch) = isSameH(cx, cy, vX, vY, vH);
            if( TF ){ return make_tuple(cx, cy, ch); }
        }
    }
    return make_tuple(-1, -1, -1);
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    uint N; cin >> N;
    vector<int> vX(N), vY(N), vH(N);
    for(uint i=0; i<N; ++i){ cin >> vX[i] >> vY[i] >> vH[i]; }
    
    int cx=0, cy=0, ch=0;
    tie(cx, cy, ch) = solver(vX, vY, vH);
    cout << cx << ' ' << cy << ' ' << ch << endl;
    
    return 0;
}
