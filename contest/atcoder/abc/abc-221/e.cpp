#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }

  atcoder::dsu d(100);

  return 0;
}

// 座標圧縮, Aを受け取って、圧縮後(0 ~ sz-1)になる。
int comp(vector<int> &A) {
  std::map<int, int> mem;
  for (auto p : A)
    mem[p] = 0;
  int sz = 0;
  for (auto &p : mem)
    p.second = sz++;
  for (auto &p : A)
    p = mem[p];
  return sz;
}
