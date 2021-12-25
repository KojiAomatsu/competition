#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string X;
  cin >> X;
  vector<int> xs;
  rep(i, 0, X.size()) { xs.push_back(X[i] - '0'); }
  vector<ll> sums(X.size() + 1, 0);
  rep(i, 0, X.size()) { sums[i + 1] = sums[i] + xs[i]; }
  sums.erase(sums.begin());
  reverse(sums.begin(), sums.end());
  ll cur = 0;
  vector<ll> anss(X.size(), 0);
  rep(i, 0, X.size()) {
    anss[i] = (sums[i] + cur) % 10;
    cur = (sums[i] + cur) / 10;
  }
  reverse(anss.begin(), anss.end());
  if (cur > 0) {
    cout << cur;
  }
  rep(i, 0, X.size()) { cout << anss[i]; }
  cout << endl;
}
