// leetcode 729. My Calendar I

// You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

// A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

// The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

// Implement the MyCalendar class:

// MyCalendar() Initializes the calendar object.
// boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

#include<bits/stdc++.h>
using namespace std;

    #include <set>
#include <utility>

class MyCalendar {
private:
    std::set<std::pair<int, int>> bookings; // Store the start and end of booked events

public:
    MyCalendar() = default;

    bool book(int start, int end) {
        // Find the first booking that overlaps with the new booking
        auto it = bookings.lower_bound({start, end});

        // Check if there's an overlap with the previous booking
        if (it != bookings.begin()) {
            auto prev = std::prev(it);
            if (prev->second > start) {
                return false; // Overlap detected
            }
        }

        // Check if there's an overlap with the next booking
        if (it != bookings.end() && it->first < end) {
            return false; // Overlap detected
        }

        // If no overlap, add the event to bookings
        bookings.insert({start, end});
        return true;
    }
};