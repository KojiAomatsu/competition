#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;

  ll le = s.size();
  char las = s[s.size() - 1];
  if (las == 's') {
    cout << s << "es" << endl;
    return 0;
  } else {
    cout << s << "s" << endl;
    return 0;
  }
}