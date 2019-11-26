class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        count = [[0] * 26] * len(strs)
        
        for i in range(len(strs)):
            for j in range(len(strs[i])):
                index = ord(strs[i][j]) - ord('a')
                count[i][index] += 1
                print(i, j, count[i][index])
            print(count)

        ans = []
        used = [0] * len(strs)        
        for i in range(len(strs)):
            if used[i] == 1:
                continue
            sub = []
            for j in range(i, len(strs)):
                if count[i] == count[j] and used[j] == 0:
                    used[j] = 1
                    sub.append(strs[j])
            ans.append(sub)
            
        return ans