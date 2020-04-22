// ref: https://atcoder.jp/contests/abc119/tasks/abc119_a

#include <bits/stdc++.h>
typedef int64_t int64;
using namespace std;

int main(){
    
    int y, m, d; char c;
    cin >> y >> c >> m >> c >> d;
    int64 date_s  = y*10000 + m*100 + d;
    int64 date_th = 2019*10000 + 4*100 + 30;
    
    if(date_s <= date_th){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }
    
    return 0;
}
