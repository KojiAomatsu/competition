#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W, M;
  cin >> H >> W >> M;
  vector<ll> minh(H + 1, W + 1);
  vector<ll> minw(W + 1, H + 1);
  rep(i, 0, M) {
    ll xi, yi;
    cin >> xi >> yi;
    minh[xi] = min(minh[xi], yi);
    minw[yi] = min(minw[yi], xi);
  }
  ll sumh = 0;
  rep(i, 1, minh[1]) { sumh += minw[i] - 1; }
  ll sumw = 0;
  rep(i, 1, minw[1]) { sumw += minh[i] - 1; }
  atcoder::fenwick_tree<ll> tree(W + 1);
  cout << (sumh + sumw - 11111) << endl;
}