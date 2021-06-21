#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll left = 0;
  ll right = 1E9;
  while (left + 1 < right) {
    ll mid = (left + right) / 2;
    if ((mid * (mid + 1)) >= 2 * N) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;
}
