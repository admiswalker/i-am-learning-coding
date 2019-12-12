#include <bits/stdc++.h>
using namespace std;

//---

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

//---

int64_t dps_re(const vector<int>& vecV, const vector<int>& vecW, unsigned int i, int64_t w){
    if(i==vecV.size()){ return 0; }
    
    int64_t val=0;
    int64_t w_minusW = w - vecW[i];
    if(w_minusW<0){ val =     dps_re(vecV, vecW, i+1, w);
    }     else    { val = max(dps_re(vecV, vecW, i+1, w_minusW)+vecV[i], dps_re(vecV, vecW, i+1, w)); }
    
    return val;
}


#define dp_m(i, j)                              \
    dp[(W+1ull)*(i) + (j)]
int64_t dps_memoW(const vector<int>& vecV, const vector<int>& vecW, const int N, const int W){
    vector<int64_t> dp((2)*(W+1), 0);
    
    for(int i=0; i<N; ++i){
        for(int w=0; w<=W; ++w){
            int w_minusW = w - vecW[i];
            if(w_minusW<0){ dp_m((i+1)&1, w) =     dp_m(i&1, w);
            }    else     { dp_m((i+1)&1, w) = max(dp_m(i&1, w), dp_m(i&1ull, w_minusW)+vecV[i]);
            }
        }
    }
    
    return dp_m(N&1ull, W);
}
#undef dp_m


#define dp_m(i, j)                              \
    dp[(sumV+1)*(i) + (j)]
int64_t dps_memoV(const vector<int>& vecV, const vector<int>& vecW, const int N, const int W){
    int64_t sumV = sum(vecV);
    
    vector<int64_t> dp((N+1)*(sumV+1), 0);
    dp_m(0, 0) = 0ll;
    for(int i=1; i<=sumV; ++i){ dp_m(0, i)=LLONG_MAX/2; }
    
    for(int i=0; i<N; ++i){
        for(int64_t v=0; v<=sumV; ++v){
            int64_t cal = v - vecV[i];
            if(cal<0){ dp_m(i+1, v) = dp_m(i, v);
            }  else  { dp_m(i+1, v) = min(dp_m(i, v), dp_m(i, cal)+vecW[i]);
            }
        }
    }
    
    int64_t ans=0ll;
    for(int64_t v=0; v<=sumV; ++v){
        if(dp_m(N, v)<=W){ ans = v; }
    }
    return ans;
}
#undef dp_m

//---

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, W; cin >> N >> W;
    vector<int> vecV(N), vecW(N);
    for(int i=0; i<N; ++i){ cin >> vecV[i] >> vecW[i]; }
    int maxW = max(vecW);
    
    int64_t ans=0;
    if      (   N<=30  ){ ans = dps_re   (vecV, vecW, 0, W);
    }else if(maxW<=1000){ ans = dps_memoW(vecV, vecW, N, W);
    }else               { ans = dps_memoV(vecV, vecW, N, W);
    }
    cout << ans << endl;
    
    return 0;
}
