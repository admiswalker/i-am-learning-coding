// メモ：
// なぜか AC されてしまうものの，たぶん必要な探査範囲を抜かしている箇所があると思うので，
// 普通に main02.cpp あたりの回答が無難．

// ref:
// [1] 蝶本 第 2 版 page. 62 個数制限付き部分和問題
// [2] https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

#include <bits/stdc++.h>
using namespace std;

template <typename T> inline void           sort     (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end());             }
template <typename T> inline std::vector<T> sorted   (const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }
template <typename T> inline std::vector<T> sorted   (      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end()); return rhs; }
template <typename T> inline void           sort_gr  (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             }
template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; }
template <typename T> inline std::vector<T> sorted_gr(      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; }

struct divMod{
private:
public:
    int div;
    int mod;
    divMod(){}
    ~divMod(){}
    
    bool operator<(const struct divMod& rhs){
        if      ( (*this).mod <  rhs.mod ){ return true;
        }else if( (*this).mod == rhs.mod ){ return (*this).div < rhs.div;
        }else                             { return false;
        }
    }
};

bool dps(vector<struct divMod>& vecPL, int N, int M, int L, int X){
    sort( vecPL );
    
    vector<int> dp_min (M, INT_MAX); dp_min [0] = 0;
    vector<int> dp_prev(M, INT_MAX); dp_prev[0] = 0;
    
    for(unsigned int i=0; i<vecPL.size(); ++i){
        int place=0, laps=0;
        for(int p=0; p<M; ++p){
            if(dp_prev[p] == INT_MAX){ continue; }
            
            place += p + vecPL[i].mod;
            laps  +=     vecPL[i].div;
            if(place >= M){ place-=M; ++laps; }
            
            dp_min[place] = min(dp_min[place], dp_prev[p]+laps);
            
            if(i<vecPL.size()-1 && vecPL[i].mod==vecPL[i+1].mod){ i++; p--; continue; } // There is no difference in vecPL[i] and vecPL[i+1] with the same mod value is number of laps, 
            place=0; laps=0;                                                            // when beginnging from same p. Because both of it will move on same distance of mod.
            // なぜか AC されてしまうものの，ここの p 起点以外の箇所では，i++ で飛ばしてしまっているので，
            // p が異なる度に，i-- をどこかでして，すべて探査する必要がある・・・はず．
        }
        if(dp_min[L] < X){ return true; }
        dp_prev = dp_min;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    vector<struct divMod> vecPL(N);
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int div = a / M;
        int mod = a - M*div; // same as a "a % M"
        vecPL[i].div = div;
        vecPL[i].mod = mod;
    }
    
    bool TF = dps(vecPL, N, M, L, X);
    cout << (TF ? "Yes":"No") << endl;
    
    return 0;
}
