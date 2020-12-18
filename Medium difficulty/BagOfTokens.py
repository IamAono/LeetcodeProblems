class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        score = 0
        maxScore = 0
        tokens.sort()
        while len(tokens) > 0:
            l = len(tokens)
            while P >= tokens[0]:
                P -= tokens[0]
                score += 1
                maxScore = max(maxScore, score)
                tokens.remove(tokens[0])
                if len(tokens) == 0:
                    break
            if score >= 1 and len(tokens) > 0:
                P += tokens[-1]
                score -= 1
                tokens.remove(tokens[-1])
            if l == len(tokens):
                break
        return maxScore
        
