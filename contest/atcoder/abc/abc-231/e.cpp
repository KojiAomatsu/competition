#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }

  map<ll, ll> lim;
  rep(i, 0, N - 1) { lim[A[i]] = A[i + 1] / A[i]; }

  ll payc = 0;
  ll over = 0;
  rep(i, 0, N) {
    if (A[i] >= X) {
      payc = 1;
      over = A[i];
      break;
    }
  }

  if (payc != 1) {
    ll div = X / A[N - 1];
    ll rem = X % A[N - 1];
    if (rem > 0) div++;
    payc = div;
    over = A[N - 1] * div;
  }

  ll rem = over - X;
  map<ll, ll> remmp;
  for (int i = N - 1; i >= 0; i--) {
    ll div = rem / A[i];
    rem %= A[i];
    remmp[A[i]] = div;
  }
  ll paymorec = 0;
  rep(i, 0, N - 1) {
    ll remc = remmp[A[i]];
    if (2 * (lim[A[i]] - remc) <= lim[A[i]] - 1) {
      remmp[A[i]] = 0;
      remmp[A[i + 1]]++;
      paymorec += lim[A[i]] - remc;
    }
  }

  ll rems = 0;
  for (auto r : remmp) {
    rems += r.second;
  }

  ll p = over / payc;
  ll last = min(payc, remmp[p]) * 2;
  cout << payc + paymorec + rems - last << endl;
}
