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
  stack<P> st; // num, occur
  int cnt = 0;
  for (auto ai : A) {
    if (st.empty()) {
      st.push(make_pair(ai, 1));
      cnt++;
      cout << cnt << endl;
      continue;
    }
    auto tp = st.top();
    if (tp.first == ai) {
      if (tp.second + 1 == tp.first) {
        cnt++;
        cnt -= tp.first;
        st.pop();
      } else {
        st.pop();
        st.push(make_pair(tp.first, tp.second + 1));
        cnt++;
      }
    } else {
      st.push(make_pair(ai, 1));
      cnt++;
    }
    cout << cnt << endl;
  }
}