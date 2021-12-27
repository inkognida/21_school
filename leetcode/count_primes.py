class Solution:
	def prime_check(self, n: int) ->int:
		if (n == 0 or n == 1):
			return (0)
		if (n == 2):
			return (1)
		for d in range(2, int(n - 1 / 2)):
			if (n % d == 0):
				return (0)
		return (1)

	def countPrimes(self, n: int) -> int:
		i = 0
		c = 0
		while (i < n):
			if (self.prime_check(i)):
				c += 1	
			i += 1
		return (c)
			

a = Solution()
print(a.countPrimes(10))