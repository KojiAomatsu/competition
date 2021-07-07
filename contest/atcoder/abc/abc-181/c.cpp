#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// 外積の実装例

ll cross(P ori, P pi, P pj) {
  ll vix = pi.first - ori.first;
  ll viy = pi.second - ori.second;
  ll vjx = pj.first - ori.first;
  ll vjy = pj.second - ori.second;
  return vix * vjy - viy * vjx;
}

int main() {
  ll N;
  cin >> N;
  vector<P> A(N);
  rep(i, 0, N) {
    ll xi, yi;
    cin >> xi >> yi;
    A[i] = {xi, yi};
  }
  bool fl = false;
  rep(i, 0, N) rep(j, i + 1, N) rep(k, j + 1, N) {
    if (cross(A[i], A[j], A[k]) == 0) {
      fl = true;
    }
  }
  cout << (fl ? "Yes" : "No") << endl;
}