#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 座標圧縮, Aを受け取って、圧縮後(0 ~ sz-1)になる。
int comp(vector<ll> &A) {
  std::map<ll, ll> mem;
  for (auto p : A)
    mem[p] = 0;
  ll sz = 0;
  for (auto &p : mem)
    p.second = sz++;
  for (auto &p : A)
    p = mem[p];
  return sz;
}

int main() {
  ll N;
  cin >> N;
  vector<P> pres(N);
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> B[i]; }
  comp(A);
  comp(B);
  rep(i, 0, N) { pres[i] = {A[i], B[i]}; }
  sort(pres.begin(), pres.end(), [](P l, P r) {
    if (l.first != r.first) {
      return l.first < r.first;
    } else {
      return l.second > r.second;
    }
  });

  atcoder::fenwick_tree<ll> fw(N);
  ll ans = N;
  rep(i, 0, N) {
    ll s = fw.sum(pres[i].second, N);
    ans += s;
    fw.add(pres[i].second, 1);
  }
  ll samec = 1;
  P ele = {-1, -1};
  rep(i, 0, N) {
    if (ele == pres[i])
      samec++;
    else {
      ele = pres[i];
      ans += samec * (samec - 1) / 2;
      samec = 1;
    }
  }
  ans += samec * (samec - 1) / 2;
  cout << ans << endl;
}
