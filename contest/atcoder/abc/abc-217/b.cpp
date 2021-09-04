#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  set<char> se;
  se.insert('R');
  se.insert('G');
  se.insert('B');
  se.insert('H');
  rep(i, 0, 3) {
    string s;
    cin >> s;
    se.erase(s[1]);
  }
  for (auto c : se) {
    cout << 'A' << c << 'C' << endl;
  }
}