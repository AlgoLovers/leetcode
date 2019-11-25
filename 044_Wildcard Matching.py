class Solution:
    def match(self, si: int, pi: int) -> bool:
        if cache[si][pi] != -1:
            return cache[si][pi]

        if si < len(s) and pi < len(p) and (s[si] == p[pi] or p[pi] == '?'):
            cache[si][pi] = match(si + 1, pi + 1)
            return cache[si][pi]

        if pi == len(p):
            if si == len(s):
                cache[si][pi] = True
            else:
                cache[si][pi] = False
            return cache[si][pi]

        if p[pi] == '*':
            if match(si, pi + 1) or (si < len(s) and match(si + 1, pi)):
                cache[si][pi] = True
                return True

        cache[si][pi] = False
        return False
        
    def isMatch(self, s: str, p: str) -> bool:
        s_len, p_len = len(s), len(p)
        cache = [[-1 for _ in range(len(s) + 1)] for _ in range(len(p) + 1)]
    return self.match(0, 0)