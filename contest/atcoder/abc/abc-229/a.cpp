#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  bool ans = true;
  if (s1 == "#." && s2 == ".#") ans = false;
  if (s1 == ".#" && s2 == "#.") ans = false;
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}