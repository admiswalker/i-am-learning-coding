#include <bits/stdc++.h>
using namespace std;

struct TXY{
    int t;
    int x;
    int y;
};

int distance(const struct TXY& lhs, const struct TXY& rhs){
    int dx = abs(lhs.x - rhs.x);
    int dy = abs(lhs.y - rhs.y);
    return dx + dy;
}

int main(){
    int N; cin >> N; N++;
    vector<struct TXY> vecTxy(N);
    vecTxy[0].t = 0;
    vecTxy[0].x = 0;
    vecTxy[0].y = 0;
    for(int i=1; i<vecTxy.size(); ++i){
        cin >> vecTxy[i].t;
        cin >> vecTxy[i].x;
        cin >> vecTxy[i].y;
    }
    
    for(int i=1; i<vecTxy.size(); ++i){
        int t = vecTxy[i].t - vecTxy[i-1].t;
        int d = distance(vecTxy[i-1], vecTxy[i]);
        if(t%d!=0){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

struct TXY{
    int t;
    int x;
    int y;
};

int distance(const struct TXY& lhs, const struct TXY& rhs){
    int dx = abs(lhs.x - rhs.x);
    int dy = abs(lhs.y - rhs.y);
    return dx + dy;
}

int main(){
    int N; cin >> N; N++;
    
    struct TXY txy_prev={0,0,0};
    for(int i=1; i<N; ++i){
        struct TXY txy_now;
        cin >> txy_now.t;
        cin >> txy_now.x;
        cin >> txy_now.y;
        
        int t = txy_now.t - txy_prev.t;
        int d = distance(txy_now, txy_prev);
//        if(t%d!=0){
        if((t+d)&1 || t<d){
            cout << "No";
            return 0;
        }
        txy_prev = txy_now;
    }
    cout << "Yes";
    
    return 0;
}
*/
