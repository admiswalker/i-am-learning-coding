// ref: https://img.atcoder.jp/abc099/editorial.pdf
// ref: http://xxxasdfghjk999.hatenablog.jp/entry/2018/07/27/220336

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
    
    int N, C; cin >> N >> C;
    vector<vector<int>> vvD(C, vector<int>(C));
    vector<vector<int>> vvT(3, vector<int>(C, 0));
    for(int r=0;r<C;++r){for(int c=0;c<C;++c){ cin>>vvD[r][c]; }}
    for(int r=0;r<N;++r){for(int c=0;c<N;++c){ int tmp; cin>>tmp; vvT[(r+c)%3][tmp-1]+=1; }}
    /*
     * vvT[0][ 0~ C-1 ]: mod==0 の要素について，0~ C-1 種類の色がそれぞれ幾つあるかを保持している．
     * vvT[1][ 0~ C-1 ]: mod==1 の要素について，0~ C-1 種類の色がそれぞれ幾つあるかを保持している．
     * vvT[2][ 0~ C-1 ]: mod==2 の要素について，0~ C-1 種類の色がそれぞれ幾つあるかを保持している．
     */
    
    int ret=INT_MAX;
    for(int p=0; p<C; ++p){
        for(int q=0; q<C; ++q){
            if(p==q){ continue; } // skip the same color
            for(int r=0; r<C; ++r){
                if(r==p || r==q){ continue; } // skip the same color
                
                // 自分自身への変換は，vvD 行列の対角成分が 0 のため，考慮しなくてよい．
                int tt=0;
                for(int i=0; i<C; ++i){ tt+=vvD[i][p]*vvT[0][i]; } // mod==0 の色を全て p に塗り替える場合の違和感の総和 // vvD[i][p]: wrongness of cnv-ing i2p, vvT[0][i]: num of color-[i] in mod [0].
                for(int i=0; i<C; ++i){ tt+=vvD[i][q]*vvT[1][i]; } // mod==1 の色を全て q に塗り替える場合の違和感の総和 // vvD[i][q]: wrongness of cnv-ing i2q, vvT[1][i]: num of color-[i] in mod [1].
                for(int i=0; i<C; ++i){ tt+=vvD[i][r]*vvT[2][i]; } // mod==2 の色を全て r に塗り替える場合の違和感の総和 // vvD[i][r]: wrongness of cnv-ing i2r, vvT[2][i]: num of color-[i] in mod [2].
                
                if(tt < ret){ ret=tt; }
            }
        }
    }
    cout << ret << endl;
    
    return 0;
}
