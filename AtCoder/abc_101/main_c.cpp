#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N, K; cin >> N >> K;
    
    uint idx;
    for(uint i=1; i<=N; ++i){
        uint num; cin >> num;
        if(num==1){ idx=i; }
    }
    
    double n_before = ceil((double)(idx-1)/(double)(K-1));
    int len_filled = n_before * (K-1) + 1;
    int len_left = N - len_filled;
    
    double n_after  = ceil((double)(len_left)/(double)(K-1));
    
    cout << (int)(n_before+n_after) << endl;
    
    return 0;
}
/*
case: 4
3 3
2 1 3
>> ans == 1
*/
/*
case: 5
7 3
2 1 3 4 5 6 7
>> ans == 3
*/
/*
case: 6
8 7
2 3 4 5 6 7 8 1
>> ans == 2
*/
