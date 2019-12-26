// ref:
// [1] 蝶本 第 2 版 page. 62 個数制限付き部分和問題
// [2] https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

#include <bits/stdc++.h>
using namespace std;

//---

template <typename T> inline void           sort     (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end());             }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline std::vector<T> sorted   (const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline std::vector<T> sorted   (      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline void           sort_gr  (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             } // Descending: 降順: 9, 8, 7, ...
template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...
template <typename T> inline std::vector<T> sorted_gr(      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...

//---
/*
bool dps(const vector<int>& vecA, int M, int L, int X){
    const int& N = vecA.size();
    int len = L + M*(X-1);
    
    vector<int> dp(len+1, -1);
    dp[0] = 0;
    
    for(int i=0; i<N; ++i){
        for(int l=0; l<=len; ++l){
            if      (dp[l]>=0                     ){ dp[l] = 1;
            }else if(l<vecA[i] || dp[l-vecA[i]]<=0){ dp[l] = -1;
            }else                                  { dp[l] = dp[l-vecA[i]] - 1; }
        }
    }
    
    for(int i=L; i<len; i+=M){
        if(dp[i]>=0){ return true; }
    }
    return false;
}
//*/
/*
bool dps_internal(const vector<int>& place2laps, int N, int M, int L, int X){
    vector<int> dp_min(M, -1); dp[0] = 0;
    vector<int> dp_tmp(M, -1); dp[0] = 0;
    
    for(int p=0; p<M; ++p){
        for(int i=0; i<place2laps[i].size(); ++i){
            int place = p + place2laps[i];
            int laps  = ;
            
            for(int l=0; l<=len; ++l){
                if      (dp[l]>=0                     ){ dp[l] = 1;
                }else if(l<vecA[i] || dp[l-vecA[i]]<=0){ dp[l] = -1;
                }else                                  { dp[l] = dp[l-vecA[i]] - 1; }
            }
        }
    }
    
    return (dp[L] >= 0);
}//*/
//---

int standardization(int& place, int M){
    if(place < M){ return 0; }
    
    int div = place / M;
    int mod = place - M*div;
    place = mod;
    
    return div;
}
bool dps(const vector<int>& vecA, int N, int M, int L, int X){
    
    vector<int> dp_min(M, INT_MAX); dp_min[0] = 0;
    vector<int> dp_tmp(M, INT_MAX); dp_tmp[0] = 0;
    
    for(int p=0; p<M; ++p){
        if(dp_tmp[p] == INT_MAX){ continue; }
        
        int place=0;
        int laps =0;
        for(unsigned int i=0; i<vecA.size(); ++i){
//            place += p + vecA[i];
//            laps  += standardization(place, M);
            place += p + vecA[i];
            laps  += place / M;
            place  = place % M;
            
            dp_min[place] = min(dp_min[place], dp_tmp[p]+laps);
        }
        
        if(dp_min[L] < X){ return true; }
//        swap(dp_min, dp_tmp);
        dp_tmp = dp_min;
    }
    
    return false;
}

/*
bool dps_internal(vector<int>& place2laps, int N, int M, int L, int X){
    
    vector<int> dp_min(M, INT_MAX); dp_min[0]=0;
    vector<int> dp_tmp(M, INT_MAX); dp_tmp[0]=0;
    
    for(int i=1; i<M; ++i){
        sort( place2laps[i] );
        
        vector<tuple<int,int>> vecPL(N);
        for(int i=0; i<vecPL.size(); ++i){
            int place = i;
            int laps  = place2laps[i];
            vecPL[i] = make_tuple(place, laps);
        }
        
        swap(dp_min, dp_tmp);
    }
    
    for(int i=0; i<place2laps.size(); ++i){
        sort( place2laps[i] );
    }
    
    for(int p=0; p<M; ++p){
        dp_min[p];
    }
    return ;
}
bool dps(const vector<int>& vecA, int N, int M, int L, int X){
    
    vector<vector<int>> place2laps(M);
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int div = a / M;
        int mod = a - M*div; // same as a "a % M"
        place2laps[mod].push_back( div );
    }
    
    return dps_internal(place2laps, N, M, L, X);
}
//*/
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
