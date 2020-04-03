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
    
    int n; cin >> n;
    int nd2 = n/2; // n div 2
    
    map<int,int> cnt_v;
    for(uint i=0; i<(uint)n; ++i){
        int v; cin >> v;
        auto itr = cnt_v.find( v );
        if(itr!=cnt_v.end()){ ++itr->second;
        }        else       { cnt_v.insert( make_pair(v, 1) ); }
    }
    
    vector<int> vNum;
    for(auto itr=cnt_v.begin(); itr!=cnt_v.end(); ++itr){
        vNum.push_back(itr->second);
    }
    
    // minus nd2
    for(uint i=0; i<vNum.size(); ++i){ vNum[i] = abs(vNum[i]-nd2); }
    sort(vNum.begin(), vNum.end());
    printn(vNum);
    
    int ans;
    if      ( vNum.size()==1 ){ ans = vNum[0];
    }           else          { ans = vNum[0]+vNum[1]; }
    cout << ans << endl;
    
    return 0;
}
