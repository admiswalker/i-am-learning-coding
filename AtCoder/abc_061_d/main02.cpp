// https://atcoder.jp/contests/abc061/submissions/1285827

/* vim:set foldmethod=marker: */
#include <bits/stdc++.h>
using namespace std;

//{{{
#define all(x) (x).begin(),(x).end()
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); i++)
#define RREP(i,a,b) for(int i=(int)(a); i>=b; i--)
#define rep(i,n) REP(i,0,n)
#define rrep(i,n) RREP(i,n,0)
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

#define dump(x) (cerr << #x << "=" << x << endl)
template<class T> ostream& osContainer(ostream& os,T c) { os<<'[';for(decltype(c.begin()) it=c.begin();it!=c.end();it++)os<<*it<<',';os<<']';return os; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { return osContainer(os,v); }
template<class T> ostream& operator<<(ostream& os,const set<T>& s) { return osContainer(os,s); }
template<class T> ostream& operator<<(ostream& os,const multiset<T>& s) { return osContainer(os,s); }
template<class T,class S> ostream& operator<<(ostream& os,const map<T,S>& m) { return osContainer(os,m); }
template<class T,class S> ostream& operator<<(ostream& os,const multimap<T,S>& m) { return osContainer(os,m); }
template<class T1,class T2>
ostream& operator<<(ostream& os, const pair<T1,T2>& p){ os << '(' << p.first << ',' << p.second << ')'; return os; }

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
//}}}
//
struct edge{int from, to, cost;};

edge es[2001];

ll d[1001];
const ll INF = 1e15;
int V, E;

bool shortest_path(int s) {
    rep(i, V+1) d[i] = INF;
    d[s] = 0;

    int c = 0;
    ll postdv = d[V];
    while(true) {
        bool update = false;
        c++;
        rep(i, E) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        bool change_dv = d[V] != postdv;
        if (!update) return true;
        if (!change_dv && c >= V-1) return true;
        if (c >= V-1) return false;
        postdv = d[V];
    }
}

void solve()
{
    cin >> V >> E;

    rep(i, E) {
        int a, b, c;
        cin >> a >> b >>c;
        es[i] = {a,b,-c};
    }

    if (shortest_path(1)) {
        cout << -d[V] << endl;
    } else {
        cout << "inf" << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(12);
    solve();
}
