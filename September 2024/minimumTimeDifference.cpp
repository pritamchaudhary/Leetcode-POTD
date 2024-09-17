#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int get_minutes(string time_point) {
        return ((((time_point[0] - '0') * 10) + (time_point[1] - '0')) * 60) + (((time_point[3] - '0') * 10) + (time_point[4] - '0'));
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        for (auto m : timePoints) {
            minutes.push_back(get_minutes(m));
        }
    
        sort(minutes.begin(), minutes.end());
    
        int min_diff = INT_MAX;
    
        for (int i = 1; i < minutes.size(); i++) {
            min_diff = min(min_diff, minutes[i] - minutes[i - 1]);
        }

        return min(min_diff, abs(minutes[0] + 1440 - minutes[minutes.size() - 1]));
    }
};
