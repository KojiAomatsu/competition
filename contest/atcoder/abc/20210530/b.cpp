#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;

  ll sum_digit_1 = K * (K + 1) / 2;
  ll sum_digit_3 = N * (N + 1) / 2;

  ll sum = sum_digit_3 * K * 100 + sum_digit_1 * N;
  cout << sum << endl;
}