class Solution:
	def countPrimes(self, n: int) -> int:
		if (n == 0 or n == 1 or n == 2):
			return (0)
		prime = [True for i in range(n + 1)]
		p = 2
		while (p * p <= n):
			if (prime[p] == True):
				for i in range(p ** 2, n + 1, p):
					prime[i] = False
			p += 1
		c = 0
		prime[0] = False
		prime[1] = False
		for p in range(n):
			if (prime[p]):
				c += 1
		return (c)
			

a = Solution()
print("Primes in range 10:", a.countPrimes(10))
