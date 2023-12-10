#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> daily_scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> daily_scores[i];
    }

    // Sort the array of daily scores in ascending order
    sort(daily_scores.begin(), daily_scores.end());

    vector<int> final_scores(n);

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            final_scores[i] = i / 2 + 1;  // Assign the minimum possible positive score
        }
        else {
            final_scores[i] = n - i / 2;  // Assign the next higher score than previous
        }
    }

    // Output the array of final scores
    for (int i = 0; i < n; ++i) {
        cout << final_scores[i] << " ";
    }
    cout << endl;

    return 0;
}
