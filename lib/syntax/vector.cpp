#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// syntax sub vector

vector<ll> sub_vector(vector<ll> vec, ll start_idx, ll end_idx) {
  // start..<endの場合は以下 end側は含まないことに注意
  // どっちもbeginで指定するのを注意
  // 0 index に注意
  return vector(vec.begin() + start_idx, vec.begin() + end_idx);
}

int main() {
  ll N;
  cin >> N;
  vector<ll> vec(N);
  rep(i, 0, N) { cin >> vec[i]; }
  for (auto item : sub_vector(vec, 2, 4)) {
    cout << item << ", ";
  }
  cout << endl;

  // syntax lower_bound
  // 指定した値以上が現れる最初の位置
  auto lb = lower_bound(vec.begin(), vec.end(), 4);
  cout << "lower_bound:" << lb - vec.begin() << endl;

  // syntax lower_bound
  // 指定した値より大きい値が現れる最初の位置
  auto lb2 = upper_bound(vec.begin(), vec.end(), 4);
  cout << "upper_bound:" << lb2 - vec.begin() << endl;
}