// ref: https://img.atcoder.jp/abc105/editorial.pdf
// ref: https://drken1215.hatenablog.com/entry/2018/08/13/123600

#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    
    int N; cin >> N;
    while(N!=0){
        int r = abs(N%2);
        N = (N-r)/(-2);
        s += (r==0 ? '0':'1');
    }
    
    reverse(s.begin(), s.end());
    if(s.size()==0){ s='0'; }
    cout << s << endl;
    
    return 0;
}
