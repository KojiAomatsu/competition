#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<vector<ll>> createCombinations(ll n) {
  vector<vector<ll>> combs(n + 1, vector<ll>(n + 1, 1));
  rep(m, 1, n + 1) {
    rep(i, 1, m) { combs[m][i] = combs[m - 1][i - 1] + combs[m - 1][i]; }
  }
  return combs;
}

int main() {
  long long num_a, num_b, k;
  cin >> num_a >> num_b >> k;

  long long all_sum = num_a + num_b;
  string result = "";

  for (int i = 0; i < all_sum; i++) {
    if (num_a == 0) {
      result += "b";
      continue;
    }
    if (num_b == 0) {
      result += "a";
      continue;
    }
    long long sum = num_a + num_b;
    vector<vector<ll>> combs;
    combs = createCombinations(sum - 1);
    long long comb = combs[sum - 1][num_a - 1];
    if (comb >= k) {
      result += "a";
      num_a -= 1;
    } else {
      result += "b";
      num_b -= 1;
      k -= comb;
    }
  }
  cout << result << endl;
}