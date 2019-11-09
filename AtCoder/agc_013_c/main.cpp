#include <bits/stdc++.h>
using namespace std;

struct XW{
    XW(){ X=0; W=0; }
    ~XW(){}
    int X; // place
    int W; // direction:: 1: forword or 2: back.
};

bool isForword(const struct XW& XW){ if(XW.W==1){ return true; }else{ return false; } }
bool isBack   (const struct XW& XW){ if(XW.W==2){ return true; }else{ return false; } }

struct XW invW(const struct XW& rhs){
    struct XW lhs = rhs;
    if      (rhs.W==1){ lhs.W=2; return lhs;
    }else if(rhs.W==2){ lhs.W=1; return lhs;
    }else             { printf("ERROR in invW\n");
    }
    return lhs;
}
struct XW advanceX(const struct XW& rhs, int L){
    struct XW lhs = rhs;
    if      (rhs.W==1){ lhs.X++; if(lhs.X>=L){lhs.X=0;  } return lhs;
    }else if(rhs.W==2){ lhs.X--; if(lhs.X< 0){lhs.X=L-1;} return lhs;
    }else             { printf("ERROR in invW\n");
    }
    return lhs;
}

bool isSameDirection(const struct XW& lhs, const struct XW& rhs){ return lhs.W == rhs.W; }
int distance(const struct XW& lhs, const struct XW& rhs, const int L){
    int small = min(lhs.X, rhs.X);
    int large = max(lhs.X, rhs.X);
    int d1 = L - large + small;
    int d2 = abs(lhs.X - rhs.X);
    return min(d1, d2);
}

vector<struct XW> advanceXW(const vector<struct XW>& vecXW, int L){
    vector<struct XW> vecXW_ret(vecXW.size());
    
    for(int i=0; i<vecXW.size(); ++i){
        int p = i-1; if(i==0           ){ p=vecXW.size()-1; } // prev
        int h = i  ;                                          // here
        int n = i+1; if(n==vecXW.size()){ n=0;              } // next
        
        int d; if( isBack(vecXW[h]) ){ d=p; }else{ d=n; } // place of direction
        
        if(isSameDirection(vecXW[h], vecXW[d])){
            vecXW_ret[h] = advanceX(vecXW[h] , L);
        }else{
            int dis = distance(vecXW[h], vecXW[d], L);
//            printf("h: %d, d: %d, dis: %d\n", h, d, dis);
            if      (dis==0){ vecXW_ret[h] = advanceX(invW(vecXW[h]), L);
            }else if(dis==1){ vecXW_ret[h] =          invW(vecXW[h]);
            }else           { vecXW_ret[h] = advanceX(     vecXW[h],  L);
            }
        }
    }
    return vecXW_ret;
}

void print_place(const vector<struct XW>& vecXW){
    for(int i=0; i<vecXW.size(); ++i){
        if(vecXW[i].X==0){
            cout << 0 << endl;
        }else{
            cout << vecXW[i].X << endl;
        }
    }
}

int main(){
    int N, L, T;
    cin >> N >> L >> T;
    
    vector<struct XW> vecXW(N);
    
    for(int i=0; i<vecXW.size(); ++i){
        int X, W; cin >> X >> W;
        vecXW[i].X=X;
        vecXW[i].W=W;
    }
    
    for(int64_t t=0; t<T; ++t){
        vecXW = advanceXW(vecXW, L);
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


