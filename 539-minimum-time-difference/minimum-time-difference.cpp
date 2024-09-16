class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;  // To store the times in minutes.
        
        // Convert each time point to minutes.
        for (const string& time : timePoints) {
            int hours = stoi(time.substr(0, 2));  // Extract the hours part.
            int mins = stoi(time.substr(3, 2));   // Extract the minutes part.
            minutes.push_back(hours * 60 + mins); // Convert to total minutes.
        }
        
        // Sort the times.
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;  // Initialize with a large value.
        
        // Compare consecutive time points for minimum difference.
        for (int i = 1; i < minutes.size(); ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Also compare the first and last time point across midnight.
        int circularDiff = 1440 - (minutes.back() - minutes[0]);  // 1440 is total minutes in a day.
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};