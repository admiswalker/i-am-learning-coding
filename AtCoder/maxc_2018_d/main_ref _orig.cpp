#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

const int cm = 1 << 16;
char ci[cm];
char *cn = ci + cm;
inline char getcha() {
	if (cn - ci == cm) { fread(ci, 1, cm, stdin); cn = ci; }
	return *cn++;
}

inline int getint() {
	char C = getcha();
	int A = C - '0';
	while ((C = getcha()) >= '0') A = A * 10 + C - '0';
	return A;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int N, M, L, X;
	N = getint();
	M = getint();
	L = getint();
	X = getint();
	
	vector<int> V[1000];

	rep(i, N) {
		int a = getint();
		int b = a / M;
		int c = a % M;
		V[c].pb(b);
	}

	int D[2][1000];
	rep(i, 2000) *(D[0] + i) = 1e9;
	D[0][0] = 1;
	D[1][0] = 1;
	rep1(i, M - 1) {
		if (V[i].size()) {
			sort(V[i].begin(), V[i].end());
			vector<pair<int, int>> V2;
			int k1 = 0;
			int k2 = 0;
			for (int j : V[i]) {
				k1 += i;
				k2 += j;
				if (k1 >= M) {
					k1 -= M;
					k2++;
				}
				if (k1 == 0) continue;
				V2.pb(mp(k1, k2));
			}
			vector<pair<int, int>> V3;
			rep(j, M) {
				if (*(D[0] + j) < 5e8) {
					for (auto p : V2) {
						int b = p.first;
						int c = p.second;
						if (j + b >= M) {
							b -= M;
							c++;
						}
						*(D[1] + j + b) = min(*(D[1] + j + b), *(D[0] + j) + c);
					}
				}
			}
			if (*(D[1] + L) < X) {
				co("Yes");
				return 0;
			}
			memcpy(D[0], D[1], 4 * M);
		}
	}

	co("No");

	Would you please return 0;
}
