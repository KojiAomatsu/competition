#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> li(N);
  map<ll, ll> cnt;
  for (auto &ele : li) {
    cin >> ele;
    cnt[ele % 200] += 1;
  }
  ll res;
  for (auto val : cnt) {
    res += val.second * (val.second - 1) / 2;
  }
  cout << res << endl;
}
