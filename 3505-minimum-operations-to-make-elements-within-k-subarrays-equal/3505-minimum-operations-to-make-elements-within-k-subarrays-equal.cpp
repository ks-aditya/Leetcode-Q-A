class Solution {
public:
    using ll = long long;

    multiset<int> left, right;
    ll sumLeft = 0, sumRight = 0;
    int x;

    void balance() {
        int need = (x + 1) / 2;

        while (left.size() > need) {
            auto it = prev(left.end());
            int val = *it;
            left.erase(it);
            sumLeft -= val;
            right.insert(val);
            sumRight += val;
        }

        while (left.size() < need && !right.empty()) {
            auto it = right.begin();
            int val = *it;
            right.erase(it);
            sumRight -= val;
            left.insert(val);
            sumLeft += val;
        }
    }

    void add(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        } else {
            right.insert(val);
            sumRight += val;
        }
        balance();
    }

    void remove(int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    }

    ll getCost() {
        ll median = *left.rbegin();

        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->x = x;

        int n = nums.size();
        vector<ll> cost(n - x + 1);

        // Calculate the cost of every window of size x.
        for (int i = 0; i < n; i++) {
            if (i >= x)
                remove(nums[i - x]);

            add(nums[i]);

            if (i >= x - 1)
                cost[i - x + 1] = getCost();
        }

        // dp[j][i] = minimum cost to select j windows
        // from the first i elements.
        const ll INF = LLONG_MAX / 4;

        vector<vector<ll>> dp(
            k + 1, vector<ll>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                // Skip the current element.
                dp[j][i] = dp[j][i - 1];

                // Select a window ending at index i - 1.
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};