#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  ll sz = 0;
  rep(i, 0, s.size()) {
    if (s[i] == '.')
      break;
    sz++;
  }
  cout << s.substr(0, sz) << endl;
}
