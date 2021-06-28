#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  rep(i, 1, 1E6) {
    if (A + B * i <= C * D * i) {
      cout << i << endl;
      return 0;
    }
  }
  if (C < B) {
    cout << -1 << endl;
    return 0;
  }
  ll num = 1;
  while (true) {
    if (A + B * num <= C * num * D) {
      break;
    }
    num++;
  }
  cout << num << endl;
}