#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll N, M, Q;
ll W[100];
ll V[100];
ll X[100];
ll QL[100];
ll QR[100];

void solve(ll idx) {
  atcoder::mcf_graph<int, ll> mcf(N + M + 2);
  ll st = N + M;
  ll gl = N + M + 1;
  ll mx = 1001001;
  rep(i, 0, N) { mcf.add_edge(st, i, 1, 0); }
  rep(i, 0, N) rep(j, 0, M) {
    if (QL[idx] - 1 <= j && j <= QR[idx] - 1) {
      continue;
    }
    if (W[i] <= X[j]) mcf.add_edge(i, N + j, 1, mx - V[i]);
  }
  rep(i, 0, M) { mcf.add_edge(N + i, gl, 1, 0); }

  int flow;
  ll cost;
  tie(flow, cost) = mcf.flow(st, gl);
  cout << flow * mx - cost << endl;
}

int main() {
  cin >> N >> M >> Q;
  rep(i, 0, N) { cin >> W[i] >> V[i]; }
  rep(i, 0, M) { cin >> X[i]; }
  rep(i, 0, Q) { cin >> QL[i] >> QR[i]; }
  rep(i, 0, Q) { solve(i); }
}
