#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A structure to represent an item with weight and value
struct Item {
    int value;
    int weight;
};

// Comparator function to sort items based on value/weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // Sort in decreasing order of value/weight ratio
}

// Function to return the maximum total value in the knapsack
double fractionalKnapsack(int W, vector<Item>& items, int n) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    int curWeight = 0; // Current weight in the knapsack
    double finalValue = 0.0; // Final maximum value

    // Loop through all items
    for (int i = 0; i < n; i++) {
        // If adding the current item doesn't exceed capacity, add it entirely
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        } 
        // Otherwise, add the fractional part of the item
        else {
            int remain = W - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break; // We can't add more items after adding a fraction
        }
    }

    return finalValue;
}

int main() {
    int n, W;
    
    // Input number of items
    cout << "Enter the number of items: ";
    cin >> n;
    
    // Input the capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    
    vector<Item> items(n);

    // Input value and weight of each item
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    // Function call to perform the Fractional Knapsack algorithm
    double maxValue = fractionalKnapsack(W, items, n);
    
    // Output the maximum value we can get
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}
