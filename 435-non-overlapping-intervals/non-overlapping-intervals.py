class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        prev = intervals[0][1]
        cnt = 1
        n= len(intervals)
        for i in range(1,n):
            if intervals[i][0] < prev :
                prev = min(prev, intervals[i][1])
            else:
                prev = intervals[i][1]
                cnt+=1
        return n-cnt
