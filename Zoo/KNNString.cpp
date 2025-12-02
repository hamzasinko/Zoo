#include "KNNString.h"

KNNString::KNNString() : KNN<string>() {}

KNNString::KNNString(int k) : KNN<string>(k) {}

double KNNString::similarityMeasure(const string& a, const string& b) const {
    const size_t n = a.size();
    const size_t m = b.size();

    if (n == 0) return m == 0 ? 1.0 : 0.0;
    if (m == 0) return 0.0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;

            dp[i][j] = min({
                dp[i - 1][j] + 1,        
                dp[i][j - 1] + 1,        
                dp[i - 1][j - 1] + cost  
                });
        }
    }

    int dist = dp[n][m];
    int maxLen = (int)max(n, m);

    return 1.0 - (double(dist) / double(maxLen));
}