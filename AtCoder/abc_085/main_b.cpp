#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> vecD(N); for(int i=0; i<vecD.size(); i++){ cin >> vecD[i]; }
    
    sort(vecD.begin(), vecD.end(), greater<int>());
    
    int num=1;
    for(int i=1; i<vecD.size(); i++){
        if(vecD[i-1]!=vecD[i]){
            num++;
        }
    }

    cout << num;
    
    return 0;
}
