// 岩波講座 ソフトウェア科学 ３ アルゴリズムとデータ構造 石畑 清
// page.396 - 399 (C) ナップザック問題の分枝限定法による解法
// 
// を参考に実装する．

#include <bits/stdc++.h>
using namespace std;

//---

template <typename T> inline void           sort     (      std::vector<T>& rhs   ){                            std::sort(rhs.begin(), rhs.end());             }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline std::vector<T> sorted   (const std::vector<T>& rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline void           sort_gr  (      std::vector<T>& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             } // Descending: 降順: 9, 8, 7, ...
template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>& rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...

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

double estimate(const vector<struct VW>& vecVW, int64_t i, int64_t v_cur, int64_t w_cur){
    int N = vecVW.size();
    double estV=(double)v_cur;
    
    for(; i<N && vecVW[i].w<=w_cur; ++i){
        estV  += (double)vecVW[i].v;
        w_cur -= vecVW[i].w;
    }
    if(i!=N){
        estV += (double)w_cur * ((double)vecVW[i].v/(double)vecVW[i].w);
    }
    
    return estV;
}

// branchAndBound
void bab(const vector<struct VW>& vecVW, int64_t& v_max, unsigned int i, int64_t v_cur, int64_t w_cur){
    if(i==vecVW.size()){
        if(v_cur > v_max){ v_max = v_cur; }
        return;
    }
    
    if(w_cur >= vecVW[i].w){
        bab(vecVW, v_max, i+1, v_cur + vecVW[i].v, w_cur - vecVW[i].w);
    }
    
    double est = estimate(vecVW, i+1, v_cur, w_cur);
    if(est > v_max){
        bab(vecVW, v_max, i+1, v_cur, w_cur);
    }
    
    return;
}

//---

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<struct VW> vecVW(N);
    for(unsigned int i=0; i<vecVW.size(); ++i){ cin >> vecVW[i].v >> vecVW[i].w; }
    
    sort_gr(vecVW);
    
    int64_t v_max = 0;
    bab(vecVW, v_max, 0, 0, W);
    cout << v_max << endl;
    
    return 0;
}
