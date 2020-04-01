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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W; cin >> H >> W;
    vector<int> vA(H*W);
    vector<int> vH_idx(H*W);
    vector<int> vW_idx(H*W);
    for(int h=0; h<H; ++h){
        int a;
        for(int w=0; w<W; ++w){
            cin >> a;
            vA    [W*h + w] = a;
            vH_idx[W*h + w] = h+1;
            vW_idx[W*h + w] = w+1;
        }
        
        if(h%2==0){ continue; }
        reverse(&    vA[W*h + 0], &    vA[W*h + W]);
        reverse(&vH_idx[W*h + 0], &vH_idx[W*h + W]);
        reverse(&vW_idx[W*h + 0], &vW_idx[W*h + W]);
    }
    
    vector<string> vS;
    for(int i=0; i<H*W-1; ++i){
        if(vA[i]%2==0){ continue; }
        ++vA[i+1];
        int h = vH_idx[i];
        int w = vW_idx[i];
        int h_next = vH_idx[i+1];
        int w_next = vW_idx[i+1];
//        cout << h << ' ' << w << ' ' << h_next << ' ' << w_next << endl;
        string buf = to_string(h) + ' ' + to_string(w) + ' ' + to_string(h_next) + ' ' + to_string(w_next);
        vS.push_back( buf );
    }
    
    cout << vS.size() << endl;
    for(uint i=0; i<vS.size(); ++i){
        cout << vS[i] << endl;
    }
    return 0;
}
