// ref: https://scrapbox.io/longshoujin/AtCoder_Begginer_Contest_ABC082_D_-_FT_Robot
// ref: https://atcoder.jp/contests/abc082/submissions/9934921

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    int x, y; cin >> x >> y;
    
    int cnt=0;
    bool isLR = true;
    vector<int> vLR, vTB;
    for(uint i=0; i<s.size(); ++i){
        if(s[i]=='F'){ ++cnt; continue; }
        if(s[i]=='T'){
            if( isLR && cnt!=0){ vLR.push_back(cnt); }
            if(!isLR && cnt!=0){ vTB.push_back(cnt); }
            isLR = !isLR;
            cnt = 0;
        }
    }
    if(s[s.size()-1]=='F'){
        if( isLR && cnt!=0){ vLR.push_back(cnt); }
        if(!isLR && cnt!=0){ vTB.push_back(cnt); }
    }
    if(s[0]!='T'){
        x -= vLR[0]; vLR.erase(vLR.begin());
    }
    
    // DP
    int base = 8000;
    vector<vector<bool>> vvDP_x(vLR.size()+1, vector<bool>(base*2+1, false)); vvDP_x[0][base] = true;
    vector<vector<bool>> vvDP_y(vTB.size()+1, vector<bool>(base*2+1, false)); vvDP_y[0][base] = true;
    for(uint vi=0; vi<vLR.size(); ++vi){
        for(int i=0; i<base*2; ++i){
            if(! vvDP_x[vi][i]){ continue; }
            
            if(i + vLR[vi] <= base*2){ vvDP_x[vi+1][i + vLR[vi]]=true; }
            if(i - vLR[vi] >= 0     ){ vvDP_x[vi+1][i - vLR[vi]]=true; }
        }
    }
    for(uint vi=0; vi<vTB.size(); ++vi){
        for(int i=0; i<base*2; ++i){
            if(! vvDP_y[vi][i]){ continue; }
            
            if(i + vTB[vi] <= base*2){ vvDP_y[vi+1][i + vTB[vi]]=true; }
            if(i - vTB[vi] >= 0     ){ vvDP_y[vi+1][i - vTB[vi]]=true; }
        }
    }
    
    cout << (vvDP_x[vLR.size()][base+x] && vvDP_y[vTB.size()][base+y] ? "Yes":"No") << endl;
    
    return 0;
}
