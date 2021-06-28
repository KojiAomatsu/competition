#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<vector<ll>> combs(201, vector<ll>(201, 1));
  rep(m, 1, 201) {
    rep(i, 1, m) { combs[m][i] = combs[m - 1][i - 1] + combs[m - 1][i]; }
  }
  cout << combs[N - 1][11] << endl;
}