#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> nx(N + 2, -1);
  vector<ll> bf(N + 2, -1);

  rep(i, 0, Q) {
    ll type;
    cin >> type;
    if (type == 3) {
      ll xi;
      cin >> xi;
      ll lea = xi;
      while (xi != -1) {
        lea = xi;
        xi = bf[xi];
      }
      vector<ll> ans;
      while (lea != -1) {
        ans.push_back(lea);
        lea = nx[lea];
      }
      cout << ans.size() << " ";
      rep(i, 0, ans.size()) { cout << ans[i] << " "; }
      cout << endl;
    } else {
      ll xi, yi;
      cin >> xi >> yi;
      if (type == 1) {
        nx[xi] = yi;
        bf[yi] = xi;
      } else {
        nx[xi] = -1;
        bf[yi] = -1;
      }
    }
  }
}