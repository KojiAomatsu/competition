#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  string S;
  cin >> N >> S;

  string ans = "";
  ll cnt = 0;
  rep(i, 0, N) {
    if (S[i] == 'C') {
      ans += string(cnt / 2, 'A');
      ans += string(cnt % 2, 'B');
      cnt = 0;
      ans += 'C';
    } else if (S[i] == 'B') {
      cnt += 1;
    } else {
      cnt += 2;
    }
  }
  ans += string(cnt / 2, 'A');
  ans += string(cnt % 2, 'B');
  cout << ans << endl;
}