#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t min, max;
    cin >> min >> max;
    
    int i=0;
    for(int64_t buf=min; buf<=max; ++i){
        buf *= 2;
    }
    
    cout << i << endl;
    
    return 0;
}
