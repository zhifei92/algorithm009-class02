class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }
        for (int & v : hash) {
            if (0 != v)
                return false;
        }
        return true;
    }
};