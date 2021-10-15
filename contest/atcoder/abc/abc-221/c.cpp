#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string strN;
  cin >> strN;
  priority_queue<ll> q;
  rep(i, 0, strN.size()) { q.push(strN[i] - '0'); }
  ll ma = 0;
  rep(i, 1, 1 << strN.size()) {
    vector<ll> as;
    vector<ll> bs;
    rep(j, 0, strN.size()) {
      if (i & (1 << j)) {
        as.push_back(strN[j] - '0');
      } else {
        bs.push_back(strN[j] - '0');
      }
    }

    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    reverse(as.begin(), as.end());
    reverse(bs.begin(), bs.end());

    ll a = 0;
    rep(i, 0, as.size()) { a = a * 10 + as[i]; }
    ll b = 0;
    rep(i, 0, bs.size()) { b = b * 10 + bs[i]; }

    ma = max(ma, a * b);
  }

  cout << ma << endl;
  return 0;
}
