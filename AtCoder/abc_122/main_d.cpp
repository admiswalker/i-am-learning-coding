// ref: https://competitive-kivantium.hateblo.jp/entry/2019/04/27/001317
// ref: https://img.atcoder.jp/abc122/editorial.pdf

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

bool ok(const string& s){
    if(             s[1]=='A' && s[2]=='G' && s[3]=='C'){ return false; } // ?AGC
    if(s[0]=='A' &&              s[2]=='G' && s[3]=='C'){ return false; } // A?GC
    if(s[0]=='A' && s[1]=='G' &&              s[3]=='C'){ return false; } // AG?C
    if(s[0]=='A' && s[1]=='G' && s[2]=='C'             ){ return false; } // AGC?
    
    if(             s[1]=='G' && s[2]=='A' && s[3]=='C'){ return false; } // ?GAC
    if(s[0]=='G' && s[1]=='A' && s[2]=='C'             ){ return false; } // GAC?
    
    if(             s[1]=='A' && s[2]=='C' && s[3]=='G'){ return false; } // ?ACG
    if(s[0]=='A' && s[1]=='C' && s[2]=='G'             ){ return false; } // ACG?
    return true;
}

int64 dfs(const int N, vector<unordered_map<string,int>>& memo, const int cur, const string last3){ // depth-first search
    if(memo[cur][last3]!=0){ return memo[cur][last3]; }
    if(cur==N){ return 1; }
    
    int ret=0;
    const int MOD = 1e9+7;
    const char base[] = {'A', 'C', 'G', 'T'};
    for(uint i=0; i<4; ++i){
        if(!ok(last3+base[i])){ continue; }
        string s = last3.substr(1) + base[i];
        ret += dfs(N, memo, cur+1, s);
        ret %= MOD;
    }
    memo[cur][last3] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<unordered_map<string,int>> memo(N+1);
    
    cout << dfs(N, memo, 0, "TTT") << endl;
    
    return 0;
}
