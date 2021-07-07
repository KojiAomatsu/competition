#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll n, ll k) {
  ll tmpn = n;
  ll logx = 0;
  vector<ll> dign;
  while (tmpn > 0) {
    ll rem = tmpn % k;
    dign.push_back(rem);
    tmpn /= k;
  }
  reverse(dign.begin(), dign.end());
  vector<bool> op(dign.size(), false);
  rep(i, 0, n) {
    // bit calc
    ll qu = i;
    rep(j, 0, dign.size()) {
      if (op[j]) {
        qu ^= 1 << j;
      }
    }

    cout << qu << endl;
    cout.flush();
    ll res;
    cin >> res;
    if (res == 1) {
      return;
    }

    // bit set
    rep(j, 0, dign.size()) {
      if (qu & 1 << j) {
        op[j] = ~op[j];
      }
    }
  }
  return;
}

int main() {
  ll t;
  cin >> t;
  rep(i, 0, t) {
    ll n, k;
    cin >> n >> k;
    solve(n, k);
  }
}