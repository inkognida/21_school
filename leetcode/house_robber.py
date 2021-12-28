def rob(nums):
	d = 1
	m, i = max(nums), nums.index(max(nums))
	nums[i] = min(nums) - d
	for el in nums:
		l_m, l_i = max(nums), nums.index(max(nums))
		if (l_i + 1 != i and l_i - 1 != i):
			
			m, i = l_m, l_i
		else:
			d += 1
			nums[l_i] = min(nums) - 1
	return (0)
# print(rob([2,7,9,3,1]))
print(rob_odd_even([2,7,9,3,1]))