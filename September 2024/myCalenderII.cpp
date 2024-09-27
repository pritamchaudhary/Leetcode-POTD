// leetcode 731. My Calendar II

// You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

// A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

// The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

// Implement the MyCalendarTwo class:

// MyCalendarTwo() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
 
#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> calendar;    
    vector<pair<int, int>> overlaps;   

    MyCalendarTwo() { }

    bool book(int start, int end) {
        for (const auto& o : overlaps) {
            if (max(o.first, start) < min(o.second, end)) {
                return false;  
            }
        }

        for (const auto& c : calendar) {
            if (max(c.first, start) < min(c.second, end)) {
                overlaps.push_back({max(c.first, start), min(c.second, end)});
            }
        }

        calendar.push_back({start, end});
        return true;
    }
};

