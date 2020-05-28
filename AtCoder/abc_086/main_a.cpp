#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    
    int product = a*b; // product
    if(product%2==0){
        printf("Even");
    }else{
        printf("Odd");
    }
    
    return 0;
}
