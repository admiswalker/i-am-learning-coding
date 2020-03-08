#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint N; cin >> N;
    if(N%2==0){
        cout << N << endl;
    }else{
        cout << N*2 << endl;
    }
    
    return 0;
}
