class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        queue<pair<string,int>> q;
        q.push(pair<string,int>{beginWord,0});
        set<string> vis;
        while (!q.empty()){
            string node = q.front().first;
            int d = q.front().second;
            q.pop();
            if (node==endWord) return d+1;
            vis.insert(node);
            for (auto u:wordList){
                int numd=0;
                for (int j=0; j<u.size(); j++){
                    numd+=(u[j]!=node[j]);
                }
                if (numd==1 && vis.find(u)==vis.end()){
                    q.push(pair<string,int>{u,d+1});
                }
            }
        }
        return 0;

    }
};
