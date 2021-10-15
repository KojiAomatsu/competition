#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string strN;
  cin >> strN;
  priority_queue<ll> q;
  rep(i, 0, strN.size()) { q.push(strN[i] - '0'); }
  ll a, b;
  while (!q.empty()) {
    ll t = q.top();
    q.pop();
    if (a == b) {
      a = a * 10 + t;
    } else if (a < b) {
      a = a * 10 + t;
    } else {
      b = b * 10 + t;
    }
  }

  cout << a * b << endl;
  return 0;
}
