#include <bits/stdc++.h>
using namespace std;

struct XW{
    XW(){ X=0; W=0; }
    ~XW(){}
    int64_t X; // place
    int64_t W; // direction:: 1: forword or 2: back.
};

void invW(struct XW& rhs){
    if      (rhs.W==1){ rhs.W=2;
    }else if(rhs.W==2){ rhs.W=1;
    }else             { printf("ERROR in invW\n"); }
}
void check_direction(vector<struct XW>& vecXW){
    if(vecXW[0].X == vecXW[vecXW.size()-1].X){
        invW(vecXW[0]             );
        invW(vecXW[vecXW.size()-1]);
    }
    for(int i=1; i<vecXW.size(); ++i){
        if(vecXW[i-1].X == vecXW[i].X){
            invW(vecXW[i-1]);
            invW(vecXW[i  ]);
        }
    }
}

bool isForword(struct XW& XW){ if(XW.W==1){ return true; }else{ return false; } }
bool isBack   (struct XW& XW){ if(XW.W==2){ return true; }else{ return false; } }
void advance(vector<struct XW>& vecXW, int L){
    for(int i=0; i<vecXW.size(); ++i){
        if      ( isForword(vecXW[i]) ){ vecXW[i].X += 5; if(vecXW[i].X == L*10){ vecXW[i].X -= L*10; }
//      if      ( isForword(vecXW[i]) ){ vecXW[i].X += 5; if(vecXW[i].X >= (L-1)*10){ vecXW[i].X -= (L-1)*10; }
        }else if( isBack   (vecXW[i]) ){ vecXW[i].X -= 5; if(vecXW[i].X < 0){ vecXW[i].X += L*10; }
        }else                          { printf("ERROR: advance()\n"); }
    }
}

void print_place(const vector<struct XW>& vecXW){
    for(int i=0; i<vecXW.size(); ++i){
        cout << vecXW[i].X/10 << endl;
    }
}

int main(){
    int N, L, T;
    cin >> N >> L >> T;
    
    vector<struct XW> vecXW(N);
    
    for(int i=0; i<vecXW.size(); ++i){
        int X, W; cin >> X >> W;
        vecXW[i].X=X*10;
        vecXW[i].W=W;
    }
    
    for(int64_t t=0; t<T*10; t+=5){
        check_direction(vecXW);
        advance(vecXW, L);
    }
    
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


