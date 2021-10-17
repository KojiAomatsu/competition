#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  bool has_g = true;
  ll cur = A[0];
  vector<ll> ans;
  rep(i, 0, N - 1) {
    ll nex = A[i + 1];
    if (has_g) {
      if (nex >= cur) {
        cur = nex;
        ans.push_back(0);
        continue;
      } else {
        cur = nex;
        has_g = false;
        ans.push_back(1);
      }
    } else {
      if (nex <= cur) {
        cur = nex;
        ans.push_back(0);
        continue;
      } else {
        cur = nex;
        has_g = true;
        ans.push_back(1);
      }
    }
  }

  if (!has_g) {
    if (cur >= A[N - 1]) {
      ans.push_back(1);
    } else {
      auto res = find_if(ans.rbegin(), ans.rend(), [](ll n) { return n == 1; });
      ans[distance(res, ans.rend())] = 0;
      ans.push_back(0);
    }
  } else {
    ans.push_back(0);
  }

  for (auto item : ans) {
    cout << item << " ";
  }
  cout << endl;
}