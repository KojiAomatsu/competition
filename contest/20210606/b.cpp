#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll ret = 0;
  rep(i, 0, N) {
    ll num;
    cin >> num;
    if (num <= 10) {
      continue;
    } else {
      ret += num - 10;
    }
  }
  cout << ret << endl;
}