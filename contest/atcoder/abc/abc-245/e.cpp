#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> B[i]; }
  vector<ll> C(M);
  vector<ll> D(M);
  rep(i, 0, M) { cin >> C[i]; }
  rep(i, 0, M) { cin >> D[i]; }

  map<ll, vector<ll>> mp_box;
  rep(i, 0, M) { mp_box[C[i]].push_back(D[i]); }
  vector<P> cands;
  rep(i, 0, N) { cands.push_back(make_pair(A[i], B[i])); }
  sort(cands.begin(), cands.end());
  reverse(cands.begin(), cands.end());

  set<ll> pos;
  auto cur_p = mp_box.rbegin();
  rep(i, 0, N) {
    auto [ai, bi] = cands[i];
    while (cur_p != mp_box.rend() && (*cur_p).first >= ai) {
      for (auto ele : (*cur_p).second) {
        pos.insert(ele);
      }
      cur_p++;
    }
    auto lb = lower_bound(pos.begin(), pos.end(), bi);
    if (lb == pos.end()) {
      cout << "No" << endl;
      return 0;
    }
    pos.erase(lb);
  }
  cout << "Yes" << endl;
}