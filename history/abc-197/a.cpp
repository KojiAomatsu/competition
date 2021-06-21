#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  cout << string(1, s[1]) + string(1, s[2]) + string(1, s[0]) << endl;
}
