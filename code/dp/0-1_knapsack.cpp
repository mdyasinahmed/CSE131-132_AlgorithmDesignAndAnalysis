#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= capacity; w++) {
            if(items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}


int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int knapsackCapacity = 50;

    int maxValue = knapsack(items, knapsackCapacity);

    cout << "Maximum value obtained = " << maxValue << endl;

    return 0;
}
