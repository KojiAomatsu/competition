#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll N;
  cin >> N;
  vector<P> pos(N);
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    pos[i] = {xi, yi};
  }
  vector<P> als;
  vector<P> cands;
  rep(i, 0, N) rep(j, i + 1, N) {
    auto [xi, yi] = pos[i];
    auto [xj, yj] = pos[j];
    ll x = xi - xj;
    ll y = yi - yj;
    bool fl = true;
    for (auto al : als) {
      if (al.first * y == al.second * x) {
        fl = false;
        break;
      }
    }
    if (fl) {
      als.push_back({x, y});
    }
  }
  cout << als.size() * 2 << endl;
}