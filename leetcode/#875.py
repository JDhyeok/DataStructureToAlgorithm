class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:


        def min_hour(k, piles):
            ret = 0

            for pile in piles:
                ret += (pile // k)
                ret += 1 if (pile % k) != 0 else 0

            return ret

        l, r = 1, max(piles)

        while l <= r:
            mid = (l + r) // 2

            target = min_hour(mid, piles)

            if h < target:
                l = mid + 1
            else:
                r = mid - 1
        return l