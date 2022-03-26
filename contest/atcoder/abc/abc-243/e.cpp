#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M);
  vector<ll> B(M);
  vector<ll> C(M);
  vector<vector<ll>> dis(N, vector<ll>(N));
  vector<vector<vector<ll>>> used(N, vector<vector<ll>>(N));
  rep(i, 0, M) {
    ll ai, bi, ci;
    cin >> ai >> bi >> ci;
    ai--;
    bi--;
    dis[ai][bi] = ci;
    used[ai][bi] = {i};
    dis[bi][ai] = ci;
    used[bi][ai] = {i};
  }

  rep(k, 0, N) rep(i, 0, N) rep(j, 0, N) { if (dis[i][k] + dis[k][j] < dis[i][j]) }
}