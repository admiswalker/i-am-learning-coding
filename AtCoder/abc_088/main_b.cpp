#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> vecA(N); for(int i=0; i<N; i++){ cin >> vecA[i]; }
    
    std::sort(vecA.begin(), vecA.end(), std::greater<int>());
    
    int Alice=0;
    int Bob  =0;
    for(int i=0; i<vecA.size(); i++){
        Alice += vecA[i++];
        Bob   += vecA[i  ];
    }
    
    cout << (Alice-Bob);
    
    return 0;
}
