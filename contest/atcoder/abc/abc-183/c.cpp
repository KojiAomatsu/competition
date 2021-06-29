#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll T[10][10];

int main() {
  ll N, K;
  cin >> N >> K;
  rep(i, 0, N) {
    rep(j, 0, N) { cin >> T[i][j]; }
  }
  ll ans = 0;
  vector<ll> per;
  rep(i, 1, N) { per.push_back(i); }
  do {
    ll dis = 0;
    dis += T[0][per[0]];
    rep(i, 0, N - 2) { dis += T[per[i]][per[i + 1]]; }
    dis += T[per[N - 2]][0];
    if (dis == K) ans++;
  } while (next_permutation(per.begin(), per.end()));
  cout << ans << endl;
}
