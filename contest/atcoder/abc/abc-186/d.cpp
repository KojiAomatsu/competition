#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  sort(A.begin(), A.end());
  vector<ll> sums(N);
  ll cur = 0;
  rep(i, 0, N) {
    cur += A[i];
    sums[i] = cur;
  }
  ll ans = 0;
  rep(i, 0, N) {
    ll al = sums[N - 1];
    ll s = al - sums[i] - A[i] * (N - 1 - i);
    ans += s;
  }
  cout << ans << endl;
}
