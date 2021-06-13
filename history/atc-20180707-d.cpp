#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
ll inf = 10000000000000001;

int main() {
  ll n, m, s, t;
  cin >> n >> m >> s >> t;
  map<ll, vector<pair<ll, ll>>> moneys;  // from, to, ai
  map<ll, vector<pair<ll, ll>>> snookes; // from ,to, bi
  rep(i, 0, m) {
    ll ui, vi, ai, bi;
    cin >> ui >> vi >> ai >> bi;
    moneys[ui].push_back({vi, ai});
    moneys[vi].push_back({ui, ai});
    snookes[ui].push_back({vi, bi});
    snookes[vi].push_back({ui, bi});
  }

  // example dijkstra ダイクストラ
  vector<ll> mins(n + 1, inf);
  mins[s] = 0;
  auto c = [](pair<ll, ll> l, pair<ll, ll> r) { return r.second < l.second; };
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(c)> que(c);
  que.push({s, 0});
  while (!que.empty()) {
    auto top = que.top();
    que.pop();

    if (top.second > mins[top.first]) {
      continue;
    }
    for (auto ele : moneys[top.first]) {
      if (top.second + ele.second < mins[ele.first]) {
        mins[ele.first] = top.second + ele.second;
        que.push({ele.first, top.second + ele.second});
      }
    }
  }

  // snooke
  vector<ll> smins(n + 1, inf);
  smins[t] = 0;
  auto c2 = [&](pair<ll, ll> l, pair<ll, ll> r) { return r.second < l.second; };
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(c2)> que2(c2);
  que2.push({t, 0});
  while (!que2.empty()) {
    auto top = que2.top();
    que2.pop();
    if (top.second > smins[top.first]) {
      continue;
    }
    for (auto ele : snookes[top.first]) {
      if (top.second + ele.second < smins[ele.first]) {
        smins[ele.first] = top.second + ele.second;
        que2.push({ele.first, top.second + ele.second});
      }
    }
  }

  vector<ll> min_via_i = mins;
  rep(i, 1, n + 1) { min_via_i[i] += smins[i]; }

  vector<ll> ans(n);
  ll an = inf;
  rep(i, 0, n) {
    an = min(an, min_via_i[n - i]);
    ans[n - 1 - i] = an;
  }
  for (auto item : ans) {
    cout << 1E15 - item << endl;
  }
}