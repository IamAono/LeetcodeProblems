class Solution:
    def findMinMoves(self, machines: List[int]) -> int:
        n = len(machines)
        dresses = sum(machines)
        if dresses % n != 0:
            return -1
        avg = int(dresses / n)
        moves = 0
        maxMoves = 0
        for m in machines:
            moves += m - avg
            maxMoves = max(max(maxMoves, abs(moves)), m - avg)
        return maxMoves
            
