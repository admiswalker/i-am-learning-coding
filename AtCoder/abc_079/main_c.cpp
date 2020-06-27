#include <bits/stdc++.h>
using namespace std;

int ctoi(const char c){
    switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default : return -1;
    }
}

int main(){
    string str;
    cin >> str;
    
    int numEq = 1 << (str.size()-1); // num of equation
    
    int ans=0;
    for(int i=0; i<numEq; ++i){
        string tmp;
        tmp += str[0];
        
        int i_buf = i;
        int sum = ctoi(str[0]);
        for(int n=1; n<str.size(); ++n){
            if(i_buf&1){ sum += ctoi(str[n]);
            }else      { sum -= ctoi(str[n]);
            }
            i_buf = i_buf >> 1;
        }
        
        if(sum==7){
            ans = i;
            break;
        }
    }
    
    for(int i=0; i<str.size()-1; ++i){
        printf("%c", str[i]);
        if(ans&1){ printf("+");
        }else    { printf("-");
        }
        ans = ans >> 1;
    }
    printf("%c=7\n", str[str.size()-1]);
    
    return 0;
}
