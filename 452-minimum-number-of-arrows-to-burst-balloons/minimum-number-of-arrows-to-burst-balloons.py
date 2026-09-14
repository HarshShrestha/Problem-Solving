class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        prev = points[0][1]
        cnt = 1
        n= len(points)
        for i in range(1,n):
            if points[i][0] <= prev :
                prev = min(prev, points[i][1])
            else:
                prev = points[i][1]
                cnt+=1
        return cnt