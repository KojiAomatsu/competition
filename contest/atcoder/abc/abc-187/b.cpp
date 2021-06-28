#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<P> poi(N);
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    poi[i] = {xi, yi};
  }
  sort(poi.begin(), poi.end());
  ll cnt = 0;
  rep(i, 0, N) rep(j, i + 1, N) {
    ll dis = poi[j].first - poi[i].first;
    if (poi[i].second + dis >= poi[j].second && poi[i].second - dis <= poi[j].second) cnt++;
  }
  cout << cnt << endl;
}
