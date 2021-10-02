#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> sums(N + 1);
  rep(i, 0, N) {
    cin >> A[i];
    sums[i + 1] = sums[i] + A[i];
  }
  ll X;
  cin >> X;

  ll ans;
  ans += (X / sums[N]) * N;
  ll res = X % sums[N];
  auto it = upper_bound(sums.begin(), sums.end(), res);
  ans += (it - sums.begin());
  cout << ans << endl;
}