#include <bits/stdc++.h>
using namespace std;

int vec_sum(const vector<int>& vec){
    int sum=0;
    for(int i=0; i<vec.size(); ++i){
        sum += vec[i];
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int payment; cin >> payment;
    int change = 1000 - payment;
    
    vector<int> vecCoin = {500, 100, 50, 10, 5, 1};
    vector<int> vecNum(vecCoin.size(), 0);
    
    int sum=0;
    for(int i=0; i<vecCoin.size(); ++i){
        while(sum<change){
            sum += vecCoin[i]; ++vecNum[i];
        }
        if(sum==change){ break; }
        sum -= vecCoin[i]; --vecNum[i];
    }
    
    int count = vec_sum(vecNum);
    cout << count << endl;
    
    return 0;
}
