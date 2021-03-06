// 岩波講座 ソフトウェア科学 ３ アルゴリズムとデータ構造 石畑 清
// page.396 - 399 (C) ナップザック問題の分枝限定法による解法
// を参考に実装する．

#include <bits/stdc++.h>
using namespace std;

//---

template <typename T> inline void           sort     (      std::vector<T>& rhs   ){                            std::sort(rhs.begin(), rhs.end());             }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline std::vector<T> sorted   (const std::vector<T>& rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline void           sort_gr  (      std::vector<T>& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             } // Descending: 降順: 9, 8, 7, ...
template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>& rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...

/*
template<typename T>
int64_t sum(const vector<T>& vecRhs){
    int64_t sum=0ll;
    for(unsigned int i=0; i<vecRhs.size(); ++i){
        sum += (int64_t)vecRhs[i];
    }
    return sum;
}


template<typename T>
T max(const vector<T>& vecRhs){
    T lhs = vecRhs[0];
    for(unsigned int i=1; i<vecRhs.size(); ++i){
        if(lhs<=vecRhs[i]){ continue; }
        lhs = vecRhs[i];
    }
    return lhs;
}
//*/
//---

struct VW{
    VW(){}
    ~VW(){}
    int v;
    int w;
    bool operator<(const struct VW& rhs) const {
        return (double)(*this).v/(double)(*this).w < (double)rhs.v/(double)rhs.w;
    };
    bool operator>(const struct VW& rhs) const {
        return (double)(*this).v/(double)(*this).w > (double)rhs.v/(double)rhs.w;
    };
};

double estimate(const vector<struct VW>& vecVW, int64_t i, int N, int64_t w_minusW){
    double estV=0.0;
    int64_t w=0;
    /*
    for(; i<N && w<=w_minusW; ++i){
        estV += (double)vecVW[i].v;
        w    += vecVW[i].w;
    }
    estV += (w_minusW-w)*vecVW[vecVW.size()-1].v;
    //*/
    //*
    for(; i<N; ++i){
        if(w<=w_minusW){
            estV += (double)vecVW[i].v;
            w    += vecVW[i].w;
        }else{
            estV += (w_minusW-w)*vecVW[i].v;
            break;
        }
    }//*/
    /*
    for(; i<N; ++i){
        if(w+vecVW[i].w<=w_minusW){
            estV += (double)vecVW[i].v;
            w    += vecVW[i].w;
        }else{
            estV += (double)(w_minusW-w)*((double)vecVW[i].v/(double)vecVW[i].w);
            printf("%ld\n", w_minusW-w);
            break;
        }
    }//*/
    /*
    for(; i<N; ++i){
        if(w+vecVW[i].w <= w_minusW){
            estV += (double)vecVW[i].v;
            w    += vecVW[i].w;
        }else{
            estV += (double)(w_minusW-w)*(double)vecVW[i].v;
            break;
        }
    }//*/
    return estV;
}

// branchAndBound
int64_t bab(const vector<struct VW>& vecVW, unsigned int i, int64_t w){
    if(i==vecVW.size()){ return 0; }
    
    int64_t val=0;
    int64_t w_minusW = w - vecVW[i].w;
    if(w_minusW<0){
        val = bab(vecVW, i+1, w);
    }else{
        int64_t calc_i = bab(vecVW, i+1, w_minusW)+vecVW[i].v;
        int64_t pass_i = 0;
        
        double est = estimate(vecVW, i+1, vecVW.size(), w_minusW);
        if(est<(double)calc_i){
            pass_i = bab(vecVW, i+1, w);
        }
        val = max(calc_i, pass_i);
    }
    
    return val;
}

//---

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<struct VW> vecVW(N);
    for(unsigned int i=0; i<vecVW.size(); ++i){ cin >> vecVW[i].v >> vecVW[i].w; }
    
    sort_gr(vecVW);
    
    int64_t ans = bab(vecVW, 0, W);
    cout << ans << endl;
    
    return 0;
}
