#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll curstart = -1;
  ll curend = -1;
  ll useddots = 0;
  ll maxi = 0;
  while (true) {
    curend++;
    if (curend >= s.size()) break;
    if (s[curend] == 'X') {
      maxi = max(maxi, curend - curstart);
    } else {
      useddots++;
      if (useddots > k) {
        while (curstart <= curend) {
          curstart++;
          if (s[curstart] == '.') {
            useddots--;
            break;
          }
        }
      }
      maxi = max(maxi, curend - curstart);
    }
  }
  cout << maxi << endl;
}