#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

bool customCompare(pll a, pll b) {
    return a > b;
}

void taskScheduling() {
    int tasks;
    
    cin >> tasks;

    std::vector<int> deadlines(tasks), profits(tasks);

    for (int i = 0; i < tasks; ++i) {
        cin >> deadlines[i];
    }

    for (int i = 0; i < tasks; ++i) {
        cin >> profits[i];
    }

    vector<pii> taskInfo(tasks);

    for (int i = 0; i < tasks; ++i) {
        taskInfo[i] = {profits[i], deadlines[i]};
    }

    sort(taskInfo.begin(), taskInfo.end(), customCompare);

    vector<bool> taskCompleted(tasks, false);

    int taskCount = 0, totalProfit = 0;

    for (int i = 0; i < tasks; ++i) {
        for (int j = min(tasks, taskInfo[i].second) - 1; j >= 0; --j) {
            if (!taskCompleted[j]) {
                taskCompleted[j] = true;
                taskCount++;
                totalProfit += taskInfo[i].first;
                break;
            }
        }
    }

    cout << "Tasks Completed: " << taskCount << ", Total Profit: " << totalProfit;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input_Q2.txt", "r", stdin);
    freopen("output_Q2.txt", "w", stdout);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        taskScheduling();
        cout << endl;
    }

    return 0;
}
