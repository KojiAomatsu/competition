#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[440][440];
bool is_friend[440][440];
ll mod = 998244353;

int main() {
  ll N, M;
  cin >> N >> M;
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    is_friend[ai][bi] = true;
    is_friend[bi][ai] = true;
  }
  rep(wi, 1, N + 1) {
    ll width = wi * 2;
    rep(i, 0, 2 * N) {
      ll j = i + width;
      if (j > 2 * N) {
        break;
      }
      bool ok = true;
      rep(ord, 0, wi) {
        if (!is_friend[i + ord][j - ord - 1]) {
          ok = false;
          break;
        }
      }
      dp[i][j] = ok ? 1 : 0;
      ll num = 0;
      rep(idx, 1, wi) {
        ll tmp = dp[i][i + 2 * idx] * dp[i + 2 * idx][j] % mod;
        num += tmp;
        num %= mod;
      }
      dp[i][j] += 2 * num;
      dp[i][j] %= mod;
    }
  }
  cout << dp[0][2 * N] << endl;
}