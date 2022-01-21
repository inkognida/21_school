class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        z = '0'
        o = '1'
        c_z = 0
        c_o = 0
        while (z in s):
            z += '0'
            c_z += 1
        while (o in s):
            o += '1'
            c_o += 1
        return (True if c_o > c_z else False)


a = Solution()
print(a.checkZeroOnes("110100010"))