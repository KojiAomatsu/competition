#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  map<ll, ll> dic;
  rep(i, 0, N) {
    cin >> A[i];
    dic[A[i]] += 1;
  }

  ll sum = N * (N - 1) / 2;
  for (auto ele : dic) {
    sum -= ele.second * (ele.second - 1) / 2;
  }
  cout << sum << endl;
}
