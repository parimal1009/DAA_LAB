#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int optimalMergePattern(vector<int>& fileSizes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(fileSizes.begin(), fileSizes.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int mergeCost = first + second;
        totalCost += mergeCost;
        minHeap.push(mergeCost);
    }

    return totalCost;
}

int main() {
    vector<int> fileSizes = {20, 30, 10, 5, 15};
    int result = optimalMergePattern(fileSizes);
    cout << "The minimum total merge cost is: " << result << endl;
    return 0;
}
