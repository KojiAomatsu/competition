#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll Q;
  cin >> Q;
  ll qs[Q][3];
  rep(i, 0, Q) rep(j, 0, 3) { cin >> qs[i][j]; }
  string pre = S.substr(0, N);
  string post = S.substr(N, N);

  for (auto q : qs) {
    if (q[0] == 2) {
      swap(pre, post);
    } else {
      auto ai = q[1] - 1;
      auto bi = q[2] - 1;
      if (ai < N && bi < N) {
        swap(pre[ai], pre[bi]);
      } else if (ai >= N && bi < N) {
        swap(post[ai - N], pre[bi]);
      } else if (ai < N && bi >= N) {
        swap(pre[ai], post[bi - N]);
      } else {
        swap(post[ai - N], post[bi - N]);
      }
    }
  }
  cout << pre + post << endl;
}