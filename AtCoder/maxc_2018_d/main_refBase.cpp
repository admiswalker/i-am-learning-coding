// ref of base: https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

#include<bits/stdc++.h>
using namespace std;

//---

template <typename T> inline void           sort     (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end());             }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline std::vector<T> sorted   (const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline std::vector<T> sorted   (      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
template <typename T> inline void           sort_gr  (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             } // Descending: 降順: 9, 8, 7, ...
template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...
template <typename T> inline std::vector<T> sorted_gr(      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...

//---

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M, L, X;
    cin >> N >> M >> L >> X;
    
    vector<vector<int>> place2laps(M);
    for(int i=0; i<N; ++i){
        int a; cin >> a;
        int div = a / M;
        int mod = a - M*div; // same as a "a % M"
        place2laps[mod].push_back( div );
    }
    
    vector<int> dp_min(M);
    vector<int> dp_tmp(M);
    dp_min[0]=0; for(unsigned int i=1; i<dp_min.size(); ++i){ dp_min[i]=INT_MAX; }
    dp_tmp[0]=0; for(unsigned int i=1; i<dp_tmp.size(); ++i){ dp_tmp[i]=INT_MAX; }
    
    for(int i=1; i<M; ++i){
        if( !place2laps[i].size() ){ continue; }
        
        sort(place2laps[i]);
        
        vector<pair<int, int>> vecPL;
        int place=0, laps=0;
        for(auto laps_cur: place2laps[i]){
            place += i;
            laps  += laps_cur;
            if(place >= M){ place-=M; ++laps; }
            
            vecPL.push_back( make_pair(place, laps) );
        }
        
        for(int p=0; p<M; ++p){
            if( dp_tmp[p] == INT_MAX){ continue; }
            
            for(auto pl: vecPL){
                int place, laps;
                tie(place, laps) = pl;
                if(p+place >= M){ place-=M; ++laps; }
                
                dp_min[p+place] = min(dp_min[p+place], dp_tmp[p]+laps);
            }
        }
        
        if(dp_min[L] < X){
            printf("Yes\n");
            return 0;
        }
        swap(dp_min, dp_tmp);
    }
    printf("No\n");
    
    return 0;
}
