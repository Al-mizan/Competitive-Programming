#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Comparison function to sort activities based on their finish times
bool activityCompare(Activity a1, Activity a2) {
    return (a1.finish < a2.finish);
}

// Function to perform activity selection
void activitySelection(vector<Activity> &activities) {
    // Sort activities based on finish time
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected Activities (start, finish): \n";

    // The first activity is always selected
    int lastSelected = 0;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    // Iterate through the sorted activities
    for (int i = 1; i < activities.size(); i++) {
        // If this activity's start time is greater than or equal to the finish time of the last selected activity
        if (activities[i].start >= activities[lastSelected].finish) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastSelected = i;  // Update the last selected activity
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);

    // Input the start and finish times
    for (int i = 0; i < n; i++) {
        cout << "Enter start and finish time for activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].finish;
    }

    // Perform activity selection
    activitySelection(activities);

    return 0;
}
