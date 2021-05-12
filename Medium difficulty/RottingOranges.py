class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        minutes = 0
        fresh = []
        rotten = []
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    fresh.append((i, j))
                elif grid[i][j] == 2:
                    rotten.append((i, j))
        if len(fresh) == 0:
            return minutes
        index = 0
        while True:
            f = len(fresh)
            minutes += 1
            r_len = len(rotten)
            while index < r_len:
                r = rotten[index]
                if (r[0] + 1, r[1]) in fresh:
                    fresh.remove((r[0] + 1, r[1]))
                    rotten.append((r[0] + 1, r[1]))
                if (r[0] - 1, r[1]) in fresh:
                    fresh.remove((r[0] - 1, r[1]))
                    rotten.append((r[0] - 1, r[1]))
                if (r[0], r[1] + 1) in fresh:
                    fresh.remove((r[0], r[1] + 1))
                    rotten.append((r[0], r[1] + 1))
                if (r[0], r[1] - 1) in fresh:
                    fresh.remove((r[0], r[1] - 1))
                    rotten.append((r[0], r[1] - 1))
                index += 1
            if len(fresh) == f or len(fresh) == 0:
                break
        if len(fresh) > 0:
            return -1
        return minutes
                
