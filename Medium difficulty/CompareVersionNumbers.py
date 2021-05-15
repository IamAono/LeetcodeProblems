class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        def solve(v1, v2, b):
            for i in range(0, len(v2)):
                current1 = int(v1[i])
                current2 = int(v2[i])
                if current1 > current2:
                    if b:
                        return 1
                    else:
                        return -1
                elif current2 > current1:
                    if b:
                        return -1
                    else:
                        return 1
            for i in range(len(v2), len(v1)):
                current = int(v1[i])
                if current != 0:
                    if b:
                        return 1
                    else:
                        return -1
            return 0
        v1 = version1.split('.')
        v2 = version2.split('.')
        if len(v1) > len(v2) or len(v1) == len(v2):
            return solve(v1, v2, True)
        else:
            return solve(v2, v1, False)
