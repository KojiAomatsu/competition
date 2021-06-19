#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll inf = 10000000001;
void solve(ll num, vector<ll> li) {
  sort(li.begin(), li.end());
  if (num == 2) {
    for (auto item : li) {
      cout << item << " ";
    }
    cout << endl;
    return;
  }
  P min = {inf, 0};
  ll bef = inf;
  rep(i, 0, li.size()) {
    ll di = bef - li[i];
    if (abs(min.first) > abs(di)) {
      min = {di, i};
    }
    bef = li[i];
  }
  auto pre = vector(li.begin(), li.begin() + min.second);
  auto post = vector(li.begin() + min.second, li.end());

  for (auto item : post) {
    cout << item << " ";
  }
  for (auto item : pre) {
    cout << item << " ";
  }
  cout << endl;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(le);
    rep(j, 0, le) { cin >> li[j]; }
    solve(le, li);
  }
}
