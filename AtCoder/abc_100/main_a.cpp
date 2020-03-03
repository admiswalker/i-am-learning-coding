#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size=16;
    int A, B; cin >> A >> B;
    
    if(max(A, B)>(size/2)){ cout << ":(" << endl; return 0; }
    cout << "Yay!" << endl;
    
    return 0;
}
