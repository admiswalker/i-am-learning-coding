// ref: https://img.atcoder.jp/arc089/editorial.pdf

#define _GLIBCXX_DEBUG
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

int64 slove(const vector<vector<int64>>& vvXY_cSum, const int K, const int x, const int y){
    int xB = max(x, 0);
    int yB = max(y, 0);
    
    int xE = x+K;
    int yE = y+K;
    xE = max(xE, 0); xE = min(xE, 2*K);
    yE = max(yE, 0); yE = min(yE, 2*K);
    
    return vvXY_cSum[xE][yE] - vvXY_cSum[xE][yB] - vvXY_cSum[xB][yE] + vvXY_cSum[xB][yB];
}

int64 max(const int64& lhs, const int64& rhs){ return (lhs > rhs ? lhs : rhs); }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    int64 K2=K*2;
    vector<vector<int64>> vvXY(K2, vector<int64>(K2, 0ll));
    for(int i=0; i<N; ++i){
        int x, y; char c; cin >> x >> y >> c;
        if(c == 'W'){ y += K; }
        x %= K2;
        y %= K2;
        ++vvXY[x][y];
    }
    
    vector<vector<int64>> vvXY_cSum(K2+1, vector<int64>(K2+1, 0ll));
    for(int xk=0; xk<K2; ++xk){
        for(int yk=0; yk<K2; ++yk){
            vvXY_cSum[xk+1][yk+1] = vvXY[xk][yk] + vvXY_cSum[xk+1][yk] + vvXY_cSum[xk][yk+1] - vvXY_cSum[xk][yk];
        }
    }
    
    int64 sum_max=0ll;
    for(int x=0; x<K; ++x){
        for(int y=0; y<K; ++y){
            int64 tmp = 0ll;
            tmp += slove(vvXY_cSum, K, x-K, y-K);
            tmp += slove(vvXY_cSum, K, x+K, y-K);
            tmp += slove(vvXY_cSum, K, x-K, y+K);
            tmp += slove(vvXY_cSum, K, x  , y  );
            tmp += slove(vvXY_cSum, K, x+K, y+K);
            sum_max = max(sum_max, tmp);
        }
    }
    
    cout << sum_max << endl;
    
    return 0;
}
