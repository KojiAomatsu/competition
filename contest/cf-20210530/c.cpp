#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

vector<string> calc(ll num, vector<ll> vec) {
  vector<string> ans;
  vector<ll> nested_page = {};
  vector<ll> nested_next_page = {};
  rep(i, 0, num) {
    ll item = vec[i];
    if (item == 1) {
      nested_page.push_back(item);
      nested_next_page.push_back(item + 1);
      string ele = "";
      rep(j, 0, nested_page.size()) {
        if (j == 0) {
          ele = to_string(nested_page[j]);
        } else {
          ele += ".";
          ele += to_string(nested_page[j]);
        }
      }
      ans.push_back(ele);
    } else {
      ll last_idx = 0;
      rep(k, 0, nested_next_page.size()) {
        if (nested_next_page[k] == item) {
          last_idx = k;
        }
      }
      vector<ll> new_vec =
          vector(nested_page.begin(), nested_page.begin() + last_idx);
      nested_page = new_vec;
      vector<ll> new_next_vec =
          vector(nested_next_page.begin(), nested_next_page.begin() + last_idx);
      nested_next_page = new_next_vec;

      nested_page.push_back(item);
      nested_next_page.push_back(item + 1);
      string ele = "";
      rep(j, 0, nested_page.size()) {
        if (j == 0) {
          ele = to_string(nested_page[j]);
        } else {
          ele += ".";
          ele += to_string(nested_page[j]);
        }
      }
      ans.push_back(ele);
    }
  }
  return ans;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll cnt;
    cin >> cnt;
    vector<ll> li(cnt);
    rep(i, 0, cnt) { cin >> li[i]; }
    vector<string> ans;
    ans = calc(cnt, li);
    for (auto item : ans) {
      cout << item << "\n";
    }
  }
}