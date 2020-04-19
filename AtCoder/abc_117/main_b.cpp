#include <bits/stdc++.h>
using namespace std;

int main(){
    
    uint N; cin >> N;
    vector<int> vL(N); for(uint i=0; i<N; ++i){ cin>>vL[i]; }
    sort(vL.begin(), vL.end());
    int sum = std::accumulate(vL.begin(), vL.end()-1, 0); // 0 is a initial value
    
    cout << (sum>vL[vL.size()-1] ? "Yes":"No") << endl;
    
    return 0;
}
