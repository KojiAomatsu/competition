#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

template <typename... Args>
auto printll(Args... xs) -> decltype(std::initializer_list<ll>{xs...}, std::declval<void>()) {
  for (auto &&x : {xs...}) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<string> A(2 * N);
  rep(i, 0, 2 * N) { cin >> A[i]; }
  vector<P> ranks(2 * N); // i 番目の人が win j
  rep(i, 0, 2 * N) { ranks[i] = {i, 0ll}; }
  rep(i, 0, M) {
    rep(j, 0, N) {
      ll f = ranks[2 * j].first;
      ll s = ranks[2 * j + 1].first;
      ll fh = A[f][i];
      ll sh = A[s][i];
      if ((fh == 'G' && sh == 'C') || (fh == 'C' && sh == 'P') || (fh == 'P' && sh == 'G')) {
        ranks[2 * j] = {f, ranks[2 * j].second + 1};
      }
      if ((fh == 'G' && sh == 'P') || (fh == 'C' && sh == 'G') || (fh == 'P' && sh == 'C')) {
        ranks[2 * j + 1] = {s, ranks[2 * j + 1].second + 1};
      }
    }
    sort(ranks.begin(), ranks.end(), [](P f, P s) {
      if (f.second != s.second) {
        return f.second > s.second;
      } else {
        return f.first < s.first;
      }
    });
  }
  for (auto item : ranks) {
    cout << item.first + 1 << endl;
  }
}
