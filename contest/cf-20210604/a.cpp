#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool judge(vector<pair<ll, ll>> skills) {
  sort(skills.begin(), skills.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; });
  auto highest = skills[0];
  auto second = skills[1];
  return (highest.first / 2 + second.first / 2) == 1;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    vector<pair<ll, ll>> skills;
    rep(j, 0, 4) {
      ll num;
      cin >> num;
      skills.push_back({j, num});
    }
    cout << (judge(skills) ? "YES" : "NO") << endl;
  }
}