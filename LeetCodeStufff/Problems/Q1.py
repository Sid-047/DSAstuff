class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        global b 
        l = nums
        while l!=[]:
            a = l.pop()
            for i in range(len(l)):
                if a+l[i]==target:
                    x = len(l)
                    b = l.index(l[i])
                    break
        return [x, b]