#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;

int solve(int n, const vii& ss) {
	auto dp = vii(2, vi(n, 0));
	dp[0][0] = ss[0][0];
	dp[1][0] = ss[1][0];

	for (auto i = 1; i < n; ++i) {
		auto c0 = dp[1][i - 1];
		if (2 <= i) {
			if (c0 < dp[1][i - 2]) {
				c0 = dp[1][i - 2];
			}
		}
		dp[0][i] = c0 + ss[0][i];

		auto c1 = dp[0][i - 1];
		if (2 <= i) {
			if (c1 < dp[0][i - 2]) {
				c1 = dp[0][i - 2];
			}
		}
		dp[1][i] = c1 + ss[1][i];
	}

	const auto& ret0 = dp[0][n - 1];
	const auto& ret1 = dp[1][n - 1];

	return (ret0 < ret1 ? ret1 : ret0);
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		int n;
		cin >> n;

		auto ss = vii(2, vi(n));
		for (auto i = 0; i < n; ++i) {
			cin >> ss[0][i];
		}
		for (auto i = 0; i < n; ++i) {
			cin >> ss[1][i];
		}

		const auto& ans = solve(n, ss);
		cout << ans << '\n';
	}

	return 0;
}