// DAA Assn 03
// Write a program to solve a 0-1 Knapsack problem using dynamic programming or branch and bound strategy.


#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> weights, vector<int> values, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            w -= weights[i - 1];
        }
    }

    return dp[n][capacity];
}

int main() {
    int v,w;
    int capacity;
    cout<<"Enter no of values: ";
    cin>>v;
    vector<int> values(v);
    cout<<"Enter values: ";
    for(int i=0; i<v; i++) cin>>values[i];
    cout<<"Enter no of weights: ";
    cin>>w;
    vector<int> weights(w);
    cout<<"Enter weights: ";
    for(int i=0; i<w; i++) cin>>weights[i];
    cout<<"Enter capacity of each: ";
    cin>>capacity;

    // vector<int> values = {60, 100, 120};
    // vector<int> weights = {10, 20, 30};
    // int capacity = 50;

    int max_value = knapsack(weights, values, capacity);
    cout << "Maximum value: " << max_value << endl;
    return 0;
}





/*
Enter no of values: 3
Enter values: 60 100 120
Enter no of weights: 3
Enter weights: 10 20 30
Enter capacity of each: 50
Maximum value: 220
*/
