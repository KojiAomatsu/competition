#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[5500][5500];       // 後ろから i 番目から j 個分とった時の合計
double prob[5500][5500]; // 後ろから i 番目から j 個分とった時の期待値

int main() {
  ll N, M, S;
  cin >> N >> M >> S;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  reverse(A.begin(), A.end());
  rep(i, 0, N) {
    rep(j, 0, N) {
      ll idx = i + j;
      if (idx >= N) {
        break;
      }
      dp[i][j + 1] = dp[i][j] + A[i + j];
    }
  }
  rep(i, 0, N) {
    rep(j, 0, N) {
      ll idx = i + j;
      if (idx >= N) {
        break;
      }
      prob[i][j + 1] = (double)(dp[i][j + 1]) / (j + 1);
    }
  }
  vector<ll> max_prob_nums(N);
  rep(i, 0, N) {
    double mx = 0;
    rep(j, 0, N) {
      if (prob[i][j + 1] > mx) {
        mx = prob[i][j + 1];
        max_prob_nums[i] = j + 1;
      }
    }
  }
  ll cnt = 0;
  double ans = 0;
  while (cnt < N) {
    ll num = max_prob_nums[cnt];
    double tar = M;
    if (M * num > S) {
      tar = (double)S / num;
      S = 0;
    } else {
      S -= M * num;
    }
    ans += tar * dp[cnt][num];
    cnt += num;
  }
  printf("%.11f", ans);
}