#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] == s[2]) {
    cout << 1 << endl;
  } else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
    cout << 3 << endl;
  } else {
    cout << 6 << endl;
  }
}