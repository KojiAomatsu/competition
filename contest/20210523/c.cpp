#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

struct BIT {
private:
  int N;

public:
  vector<ll> bit;
  BIT(ll size) {
    N = size;
    bit.resize(N);
  }

  void add(ll a, ll w) {
    for (ll x = a; x <= N; x += x & -x)
      bit[x] += w;
  }

  ll sum(ll a) {
    ll ret = 0;
    for (ll x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  ll N;
  cin >> N;
  vector<ll> li(N, 0);
  vector<ll> comp(N, 0);
  map<pair<ll, ll>, ll> to_idx_b;
  map<ll, ll> cnta, cntb;
  rep(i, 0, N) {
    ll num;
    cin >> num;
    li[i] = num + i;
  }
  rep(i, 0, N) {
    ll num;
    cin >> num;
    comp[i] = num + i;
    to_idx_b[{num + i, cntb[num + i]++}] = i;
  }
  vector<ll> sw(N);
  for (ll i = 0; i < N; i++) {
    ll target = li[i];
    pair<ll, ll> tmp = {target, cnta[target]++};
    if (to_idx_b.count(tmp) == 0) {
      cout << -1 << endl;
      return 0;
    } else {
      sw[i] = to_idx_b[tmp];
    }
  }

  ll swaps = 0;
  atcoder::fenwick_tree<ll> bi(N);
  rep(i, 0, N) {
    ll num = sw[i];
    bi.add(num, 1);
    swaps += i - bi.sum(0, num);
  }

  cout << swaps << endl;
}
