#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  map<ll, ll> sums;
  rep(i, 0, N) {
    ll ai, bi;
    cin >> ai >> bi;
    sums[ai] += bi;
  }

  ll cur_sum = 0;
  for (auto item : sums) {
    ll limit = K + cur_sum;
    if (limit < item.first) {
      break;
    }
    cur_sum += item.second;
  }

  cout << K + cur_sum << endl;
}