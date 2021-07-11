#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
ll mod = 1E9 + 7;

int main() {
  ll N;
  cin >> N;
  vector<ll> C(N);
  rep(i, 0, N) { cin >> C[i]; }
  sort(C.begin(), C.end());
  ll ans = 1;
  rep(i, 0, N) {
    if (C[i] - i < 0) break;
    ans = ans * (C[i] - i) % mod;
  }
  cout << ans << endl;
}