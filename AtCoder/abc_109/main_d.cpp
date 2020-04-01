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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    
    int H, W; cin >> H >> W;
    vector<int> vA(H*W);
    vector<int> vH_idx(H*W);
    vector<int> vW_idx(H*W);
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            int a; cin >> a;
            vA    [W*h + w] = a;
            vH_idx[W*h + w] = h;
            vW_idx[W*h + w] = w;
        }
        reverse(&    vA[W*h + 0], &    vA[W*h + W]);
        reverse(&vH_idx[W*h + 0], &vH_idx[W*h + W]);
        reverse(&vW_idx[W*h + 0], &vW_idx[W*h + W]);
    }
    
    for(int i=0; i<H*W-1; ++i){
        if(vA[i]%2==0){ continue; }
        int hIdx = vH_idx[i];
        int wIdx = vW_idx[i];
        int hIdx_next = vH_idx[i+1];
        int wIdx_next = vW_idx[i+1];
        cout << h << ' ' << w << ' ' << h++ << ' ' << w++ << endl;
    }
    
    int ans=0;
    
    cout << ans << endl;
    
    /*
    int H, W; cin >> H >> W;
    vector<int> vA(H*W);
    for(int h=0; h<H; ++h){
        vector<int> vW(W);
        for(int w=0; w<W; ++w){ cin>>vW[w]; }
//        if(h%2==0){ reverse(vW.beign(), vW.end()); }
        
        if(h%2!=0){
            for(int w=0; w<W; ++w){
                if(vW[w]%2==0){ continue; }
                cout << h << ' ' << w << ' ' << h << ' ' << w << endl;
            }
        }else{
            for(int w=W-1; w>=0; w){
                if(vW[w]%2==0){ continue; }
                cout << h << endl;
            }
        }
    }
    //*/
    /*
    int H, W; cin >> H >> W;
    vector<int> vA(H*W);
    for(int h=0; h<H; ++h){
        for(int w=0; w<W; ++w){
            int a; cin >> a;
            vA[W*h + w] = a;
        }
        reverse(&vA[W*h + 0], &vA[W*h + W]);
    }
    
    for(int i=0; i<H*W; ++i){
        if(vA[i]%2==0){
        }
    }
    
    int ans=0;
    
    cout << ans << endl;
    //*/
    return 0;
}
