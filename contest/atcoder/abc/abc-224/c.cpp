#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N);
  vector<ll> Y(N);
  rep(i, 0, N) { cin >> X[i] >> Y[i]; }
  ll cnt = 0;
  rep(i, 0, N - 2) {
    rep(j, i, N - 1) {
      rep(k, j, N) {
        ll x1 = X[j] - X[i];
        ll y1 = Y[j] - Y[i];
        ll x2 = X[k] - X[i];
        ll y2 = Y[k] - Y[i];
        if (x1 * y2 != x2 * y1) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
}