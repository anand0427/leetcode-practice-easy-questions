class Solution:
    def reverse(self, x: int) -> int:
        num = 0
        val = x
        x = abs(x)
        while x>0:
            num=num+x%10
            num*=10
            x = x//10
        num = num//10
        if num > (2**31) or (-num)<(-2**31) :
            return 0
        return 0-num if val<0 else num