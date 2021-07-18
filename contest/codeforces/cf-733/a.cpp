#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(string s) {
  ll mx = 0;
  rep(i, 0, s.size()) {
    ll nu = s[i] - '0';
    mx = max(mx, nu);
  }
  return mx;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }
}