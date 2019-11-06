class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        n = len(nums)
        nums.sort()
        ans = []
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            L, R = i + 1, n - 1
            while L < R:
                _sum = nums[i] + nums[L] + nums[R]
                if _sum == 0:
                    ans.append([nums[i], nums[L], nums[R]])
                    L += 1
                    R -= 1
                    while L < R and nums[L] == nums[L - 1]:
                        L += 1
                    while L < R and nums[R] == nums[R + 1]:
                        R -= 1
                elif _sum < 0:
                    L += 1
                else:
                    R -= 1
        return ans
        
