#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  ll K;
  cin >> N >> K;
  ll res = N;
  rep(i, 0, K) {
    if (res % 200 == 0) {
      res /= 200;
    } else {
      res = res * 1000 + 200;
    }
  }
  cout << res << endl;
}
