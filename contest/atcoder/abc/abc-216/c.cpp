#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  string ans = "";

  while (N > 0) {
    if (N % 2 == 1) {
      ans += "A";
      N--;
    } else {
      ans += "B";
      N /= 2;
    }
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}