class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num1 = num1[::-1]
        num2 = num2[::-1]
        
        val = [0] * (len(num1) + len(num2) + 1)
        for i in range(len(num1)):
            for j in range(len(num2)):
                val[i + j] = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
                
        ans = ""
        
        for i in range(len(val)):
            cur = val[i] % 10
            carry = val[i] / 10
            val[i + 1] += carry
            ans += chr(cur + ord('0'))
            
        ans = ans[::-1]
        if ans[0] == '0':
            ans = ans[1:len(ans)]
            
        return ans
            