#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 階乗
ll factorial(ll a) {
  if (a <= 1) {
    return 1;
  } else {
    return a * factorial(a - 1);
  }
}

// コンビネーション
ll combination(ll n, ll k) {
  if (k == 0 || n == k) {
    return 1;
  }
  if (k == 1 || n - k == 1) {
    return n;
  }
  return combination(n - 1, k - 1) + combination(n - 1, k);
}

vector<vector<ll>> createCombinations(ll n) {
  vector<vector<ll>> combs(n + 1, vector<ll>(n + 1, 1));
  rep(m, 1, n + 1) {
    rep(i, 1, m) { combs[m][i] = combs[m - 1][i - 1] + combs[m - 1][i]; }
  }
  return combs;
}

template <ll m> vector<vector<ll>> combinations(m + 1, vector<ll>(m + 1, 1));
// auto combs = combinations<100>;
// rep(a, 1, 101) {
//   rep(i, 1, a) { combs[a][i] = combs[a - 1][i - 1] + combs[a - 1][i]; }
// }

int main() {
  ll n, k;
  cin >> n >> k;
  vector<vector<ll>> combs;
  combs = createCombinations(n);

  cout << combs[n][k] << endl;
}