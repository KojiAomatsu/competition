#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> xs;
  vector<pair<ll, ll>> ys;
  rep(i, 0, N) {
    ll xi;
    ll yi;
    cin >> xi >> yi;
    xs.push_back({i, xi});
    ys.push_back({i, yi});
  }
  sort(xs.begin(), xs.end(), [](const pair<ll, ll> a, const pair<ll, ll> b) {
    return a.second > b.second;
  });
  sort(ys.begin(), ys.end(), [](const pair<ll, ll> a, const pair<ll, ll> b) {
    return a.second > b.second;
  });

  vector<pair<vector<ll>, ll>> comp;

  auto x_big = xs[0];
  auto x_big2 = xs[1];
  auto x_sma = xs.back();
  auto x_sma2 = xs[xs.size() - 2];

  ll x_dist = x_big.second - x_sma.second;
  vector<ll> x_ids = {x_big.first, x_sma.first};
  comp.push_back({x_ids, x_dist});

  ll x2_dist = x_big2.second - x_sma.second;
  vector<ll> x2_ids = {x_big2.first, x_sma.first};
  comp.push_back({x2_ids, x2_dist});

  ll x3_dist = x_big.second - x_sma2.second;
  vector<ll> x3_ids = {x_big.first, x_sma2.first};
  comp.push_back({x3_ids, x3_dist});

  auto y_big = ys[0];
  auto y_big2 = ys[1];
  auto y_sma = ys.back();
  auto y_sma2 = ys[ys.size() - 2];

  ll y_dist = y_big.second - y_sma.second;
  vector<ll> y_ids = {y_big.first, y_sma.first};
  comp.push_back({y_ids, y_dist});

  ll y2_dist = y_big2.second - y_sma.second;
  vector<ll> y2_ids = {y_big2.first, y_sma.first};
  comp.push_back({y2_ids, y2_dist});

  ll y3_dist = y_big.second - y_sma2.second;
  vector<ll> y3_ids = {y_big.first, y_sma2.first};
  comp.push_back({y3_ids, y3_dist});

  sort(comp.begin(), comp.end(),
       [](const pair<vector<ll>, ll> a, const pair<vector<ll>, ll> b) {
         return a.second > b.second;
       });
  auto first_id = comp[0].first;
  auto second_id = comp[1].first;
  if (first_id != second_id) {
    cout << comp[1].second << endl;
  } else {
    cout << comp[2].second << endl;
  }
}