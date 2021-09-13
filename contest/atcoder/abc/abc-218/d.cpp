#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  map<P, bool> dic;
  vector<P> points(N);
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    dic[{xi, yi}] = true;
    points[i] = {xi, yi};
  }
  sort(points.begin(), points.end());
  ll ans = 0;
  rep(i, 0, N) rep(j, i + 1, N) {
    if (points[i].first == points[j].first || points[i].second == points[j].second) {
      continue;
    }
    if (dic[{points[i].first, points[j].second}] && dic[{points[j].first, points[i].second}]) {
      ans++;
    }
  }
  cout << ans / 2 << endl;
}
