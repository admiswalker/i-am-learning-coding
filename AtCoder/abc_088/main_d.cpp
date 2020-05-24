// ref: antsbook page. 37~ 39
// ref: https://atcoder.jp/contests/abc007/submissions/8568869

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

int search(const vector<string>& vStr, int r_begin, int c_begin, int r_end, int c_end){
    int Rows = vStr.size();
    int Cols = vStr[0].size();
    vector<vector<int>> vvS(Rows, vector<int>(Cols, INT_MAX)); // steps
    
    queue<tuple<int,int,int>> queRCS; queRCS.push(make_tuple(r_begin, c_begin, 0)); // row, col, steps
    while(queRCS.size()!=0){
        int r, c, steps;
        tie(r, c, steps) = queRCS.front(); queRCS.pop();
        if(!( 0<=r&&r<Rows && 0<=c&&c<Cols) ){ continue; }
        
        if(vStr[r][c]=='#'){ continue; }
        if(vvS[r][c]!=INT_MAX){ continue; }
        vvS[r][c] = steps;
        if(r==r_end && c==c_end){ break; }
        
        ++steps;
        queRCS.push(make_tuple(r-1, c  , steps));
        queRCS.push(make_tuple(r  , c-1, steps));
        queRCS.push(make_tuple(r+1, c  , steps));
        queRCS.push(make_tuple(r  , c+1, steps));
    }
    return vvS[r_end][c_end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int H, W; cin >> H >> W;
    vector<string> vS(H);
    for(int r; r<H; ++r){
        cin >> vS[r];
    }
    
    int cnt_B=0; // black
    for(int r=0; r<H; ++r){
        for(int c=0; c<W; ++c){
            if(vS[r][c]=='#'){ ++cnt_B; }
        }
    }
    
    int steps = search(vS, 0, 0, H-1, W-1);
    if(steps==INT_MAX){ cout << -1 << endl; return 0; }
    
    cout << H*W - cnt_B - steps - 1 << endl;
    
    return 0;
}
