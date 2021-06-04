#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll ans = N;

  vector<ll> pluss;
  vector<ll> minuss;
  vector<ll> sums;
  vector<ll> allsums;

  ll sum = 0;
  ll allsum = 0;
  priority_queue<ll> minus_que;

  for (ll i = 0; i < N; i++) {
    ll inp;
    cin >> inp;
    if (inp >= 0) {
      sum += inp;
    } else {
      pluss.push_back(sum);
      minuss.push_back(inp);
      sums.push_back(sum + inp);
      allsum += sum + inp;
      allsums.push_back(allsum);
      sum = 0;
    }
  }

  ll plus_potion = 0;
  rep(i, 0, allsums.size()) {
    minus_que.push(-minuss[i]);
    ll current_sum = allsums[i];
    if (current_sum + plus_potion < 0) {
      if (minus_que.size() == 0) {
        continue;
      }
      auto throwq = minus_que.top();
      plus_potion += throwq;
      minus_que.pop();
      ans -= 1;
    }
  }

  cout << ans << endl;
}