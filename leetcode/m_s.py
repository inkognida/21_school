import itertools
class Solution:
    def minSwaps(self, s: str) -> int:
        ls = list(s)
        c = 0
        if ls[0] == '1' and (abs(s.count('1') - s.count('0')) <= 1):
            correct = "10" * int(len(s) / 2)
            print(ls)
            for i in range(len(ls)):
                if (ls[i] == '1' and i % 2 != 0):
                    for n in range(i, len(ls)):
                        # print(n, ls[n], ls[i], i)
                        if (n % 2 == 0 and ls[n] == '0'):
                            # print(ls[i], ls[n], i, n, ls)
                            ls[i], ls[n] = ls[n], ls[i]
                            # print(ls[i], ls[n], i, n, ls)
                            c += 1

        elif ls[0] == '0' and (abs(s.count('0') - s.count('1')) <= 1):
            for i in range(len(ls)):
                if (i % 2 != 0 and ls[i] == '0'):
                    for n in range(i, len(ls)):
                        if (n % 2 == 0 and ls[n] == '1'):
                            ls[i], ls[n] = ls[n], ls[i]
                            print(ls)
                            c += 1
        else:
            c = -1

        print(c)
        return (c)


# IDK how to solve it
a = Solution()
b = a.minSwaps("0010111")