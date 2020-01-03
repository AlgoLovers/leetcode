class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        unordered_set<string> not_used(deadends.begin(), deadends.end());
        
        if(not_used.count(target) != 0 || not_used.count("0000")) {
            return -1;
        }
        
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
                
        int count = 0;
        while(!q.empty()) {
            ++count;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto cur = q.front();   q.pop();
                for(int i = 0; i < 4; ++i) {
                    for(int d = -1; d <= 1; d += 2) {
                        string next = cur;
                        next[i] = (next[i] + d);
                        if(next[i] > '9') {
                            next[i] = '0';
                        }
                        if(next[i] < '0') {
                            next[i] = '9';
                        }
                        
                        if(next == target) {
                            return count;
                        }
                        
                        if(not_used.count(next) == 0 && visited.count(next) == 0) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }    
                }
                
            }
        }
        return -1;
    }
};