#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int main() {
    // Initialize the vector of petrolPump structures
    vector<petrolPump> p = {
        {4, 6}, 
        {6, 5}, 
        {7, 3}, 
        {4, 5}
    };

    int n = p.size();
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0) {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0) {
        cout << "Start at petrol pump: " << start << endl;
        return start;
    } else {
        cout << "Not possible to complete the tour." << endl;
        return -1;
    }
}
