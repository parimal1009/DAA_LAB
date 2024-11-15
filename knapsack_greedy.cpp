#include <iostream>
#include <vector>
#include <algorithm>

double fractionalKnapsack(double capacity, std::vector<std::pair<double, double>> &items) {
    std::sort(items.begin(), items.end(), [](auto &a, auto &b) { return a.first / a.second > b.first / b.second; });
    double totalValue = 0;
    for (auto &item : items) {
        if (capacity >= item.second) {
            capacity -= item.second;
            totalValue += item.first;
        } else {
            totalValue += item.first * (capacity / item.second);
            break;
        }
    }
    return totalValue;
}

int main() {
    std::vector<std::pair<double, double>> items = { {60, 10}, {100, 20}, {120, 30} };
    double capacity = 50;
    std::cout << "Maximum value: " << fractionalKnapsack(capacity, items) << std::endl;
    return 0;
}
