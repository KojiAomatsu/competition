#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  rep(i, 0, M) { cin >> A[i]; }
  if (M == 0) {
    cout << 1 << endl;
    return 0;
  }
  sort(A.begin(), A.end());
  vector<ll> dif;
  ll prev = 0;
  rep(i, 0, M) {
    ll num = A[i] - prev - 1;
    if (num != 0) {
      dif.push_back(num);
    }
    prev = A[i];
  }
  ll la = N - A[M - 1];
  if (la != 0) {
    dif.push_back(la);
  }

  ll k = 1001001001;
  for (auto di : dif) {
    k = min(k, di);
  }
  ll ans = 0;
  for (auto di : dif) {
    if (di % k == 0) {
      ans += di / k;
    } else {
      ans += di / k + 1;
    }
  }
  cout << ans << endl;
}