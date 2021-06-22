#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  bool flag = true;
  rep(i, 0, s.size()) {
    if (i % 2 == 0) {
      bool yes = s[i] - 'a' >= 0;
      if (!yes) {
        flag = false;
      }
    } else {
      bool yes = 'Z' - s[i] >= 0;
      if (!yes) {
        flag = false;
      }
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}
