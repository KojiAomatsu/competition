#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll n;
  cin >> n;
  bool fl = true;
  if (n == 2 || n == 3 || n == 4) fl = false;
  if (n == 1) fl = true;
  cout << (fl ? "Yes" : "No") << endl;
}