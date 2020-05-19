// ref: https://atcoder.jp/contests/abc090/submissions/2196508

// Tweet
// ABC 090 D RemainderReminder
// https://beta.atcoder.jp/contests/abc090/submissions/2196508
// 
// 昨日のD問題をまとめて、ACしてきた。
// やはり重要なのは、a % b ≧ Kの条件のうち、aを固定して考えることだと思う。
// その結果、変数がbのみになり、O(N)で解けるようになる。
// O(N^2)になるような時に、この発想が必要になってくるのか……？
// 
// ref: https://twitter.com/task4233/status/973160336474828800
//      <blockquote class="twitter-tweet"><p lang="ja" dir="ltr">ABC 090 D RemainderReminder<a href="https://t.co/94ymCHhwfx">https://t.co/94ymCHhwfx</a><br><br>昨日のD問題をまとめて、ACしてきた。<br>やはり重要なのは、a % b ≧ Kの条件のうち、aを固定して考えることだと思う。<br>その結果、変数がbのみになり、O(N)で解けるようになる。<br>O(N^2)になるような時に、この発想が必要になってくるのか……？ <a href="https://t.co/MK5QCEZRAv">pic.twitter.com/MK5QCEZRAv</a></p>&mdash; Tasker (@task4233) <a href="https://twitter.com/task4233/status/973160336474828800?ref_src=twsrc%5Etfw">March 12, 2018</a></blockquote> <script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>

// ------------------------------------
// Date:2018/ 3/11
// Problem:ABC 090 . d.cpp
//
// ------------------------------------

#include <bits/stdc++.h>

using namespace std;

#define EACH(i,a) for (auto&& i : a)
#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define debug(x) cerr << #x << ":" << x << endl

typedef long long ll;

static const int MOD = 1000000007;

bool state[101010];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  /*
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  */

  ll ans = 0ll;
  FOR(bi, K + 1, N + 1) {
    ll tmp = (N + 1) / bi;
    ans += tmp * (bi - min(K, bi));
    ans += max(0, ((N + 1) % bi) - K);
    if (K == 0) {
      // グループを形成できない中途半端なものを求めるときに、+1(0の分)を引く必要がある
      ans--;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

