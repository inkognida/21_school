from typing import List
import numpy as np
from math import floor, ceil
class Solution:
    def median_bigger(self, grid: List[List[int]], x: int) -> int:
        mb = sorted(grid)[ceil((len(grid))/2)]
        grid_copy = grid.copy()
        cb = 0

        for el in grid:
            if (mb == el):
                continue
            elif (el > mb):
                tmp = el
                while (el != mb):
                    cb += 1
                    el -= x
                    if (el < min(grid_copy)):
                        return (-1)
                grid[grid.index(tmp)] = el
            elif (el < mb):
                tmp = el
                while (el != mb):
                    cb += 1
                    el += x
                    if el > max(grid_copy):
                        return (-1)
                grid[grid.index(tmp)] = el
        return (cb)

    def minOperations(self, grid: List[List[int]], x: int) -> int:
        grid = (list(np.array(grid).ravel()))
        if (len(grid) <= 1):
            return (0)
        grid_copy = grid.copy()
        cs = 0
        cb = self.median_bigger(grid.copy(), x)
        ms = sorted(grid)[ceil((len(grid))/2) - 1]

        for el in grid:
            if (ms == el):
                continue
            elif (el > ms):
                tmp = el
                while (el != ms):
                    cs += 1
                    el -= x
                    if (el < min(grid_copy)):
                        return (-1)
                grid[grid.index(tmp)] = el
            elif (el < ms):
                tmp = el
                while (el != ms):
                    cs += 1
                    el += x
                    if el > max(grid_copy):
                        return (-1)
                grid[grid.index(tmp)] = el
        return (cs if cs < cb else cb)
a = Solution()
print(a.minOperations([[1,5],[2,3]], 1))



