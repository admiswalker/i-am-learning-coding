#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(const int N){
    int sum=0;
    string Ns = to_string(N);
    for(int i=0; i<Ns.size(); i++){
        sum += (int)Ns[i] - (int)'0';
    }
    return sum;
}

int main(){
    int N; cin >> N;
    int A, B; cin >> A >> B;
    
    int sum=0;
    for(int i=1; i<=N; i++){
        int sumD = sumOfDigits(i);
        if( A<=sumD && sumD<=B ){ sum += i; }
    }
    
    cout << sum;
    
    return 0;
}
