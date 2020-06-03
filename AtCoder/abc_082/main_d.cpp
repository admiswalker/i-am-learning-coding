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
    
    uint i=0;
    
    int cnt=0;
    bool isLR = true;
    vector<int> vLR, vTB;
    for(; i<s.size(); ++i){
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
    
    sort(vLR.begin(), vLR.end(), greater<int>());
    sort(vTB.begin(), vTB.end(), greater<int>());
    
    int sumLR=0, sumTB=0;
    for(uint i=0; i<vLR.size(); ++i){
        sumLR -= (sumLR>x ? 1:-1) * vLR[i];
    }
    for(uint i=0; i<vTB.size(); ++i){
        sumTB -= (sumTB>y ? 1:-1) * vTB[i];
    }
    
    cout << (sumLR==x && sumTB==y ? "Yes":"No") << endl;
    
    return 0;
}
