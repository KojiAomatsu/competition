#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll cnt = 0;
  set<ll> s;
  rep(i, 2, N) {
    if (i * i > N) {
      break;
    }
    ll cur = i;
    while (true) {
      cur *= i;
      if (cur > N) {
        break;
      }
      if (s.count(cur) == 0) {
        s.insert(cur);
        cnt++;
      }
    }
  }

  cout << N - cnt << endl;
}
