class Solution(object):
    def countValidPrefixes(self, s):
        """
        :type s: str
        :rtype: int
        """
        z_cnt = 0
        o_cnt = 0
        ans = 0
        for ch in s:
            z_cnt += (1 if ch=='0' else 0)
            o_cnt +=  (1 if ch=='1' else 0)
            ans += (1 if abs(z_cnt- o_cnt) in [0,1] else 0)

        return ans