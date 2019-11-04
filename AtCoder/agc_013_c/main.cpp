#include <bits/stdc++.h>
using namespace std;

struct XW{
    XW(){ X=0; W=0; }
    ~XW(){}
    char X;
    char W;
};

void invW(struct XW& rhs){
    if      (rhs.W==1){ rhs.W=2;
    }else if(rhs.W==2){ rhs.W=1;
    }else             { printf("ERROR in invW\n"); }
}
void check_direction(vector<struct XW>& vecXW){
    if(vecXW[0].X==1 && vecXW[vecXW.size()-1].X==1){
        invW(vecXW[0]             );
        invW(vecXW[vecXW.size()-1]);
    }
    
    for(int i=1; i<vecXW.size(); ++i){
        if(vecXW[i-1].X==1 && vecXW[i].X==1){
            invW(vecXW[i-1]);
            invW(vecXW[i]  );
//            i+=2;
//            i+=3;
        }
    }
}

void forword(vector<struct XW>& vecXW_ret, vector<struct XW>& vecXW, int i){
    if(i==vecXW.size()-1){ vecXW_ret[0]  =vecXW[i];
    }         else       { vecXW_ret[i+1]=vecXW[i]; }
}
void back(vector<struct XW>& vecXW_ret, vector<struct XW>& vecXW, int i){
    if(i==0){ vecXW_ret[vecXW_ret.size()-1]=vecXW[i];
    }  else { vecXW_ret[i-1]               =vecXW[i]; }
}
vector<struct XW> advance(vector<struct XW>& vecXW){
    vector<struct XW> vecXW_ret(vecXW.size());
    for(int i=0; i<vecXW.size(); ++i){
        if(vecXW[i].X==0){ continue; }
        
        if      (vecXW[i].W==1){ forword(vecXW_ret, vecXW, i);
        }else if(vecXW[i].W==2){ back   (vecXW_ret, vecXW, i);
        }else                  { printf("ERROR in advance\n"); }
    }
    return vecXW_ret;
}

void print_place(const vector<struct XW>& vecXW){
    for(int i=0; i<vecXW.size(); ++i){
        if(vecXW[i].X==1){
            cout << i/2 << endl;
        }
    }
}

int main(){
    int N, L, T;
    cin >> N >> L >> T;
    L *= 2; // for 0.5 sec
    T *= 2; // for 0.5 sec
    
    vector<struct XW> vecXW(L);
    
    for(int i=0; i<N; ++i){
        int X, W;
        cin >> X >> W;
        X *= 2;
        vecXW[X].X=1;
        vecXW[X].W=W;
    }
    
    for(int t=0; t<T; ++t){
        check_direction(vecXW);
        vecXW = advance(vecXW);
        printf("---\n");
        print_place(vecXW);
    }
    printf("---\n");

    print_place(vecXW);
    
    return 0;
}

// 0.0 sec
//   0  1  2  3  4  5  6  7
//   1        2        1
//   1        2        3     <- AnsNo.

// 1.5 sec
//   0  1  2  3  4  5  6  7
//       12             1
//       12             3    <- AnsNo.

// 2 sec
//   0  1  2  3  4  5  6  7
//      2  1              1
//      1  2              3  <- AnsNo.

// 2.5 sec
//   0  1  2  3  4  5  6  7
//    12    1
//    31    2                <- AnsNo.

// 3.0 sec
//   0  1  2  3  4  5  6  7
//   1  2     1
//   3  1     2              <- AnsNo.


