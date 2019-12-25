// ref: https://atcoder.jp/contests/maximum-cup-2018/submissions/4834449

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
    
    vector<vector<int>> D(2);
    for(unsigned int p=0; p<D.size(); ++p){
        D[p].resize(1000);
        
        D[p][0] = 1;
        for(unsigned int q=1; q<D[p].size(); ++q){ D[p][q] = 1e9; }
    }
    
    for(int i=1; i<M; ++i){
        if( !place2laps[i].size() ){ continue; }
        
        sort(place2laps[i]);
        
        vector<pair<int, int>> vecPL;
        int place = 0; // place
        int laps  = 0; // numOfLaps
        for(auto laps_cur: place2laps[i]){
            place += i;
            laps  += laps_cur;
            if(place >= M){ place-=M; ++laps; }
            
//            if(place == 0){ continue; }
            vecPL.push_back( make_pair(place, laps) );
        }
        
        vector<pair<int, int>> V3;
        for(int p=0; p<M; ++p){
            if( D[0][p] >= 5e8){ continue; }
            
            for(auto pl: vecPL){
                int place = pl.first;
                int laps  = pl.second;
                if(p + place >= M){ place-=M; ++laps; }
                
                D[1][p+place] = min(D[1][p+place], D[0][p+laps]);
            }
        }
        
        if(D[1][L] < X){
            printf("Yes\n");
            return 0;
        }
        memcpy(&D[0][0], &D[1][0], 4 * M);
    }
    printf("No\n");
    
    return 0;
}
