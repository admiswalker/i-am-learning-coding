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
//        if      ( (*this).div <  rhs.div ){ return true;
//        }else if( (*this).div == rhs.div ){ return (*this).mod < rhs.mod;
//        }else                             { return false;
//        }
        if      ( (*this).mod <  rhs.mod ){ return true;
        }else if( (*this).mod == rhs.mod ){ return (*this).div < rhs.div;
        }else                             { return false;
        }
    }
};

bool dps(const vector<int>& vecA, int N, int M, int L, int X){
    
    vector<struct divMod> vecPL(N);
    for(int i=0; i<N; ++i){
        int div = vecA[i] / M;
        int mod = vecA[i] - M*div; // same as a "a % M"
        vecPL[i].div = div;
        vecPL[i].mod = mod;
    }
    sort( vecPL );
//    for(unsigned int i=0; i<vecPL.size(); ++i){
//        printf("%d: ", vecPL[i].div);
//        printf("%d", vecPL[i].mod);
//        printf("\n");
//    }
    
    vector<int> dp_min (M, INT_MAX); dp_min [0] = 0;
    vector<int> dp_prev(M, INT_MAX); dp_prev[0] = 0;
    
//    vector<int> vecNum(N); for(int i=0; i<vecNum.size(); ++i){ vecNum[i]=i; }
    for(unsigned int i=0; i<vecPL.size(); ++i){
        for(int p=0; p<M; ++p){
            if(dp_prev[p] == INT_MAX){ continue; }
            
            int place = p + vecPL[i].mod;
            int laps  =     vecPL[i].div;
            if(place >= M){ place-=M; ++laps; }
            
            dp_min[place] = min(dp_min[place], dp_prev[p]+laps);
            if(i<vecPL.size()-1 && vecPL[i].mod==vecPL[i+1].mod){ i++; p--; continue; } // same mod has no meaning in its order. so we can process it in same time.
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
    vector<int> vecA(N);
    for(int i=0; i<N; ++i){ cin >> vecA[i]; }
    
    bool TF = dps(vecA, N, M, L, X);
    cout << (TF ? "Yes":"No") << endl;
    
    return 0;
}
