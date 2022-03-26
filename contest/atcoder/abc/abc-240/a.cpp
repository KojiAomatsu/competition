#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll a, b;
  cin >> a >> b;
  if (b - a == 1 || b - a == 9)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}