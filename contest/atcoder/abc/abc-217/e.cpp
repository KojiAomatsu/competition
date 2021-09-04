#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll Q;
  cin >> Q;
  priority_queue<ll, vector<ll>, greater<ll>> firq;
  queue<ll> secq;
  rep(i, 0, Q) {
    ll qi;
    cin >> qi;
    if (qi == 1) {
      ll xi;
      cin >> xi;
      secq.push(xi);
    } else if (qi == 2) {
      if (firq.empty()) {
        ll top = secq.front();
        secq.pop();
        cout << top << endl;
      } else {
        ll top = firq.top();
        firq.pop();
        cout << top << endl;
      }
    } else {
      while (!secq.empty()) {
        ll top = secq.front();
        secq.pop();
        firq.push(top);
      }
    }
  }
}