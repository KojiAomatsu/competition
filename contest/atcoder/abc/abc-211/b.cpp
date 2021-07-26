#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  set<string> se;
  se.insert("3B");
  se.insert("HR");
  se.insert("2B");
  se.insert("H");
  rep(i, 0, 4) {
    string s;
    cin >> s;
    se.erase(s);
  }
  cout << (se.size() == 0 ? "Yes" : "No") << endl;
}