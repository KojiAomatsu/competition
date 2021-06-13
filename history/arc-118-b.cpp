#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll K, N, M;
  cin >> K >> N >> M;
  vector<ll> A(K);
  vector<ll> B(K);
  // lib priority queue 使い方
  // l が既存, r が new element. new element の優先度が高い時は true を返すようにする
  auto c = [](pair<ll, pair<ll, ll>> l, pair<ll, pair<ll, ll>> r) {
    return l.second.first == r.second.first ? l.second.second >= r.second.second : l.second.first <= r.second.first;
  };
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, decltype(c)> que(c);
  ll sum = M;
  rep(i, 0, K) {
    cin >> A[i];
    B[i] = A[i] * M / N;
    // bi, { cur score, new score }
    que.push({i, {abs(B[i] * N - A[i] * M), abs(B[i] * (N + 1) - A[i] * M)}});
    sum -= B[i];
  }

  while (que.size() != 0) {
    auto worst = que.top();
    que.pop();
    if (sum > 0) {
      ll bi = B[worst.first]++;
    } else {
      break;
    }
    sum--;
  }
  rep(i, 0, K) { cout << B[i] << " "; }
}