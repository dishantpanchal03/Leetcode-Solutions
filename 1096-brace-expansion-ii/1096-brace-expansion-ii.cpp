class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> res, cur;
        cur.insert("");

        while (i < s.size() && s[i] != '}') {
            set<string> part;

            if (s[i] == '{') {
                i++;
                part = solve(s, i);
                i++;
            }
            else if (s[i] == ',') {
                i++;
                auto right = solve(s, i);
                res.insert(cur.begin(), cur.end());
                res.insert(right.begin(), right.end());
                return res;
            }
            else {
                part.insert(string(1, s[i++]));
            }

            set<string> temp;
            for (auto a : cur)
                for (auto b : part)
                    temp.insert(a + b);

            cur = temp;
        }

        res.insert(cur.begin(), cur.end());
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};
