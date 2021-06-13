#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll K, N, M;
  cin >> K >> N >> M;
  vector<ll> A(K);
  vector<ll> B(K);
  vector<pair<ll, ll>> scores(K);
  ll sum = 0;
  rep(i, 0, K) {
    cin >> A[i];
    B[i] = A[i] * M / N;
    // bi, { cur score, new score }
    scores.push_back({A[i] * M - B[i] * N, i});
    sum += B[i];
  }

  sort(scores.begin(), scores.end());
  reverse(scores.begin(), scores.end());

  rep(i, sum, M) { B[scores[i - sum].second]++; }

  rep(i, 0, K) { cout << B[i] << " "; }
}