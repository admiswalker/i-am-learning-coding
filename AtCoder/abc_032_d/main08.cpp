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
//    struct VW& operator=(const struct VW& rhs){
//        return *this;
//    }
    bool operator<(const struct VW& rhs) const {
        return (double)(*this).v/(double)(*this).w < (double)rhs.v/(double)rhs.w;
    };
    bool operator>(const struct VW& rhs) const {
        return (double)(*this).v/(double)(*this).w > (double)rhs.v/(double)rhs.w;
    };
};
/*
// branchAndBound
int64_t bab(const vector<int>& vecVW, unsigned int i, int64_t w){
    if(i==vecV.size()){ return 0; }
    
    int64_t val=0;
    int64_t w_minusW = w - vecW[i];
    if(w_minusW<0){ val =     bab(vecV, vecW, i+1, w);
    }     else    { val = max(bab(vecV, vecW, i+1, w_minusW)+vecV[i], bab(vecV, vecW, i+1, w)); }
    
    return val;
}
//*/
//---

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<struct VW> vecVW(N);
    for(unsigned int i=0; i<vecVW.size(); ++i){ cin >> vecVW[i].v >> vecVW[i].w; }
    
    sort_gr(vecVW);
    for(unsigned int i=0; i<vecVW.size(); ++i){
        printf("%d: %lf\n", i, (double)vecVW[i].v/(double)vecVW[i].w);
    }
    
//    int64_t ans = bab(vecV, vecW, 0, W);
//    cout << ans << endl;
    
    return 0;
}
