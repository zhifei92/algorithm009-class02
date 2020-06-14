class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> mp;
        set<string> visited;
        bool isVaild = false;
        for(auto& word : wordList) {
            if(word == endWord) isVaild = true;
            auto comboWord = word;
            auto tmp = ' ';
            for(auto &c : comboWord) {
                tmp = c;
                c = '*';
                mp[comboWord].push_back(word);
                c = tmp;
            }
        }
        if(!isVaild) return 0;
        queue<string> que;
        que.push(beginWord);
        int step = 1;
        while(!que.empty()) {
            step++;
            auto levelSize = que.size();
            while(levelSize--) {
                string curWord = que.front();
                que.pop();
                auto tmp = ' ';
                for(auto& c : curWord) {
                    tmp = c;
                    c = '*';
                    auto& curComboWordList = mp[curWord];
                    for(auto& word : curComboWordList) {
                        if(word == endWord) return step;
                        if(visited.count(word) == 0) {
                            visited.insert(word);
                            que.push(word);
                        }
                    }
                    c = tmp;
                }
            }
        }
        return 0;
    }
};