#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  vector<ll> D(N);
  rep(i, 0, N) { cin >> A[i] >> B[i] >> C[i] >> D[i]; }

  atcoder::mf_graph<int> mf(N + N + H + W + 2);
  ll st = N + N + H + W;
  ll gl = N + N + H + W + 1;
  rep(i, 0, H) { mf.add_edge(st, i, 1); }
  rep(i, 0, W) { mf.add_edge(H + i, gl, 1); }
  rep(i, 0, N) {
    mf.add_edge(H + W + i, H + W + N + i, 1);
    rep(j, 0, H) {
      if (A[i] - 1 <= j && C[i] - 1 >= j) {
        mf.add_edge(j, H + W + i, 1);
      }
    }
    rep(j, 0, W) {
      if (B[i] - 1 <= j && D[i] - 1 >= j) {
        mf.add_edge(H + W + N + i, H + j, 1);
      }
    }
  }
  int ans;
  ans = mf.flow(st, gl);
  cout << ans << endl;
}
