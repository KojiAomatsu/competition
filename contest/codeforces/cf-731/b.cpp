#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool solve(string s) {
  ll le = s.size();
  char target = 'a' + le - 1;
  while (le > 0) {
    if (s[0] == target) {
      s = s.substr(1, le - 1);
    } else if (s[le - 1] == target) {
      s = s.substr(0, le - 1);
    } else {
      return false;
    }
    le--;
    target -= 1;
  }
  if (le == 0) {
    return true;
  }
  return false;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    string s;
    cin >> s;
    cout << (solve(s) ? "Yes" : "No") << endl;
  }
}