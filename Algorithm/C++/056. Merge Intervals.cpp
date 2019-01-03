/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class compare {
public:
    bool operator()(Interval &a, Interval &b) {
        return a.start < b.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) return intervals;
        
        sort(intervals.begin(), intervals.end(), compare());
        
        vector<Interval> result;
        result.push_back(intervals[0]);
        int c = 0;
        for (unsigned int i = 1; i < intervals.size(); i++) {
            if (result[c].end >= intervals[i].start) {
                result[c].end = max(result[c].end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
                c++;
            }
        }
        
        return result;
    }
};