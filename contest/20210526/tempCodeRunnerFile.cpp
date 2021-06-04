  // rep(i, 0, N) {
  //   rep(j, 0, 200) {
  //     if (ans_dp[i][j].size() == 0)
  //       continue;
  //     ans_dp[i + 1][j].insert(ans_dp[i + 1][j].begin(), ans_dp[i +
  //     1][j].end(),
  //                             ans_dp[i][j].end());
  //     cout << "ok\n";
  //     vector<vector<ll>> tmp = ans_dp[i][j];
  //     for (auto arr : tmp) {
  //       arr.push_back(i + 1);
  //     }
  //     ans_dp[i + 1][j + li[i] % 200].insert(
  //         ans_dp[i + 1][j + li[i] % 200].begin(),
  //         ans_dp[i + 1][j + li[i] % 200].end(), tmp.end());
  //   }
  // }
  // if (ans_dp[N][0].size() >= 3) {
  //   cout << "Yes" << endl;
  //   return 0;
  // }
  // rep(i, 1, N) {
  //   if (ans_dp[N][i].size() >= 2) {
  //     cout << "Yes" << endl;
  //     return 0;
  //   }
  // }
  // cout << "No" << endl;