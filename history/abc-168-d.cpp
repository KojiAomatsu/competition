#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  map<ll, vector<ll>> path;
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    path[ai].push_back(bi);
    path[bi].push_back(ai);
  }
  vector<bool> fin(N + 1, false);
  vector<ll> res(N + 1);
  fin[0] = true;
  fin[1] = true;
  queue<pair<ll, ll>> qu; // first: edge_num, second: parent

  for (auto ele : path[1]) {
    qu.push({ele, 1});
  }

  while (!qu.empty()) {
    auto fir = qu.front();
    qu.pop();
    if (fin[fir.first]) {
      continue;
    }
    res[fir.first] = fir.second;
    fin[fir.first] = true;
    for (auto ele : path[fir.first]) {
      if (!fin[ele]) {
        qu.push({ele, fir.first});
      }
    }
  }

  for (auto ele : fin) {
    if (!ele) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (ll i = 2; i < res.size(); i++) {
    cout << res[i] << endl;
  }
}