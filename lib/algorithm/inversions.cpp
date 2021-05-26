#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 1-indexedなので注意。
struct BIT {
private:
  vector<ll> bit;
  int N;

public:
  BIT(ll size) {
    N = size;
    bit.resize(N + 1);
  }

  // 一点更新です
  void add(ll a, ll w) {
    for (int x = a; x <= N; x += x & -x)
      bit[x] += w;
  }

  // 1~Nまでの和を求める。
  int sum(ll a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  ll N;
  cin >> N;
}
