struct Node {
    bool word;
    string str;
    unordered_map<char, Node*> words;
};
class Trie {
public:
    Trie() {
        root = new Node();
    }
    virtual ~Trie() {
        clear(root);
    }
    void insert(string word) {
        Node* p = root;
        for (char c: word) {
            if (p->words.find(c) == p->words.end()) {
                Node* t = new Node();
                p->words[c] = t;
            } 
            p = p->words[c];
        }
        p->str = word; // node对应的word，为了之后根据node来找到结果
        p->word = true;
    }
    void search(vector<string>& res, vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                help(res, board, root, i, j);
            }
        }
    }
    void help(vector<string>&res, vector<vector<char>>& board, Node* p, int x, int y) {
        if (p->word) {
            p->word = false; // 其他方向就不会再把答案放进去了
            res.push_back(p->str);
            return;
        } 
        if (x < 0 || x == board.size() || y < 0 || y == board[x].size()) return;
        if (p->words.find(board[x][y]) == p->words.end()) return;
        p = p->words[board[x][y]]; // 此时的p是其他字符了
        char cur = board[x][y];
        board[x][y] = '#';
        help(res, board, p, x+1, y);
        help(res, board, p, x-1, y);
        help(res, board, p, x, y+1);
        help(res, board, p, x, y-1);
        board[x][y] = cur;
    }
    
private:
    Node* root;

private:
    void clear(Node* root) {
        for(auto iter = root->words.begin(); iter != root->words.end(); iter++) {
            if(iter->second != nullptr) clear(iter->second);
        }
        delete root;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        vector<string> res;
        for (string& w: words) {
            trie.insert(w);
        }
        trie.search(res, board);
        return res;
        
    }
};