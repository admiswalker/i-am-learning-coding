#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    uint R; cin >> R;
    if      (R<1200){ cout << "ABC" << endl;
    }else if(R<2800){ cout << "ARC" << endl;
    }else           { cout << "AGC" << endl; }
    
    return 0;
}
