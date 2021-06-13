#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll t, N;
  cin >> t >> N;
  ll left = 1;
  ll right = 1000000000000000;
  while (true) {
    ll mid = (left + right) / 2;
    ll price = mid * (100 + t) / 100;
    if (price - mid >= N) {
      right = mid;
    } else {
      left = mid;
    }
    if (left + 1 == right) {
      break;
    }
  }
  ll ok = left * (100 + t) / 100;
  ll dif = ok - left;
  cout << ok + N - dif << endl;
}