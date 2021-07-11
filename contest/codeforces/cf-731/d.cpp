#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll num, vector<ll> li) {
  vector<ll> ans;
  ans.push_back(0);
  rep(i, 0, num - 1) {
    ll cur = li[i] ^ ans[i];
    ll nex = li[i + 1];

    ll pt = 1;
    ll an = 0;
    while (pt <= cur) {
      if ((cur & pt) && !(nex & pt)) {
        an += pt;
      }
      pt = pt << 1;
    }
    ans.push_back(an);
  }
  for (auto item : ans) {
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