import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        pq = []
        for ele in nums:
            heapq.heappush(pq,ele)
            if len(pq) > k :
                heapq.heappop(pq)
        return pq[0]