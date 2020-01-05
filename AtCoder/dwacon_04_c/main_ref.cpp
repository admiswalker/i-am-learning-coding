// ref of base: https://atcoder.jp/contests/dwacon2018-prelims/submissions/3318731

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
   
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD=1e9+7;

int main()
{
	int n, m;
	cin>>n>>m;
	int a[101], b[101];
	a[0]=-1, b[0]=-1;
	int cta[101], ctb[101];
	int sa=0, sb=0;
	int ct;
	for(int i=1; i<=n; i++){
		cin>>a[i]; sa+=a[i];
		if(a[i]!=a[i-1]) ct=1;
		cta[i]=ct;
		ct++;
	}
	for(int i=1; i<=m; i++){
		cin>>b[i]; sb+=b[i];
		if(b[i]!=b[i-1]) ct=1;
		ctb[i]=ct;
		ct++;
	}
	ll dpa[1001]={}, dpb[1001]={};
	dpa[0]=1, dpb[0]=1;
	for(int i=1; i<=n; i++){
		for(int j=cta[i]; j<=sb; j++){
			dpa[j]+=dpa[j-cta[i]];
			dpa[j]%=MOD;
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=ctb[i]; j<=sa; j++){
			dpb[j]+=dpb[j-ctb[i]];
			dpb[j]%=MOD;
		}
	}
	cout<<dpa[sb]*dpb[sa]%MOD<<endl;
    return 0;
}
