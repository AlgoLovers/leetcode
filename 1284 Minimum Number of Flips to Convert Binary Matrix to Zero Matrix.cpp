class Solution {
public:
    int getStatus(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int ret = 0;
        for(int y = 0; y < n; ++y) {
            for(int x = 0; x < m; ++x) {
                ret = (ret << 1);
                ret += mat[y][x];
            }
        }
        return ret;
    }
    vector<vector<int>> getFlip(vector<vector<int>>& mat, int y, int x) {
        vector<vector<int>> ret(mat);
        const int dy[] = {-1, 0, +1, 0};
        const int dx[] = {0, +1, 0, -1};
        int n = mat.size();
        int m = mat[0].size();
        for(int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            ret[ny][nx] = !ret[ny][nx];
        }
        ret[y][x] = !ret[y][x];
        
        return ret;
    }
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<vector<vector<int>>> q;
        queue<int> qc;
        vector<bool> visited((1 << (n * m)), false);
        
        int status = getStatus(mat);
        visited[status] = true;
        q.push(mat);
        qc.push(0);
        
        bool find = false;
        int count = 0;
        while(!q.empty()) {
            vector<vector<int>> cur = q.front();
            count = qc.front();
            q.pop();
            qc.pop();
            int status = getStatus(cur);
            if(status == 0) {
                find = true;
                break;
            }
            for(int y = 0; y < n; ++y) {
                for(int x = 0; x < m; ++x) {
                    vector<vector<int>> next = getFlip(cur, y, x);
                    int status = getStatus(next);
                    if(visited[status] == false) {
                        visited[status] = true;
                        q.push(next);
                        qc.push(count + 1);
                    }
                }
            }
        }
        return (find == true) ? (count) : (-1);
    }
};