#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  bool is_er = false;
  if (s[s.size() - 2] == 'e' && s[s.size() - 1] == 'r') {
    is_er = true;
  }
  cout << (is_er ? "er" : "ist") << endl;
}