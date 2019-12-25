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
        place2laps[mod].push_back(div);
    }
    
    int D[2][1000];
    for(int i=0; i<2000; ++i){ *(D[0] + i) = 1e9; }
    D[0][0] = 1;
    D[1][0] = 1;
    for(int i=1; i<M; ++i){
        if( !place2laps[i].size() ){ continue; }
        
        sort(place2laps[i]);
        
        vector<pair<int, int>> V2;
        int place = 0; // place
        int laps  = 0; // numOfLaps
        for(unsigned int j=0; j<place2laps[i].size(); ++j){
            place += i;
            laps  += place2laps[i][j];
            if(place >= M){ place -= M; laps++; }
            
//            if(place == 0){ continue; }
            V2.push_back( make_pair(place, laps) );
        }
        vector<pair<int, int>> V3;
        for(int j=0; j<M; ++j){
            if(*(D[0] + j) < 5e8){
                for(auto p : V2){
                    int b = p.first;
                    int c = p.second;
                    if(j + b >= M){
                        b -= M;
                        c++;
                    }
                    *(D[1] + j + b) = min(*(D[1] + j + b), *(D[0] + j) + c);
                }
            }
        }
        if(*(D[1] + L) < X){
            printf("Yes\n");
            return 0;
        }
        memcpy(D[0], D[1], 4 * M);
    }
    printf("No\n");
    
    return 0;
}
