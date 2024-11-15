#include <iostream>
#include <vector>
using namespace std;

int knapsackMemo(vector<int>& weight, vector<int>& value, int W, int n, vector<vector<int>>& memo) {
    if (n == 0 || W == 0)
        return 0;

    if (memo[n][W] != -1)
        return memo[n][W];

    if (weight[n - 1] > W)
        return memo[n][W] = knapsackMemo(weight, value, W, n - 1, memo);

    return memo[n][W] = max(value[n - 1] + knapsackMemo(weight, value, W - weight[n - 1], n - 1, memo),
                            knapsackMemo(weight, value, W, n - 1, memo));
}

int main() {
    vector<int> weight = { 1, 2, 4, 5 };
    vector<int> value = { 5, 4, 8, 6 };
    int W = 5;

    int n = weight.size();
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1)); // initialize memo table with -1

    cout << "Maximum value = " << knapsackMemo(weight, value, W, n, memo) << endl;
    return 0;
}
