#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  char a, b, c;
  cin >> a >> b >> c;
  int ai = a - '0';
  int bi = b - '0';
  int ci = c - '0';
  int ans = (ai + bi + ci) * 111;
  cout << ans << endl;
  return 0;
}