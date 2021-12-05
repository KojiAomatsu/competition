#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;

  ll ans = 0;
  ll le = 1;
  char cur = '-';
  rep(i, 0, N) {
    if (S[i] == cur) {
      le += 1;
    } else {
      ans += le * (le - 1) / 2;
      le = 1;
      cur = S[i];
    }
  }
  ans += le * (le - 1) / 2;
  cout << ans << endl;
}