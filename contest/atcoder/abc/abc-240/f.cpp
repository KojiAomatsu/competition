#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll N, ll M, vector<P> &xy) {
  ll ans = -1E12;
  vector<ll> A(N);
  vector<ll> B(N);
  int i = 0;
  ll cur = 0;
  for (auto [x, y] : xy) {
    if (i == 0) {
      ans = max(ans, x);
    }
    A[i] = cur * y;
    A[i] += x * (1 + y) * y / 2;
    cur += x * y;
    B[i] = cur;
    i++;
  }

  ll tmp = 0;
  for (int i = 0; i < N; i++) {
    auto [x, y] = xy[i];
    if (x < 0) {
      if (i != 0 && B[i - 1] > 0) {
        ll div = -x;
        ll pos = min(B[i - 1] / div, y);
        ll sub = B[i - 1] * pos;
        sub += x * (1 + pos) * pos / 2;
        ans = max(ans, tmp + sub);
      }
    }
    tmp += A[i];
    ans = max(ans, tmp);
  }

  return ans;
}

int main() {
  ll T;
  cin >> T;
  rep(i, 0, T) {
    ll N, M;
    cin >> N >> M;
    vector<P> xy;
    rep(j, 0, N) {
      ll xi, yi;
      cin >> xi >> yi;
      xy.push_back(make_pair(xi, yi));
    }
    cout << solve(N, M, xy) << endl;
  }
}