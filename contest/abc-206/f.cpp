#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[110][110];

int main() {
  ll t;
  cin >> t;
  rep(i, 0, t) {
    ll N;
    cin >> N;
    vector<ll> L(N);
    vector<ll> R(N);
    rep(j, 0, N) { cin >> L[j] >> R[j]; }

    rep(ii, 1, 100) {
      rep(jj, 1, 100) {
        ll l = jj;
        ll r = jj + ii;
        if (r > 100) {
          break;
        }

        set<ll> s;
        rep(k, 0, N) {
          if (L[k] >= l && R[k] <= r) {
            s.insert(dp[l][L[k]] ^ dp[R[k]][r]);
          }
        }
        ll min = 0;
        while (true) {
          if (s.count(min)) {
            min++;
          } else {
            break;
          }
        }
        dp[l][r] = min;
      }
    }

    ll grundy = dp[1][100];
    cout << (grundy ? "Alice" : "Bob") << endl;
  }
}
