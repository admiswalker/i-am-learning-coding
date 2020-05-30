#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Y; cin >> N >> Y;

    for(int a=0; a<=N; ++a){
        for(int b=0; b<=(N-a); ++b){
            int c=(N-a-b);
            int sum = 10000*a + 5000*b + 1000*c;
            if(sum==Y){
                cout << a << ' ' << b << ' ' << c;
                return 0;
            }
        }
    }
    
    cout << -1 << ' ' << -1  << ' ' << -1;
    
    return 0;
}
