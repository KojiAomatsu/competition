#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(K);
  rep(i, 0, K) { cin >> A[i]; }
  queue<ll> que;
  vector<ll> ans;
  vector<ll> tmp;
  ll cur = 0;
  ll upto = 0;
  rep(i, 0, K) {
    upto = A[i];
    if (i == K - 1) {
      upto = N;
    }
    ans.push_back(upto);
    rep(j, 1, upto - cur) {
      ll num = cur + j;
      bool is_over = i + j - 1 >= K;
      ll idx = is_over ? K - 1 : i + j - 1;
      que.push(num);
    }
    if (i == K - 1) {
      stack<ll> sta;
      while (!que.empty()) {
        ll top = que.front();
        que.pop();
        sta.push(top);
      }
      while (!sta.empty()) {
        ll top = sta.top();
        sta.pop();
        ans.push_back(top);
      }
    } else {
      if (!que.empty()) {
        ll top = que.front();
        que.pop();
        ans.push_back(top);
      }
    }
    cur = upto;
  }
  for (auto item : ans) {
    cout << item << " ";
  }
  cout << endl;
}
