#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  int le = s.length();
  int last = s[le - 1] - '0';
  string appe = "";
  if (last <= 2) {
    appe = "-";
  } else if (last <= 6) {
    appe = "";
  } else {
    appe = "+";
  }

  string ans = s.substr(0, le - 2);
  ans += appe;
  cout << ans << endl;
}