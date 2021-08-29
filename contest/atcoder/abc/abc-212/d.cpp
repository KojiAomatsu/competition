#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll Q;
  cin >> Q;
  vector<ll> curs(Q + 1);
  ll cur = 0;
  priority_queue<P, vector<P>, function<bool(P, P)>> pq(
      [](P a, P b) { return a.first - a.second > b.first - b.second; });
  rep(i, 0, Q) {
    cur = i;
    int p;
    cin >> p;
    if (p == 1) {
      ll nu;
      cin >> nu;
      pq.push({nu, curs[i]});
      curs[i + 1] = curs[i];
    } else if (p == 2) {
      ll nu;
      cin >> nu;
      curs[i + 1] = curs[i] + nu;
    } else {
      auto top = pq.top();
      pq.pop();
      cout << top.first + curs[i] - top.second << endl;
      curs[i + 1] = curs[i];
    }
  }
}