#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> PN(N);
  vector<ll> n_to_idx(N);
  rep(i, 0, N) {
    ll pni;
    cin >> pni;
    pni--;
    PN[i] = pni;
    n_to_idx[PN[i]] = i;
  }
  ll M;
  cin >> M;
  vector<vector<vector<ll>>> Ed(N, vector<vector<ll>>(N)); // vector<ll> 手順のvector
  vector<pair<P, ll>> ab;
  map<ll, P> mp;
  rep(i, 0, M) {
    ll ai, bi;
    cin >> ai >> bi;
    ai--;
    bi--;
    ab.push_back({{ai, bi}, i + 1});
    mp[i + 1] = {ai, bi};
  }
  sort(ab.begin(), ab.end());
  rep(i, 0, M) {
    ll a = ab[i].first.first;
    ll b = ab[i].first.second;
    ll k = ab[i].second;
    if (Ed[a][b].size() == 0) {
      Ed[a][b].push_back(k);
    } else {
      rep(j, 0, a) {
        if (Ed[j][a].size() == 0) continue;
        if (Ed[j][b].size() == 0) continue;
        Ed[j][b] = Ed[j][a];
        Ed[j][j].push_back(k);
      }
    }
  }
  vector<ll> ans;
  rep(i, 0, N) {
    ll from = i;
    ll to = n_to_idx[i];
    if (to < from) swap(to, from);
    if (Ed[from][to].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
    ans.insert(ans.end(), Ed[from][to].begin(), Ed[from][to].end());
    for (auto e : Ed[from][to]) {
      ll f = mp[e].first;
      ll s = mp[e].second;
      swap(n_to_idx[f], n_to_idx[s]);
    }
  }
  cout << ans.size() << endl;
  for (auto item : ans) {
    cout << item << " ";
  }
  cout << endl;
}
