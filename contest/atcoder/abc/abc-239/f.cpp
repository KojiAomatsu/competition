#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> D(N);
  set<ll> rests;
  ll sum = 0;
  rep(i, 0, N) {
    cin >> D[i];
    if (D[i] > 1) {
      rests.insert(i);
    }
    sum += D[i];
  }
  if (sum != 2 * (N - 1)) {
    cout << -1 << endl;
    return 0;
  }
  atcoder::dsu d(N);
  rep(i, 0, M) {
    ll Ai, Bi;
    cin >> Ai >> Bi;
    Ai--;
    Bi--;

    if (d.same(Ai, Bi)) {
      cout << -1 << endl;
      return 0;
    }

    if (rests.count(Ai) || rests.count(Bi)) {
      D[Ai]--;
      D[Bi]--;
      if (D[Ai] == 0) {
        rests.erase(Ai);
      }
      if (D[Bi] == 0) {
        rests.erase(Bi);
      }
      if (D[Ai] && D[Bi] && rests.size()) {
        cout << -1 << endl;
        return 0;
      }
      d.merge(Ai, Bi);
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<P> combs;
  for (auto s : rests) {
    combs.push_back(make_pair(D[s], s));
  }

  // 1 とそれ以外のPriorityQueueに分ければよい
  sort(combs.begin(), combs.end());
  for (int i = 0; i < combs.size(); i++) {
    int j = combs.size() - 1;
    while (i < j) {
      if (d.same(combs[i].second, combs[j].second)) {
        j--;
        continue;
      } else {
        d.merge(combs[i].second, combs[j].second);
        cout << combs[i].second + 1 << " " << combs[j].second + 1 << endl;
        D[combs[i].second]--;
        D[combs[j].second]--;
        if (combs[i].second == 0) {
          break;
        }
        if (combs[j].second == 0) {
          combs.erase(combs.begin() + j);
        }
      }
    }
  }
}