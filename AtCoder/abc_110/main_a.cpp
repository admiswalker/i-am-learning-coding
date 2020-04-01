#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> vX(3);
    cin >> vX[0] >> vX[1] >> vX[2];
    sort(vX.begin(), vX.end());
    
    cout << vX[2]*10+vX[1]+vX[0] << endl;
    
    return 0;
}
