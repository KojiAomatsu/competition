#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, S, D;
  cin >> N >> S >> D;
  bool flag = false;
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    if (xi < S && yi > D) {
      flag = true;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}
