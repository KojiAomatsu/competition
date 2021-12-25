#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  vector<ll> sums(N + 1, 0);
  rep(i, 0, N) { sums[i + 1] = sums[i] + A[i]; }
  ll ans = 0;
  map<ll, ll> cnt;
  rep(i, 1, N + 1) {
    if (sums[i] == K) ans++;
    ans += cnt[sums[i] - K];
    cnt[sums[i]]++;
  }

  cout << ans << endl;
}
