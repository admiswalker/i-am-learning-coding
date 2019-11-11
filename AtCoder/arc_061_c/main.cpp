// メモ：まずは，上を写経してから考えるように．

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    long int ans=0;
    
    int numEq = 1 << (str.size()-1); // num of equation
    
    for(int n=0; n<numEq; ++n){ // ビットフラグで全通りを表現できる
        string tmp;
        tmp += str[0];
        
        for(int i=0; i<str.size()-1; ++i){
            if(n & (1<<i)){
                ans += stol(tmp); // str to longInt
                tmp = str[i+1];
            }else{
                tmp += str[i+1];
            }
        }
        ans += stol(tmp);
    }
    
    cout << ans << endl;
    
    return 0;
}

/*
// Ref: https://atcoder.jp/contests/arc061/submissions/8289928

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    long ans = 0;
    for (int i = 0; i < (1 << (str.size() - 1)); i++) {
        string tmp;
        tmp += str[0];
        for (int j = 0; j < str.size() - 1; j++) {
            if (i & (1 << j)) {
                ans += stol(tmp);
                tmp = str[j + 1];
            }
            else {
                tmp += str[j + 1];
            }
        }
        ans += stol(tmp);
    }
    cout << ans << endl;			
}
//*/
