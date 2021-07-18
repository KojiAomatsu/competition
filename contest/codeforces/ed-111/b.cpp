#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll le, ll a, ll b, string s) {
  ll ans = 0;
  if (b >= 0) {
    ans = le * (a + b);
    return ans;
  }

  ll num_0 = 0;
  ll num_1 = 0;
  char cur_char = s[0];
  rep(i, 1, le) {
    if (cur_char != s[i]) {
      if (s[i] == '1') {
        num_0++;
        cur_char = '1';
      } else {
        num_1++;
        cur_char = '0';
      }
    }
  }
  if (s[le - 1] == '1') {
    num_1++;
  } else {
    num_0++;
  }
  ans = a * le;
  ans += b * (min(num_0, num_1) + 1);
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le, a, b;
    cin >> le >> a >> b;
    string s;
    cin >> s;
    cout << solve(le, a, b, s) << endl;
  }
}