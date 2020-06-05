#include <bits/stdc++.h>
using namespace std;

bool isEven(const int n){
    if(n%2==0){
        return true;
    }else{
        return false;
    }
}
int min(const vector<int>& vec){
    int min=vec[0];
    for(int i=1; i<vec.size(); i++){
        if(min>vec[i]){
            min=vec[i];
        }
    }
    return min;
}
int numOf2in(int x){
    int n=0;
    while(isEven(x)){
        x/=2;
        n++;
    }
    return n;
}
vector<int> numOf2in(const vector<int>& vec_in){
    vector<int> vec_out(vec_in.size());
    for(int i=0; i<vec_in.size(); i++){
        vec_out[i] = numOf2in(vec_in[i]);
    }
    return vec_out;
}

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<A.size(); i++){
        cin >> A[i];
    }
    
    A = numOf2in(A);
    int a = min(A);
    cout << a;
    
    return 0;
}
