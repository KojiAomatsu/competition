#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll xi, yi, xj, yj;
  cin >> xi >> yi >> xj >> yj;
  ll dis = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
  set<ll> ans;
  ans.insert(2);
  ans.insert(10);
  ans.insert(16);
  ans.insert(20);
  ans.insert(18);
  ans.insert(4);
  bool fl = ans.count(dis) > 0;
  cout << (fl ? "Yes" : "No") << endl;
}