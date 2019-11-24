#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int payment; cin >> payment;
    int change = 1000 - payment;
    
    vector<int> vecCoin = {500, 100, 50, 10, 5, 1};
    
    int ans=0;
    int sum=0;
    for(int i=0; i<vecCoin.size(); ++i){
//        ans += change/vecCoin[i];
//        change -= change%vecCoin[i];
        int div = change/vecCoin[i];
        int mod = change - vecCoin[i]*div;
        ans += div;
        change = mod;
    }
    
    cout << ans << endl;
    
    return 0;
}
