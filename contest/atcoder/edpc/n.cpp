#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  vector<vector<ll>> dp(N, vector<ll>(N, 0));
  vector<vector<ll>> cost(N, vector<ll>(N, 1E15));
  for (int i = 0; i < N; i++) {
    dp[i][i] = A[i];
    cost[i][i] = 0;
  }
  for (int range = 1; range < N; range++) {
    for (int start = 0; start < N; start++) {
      int end = start + range;
      if (end >= N) continue;
      dp[start][end] = dp[start][start] + dp[start + 1][end];
      for (int div = start; div < end; div++) {
        cost[start][end] = min(cost[start][end], dp[start][end] + cost[start][div] + cost[div + 1][end]);
      }
    }
  }
  cout << cost[0][N - 1] << endl;
}