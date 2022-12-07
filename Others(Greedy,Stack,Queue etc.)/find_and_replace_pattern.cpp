class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> res;

        for (auto x : words)
        {
            if (matches(x, pattern))
            {
                res.push_back(x);
            }
        }

        return res;
    }

    bool matches(string w, string pattern)
    {

        vector<char> p(26);
        vector<char> q(26);

        for (int i = 0; i < w.length(); i++)
        {
            char wo = w[i];
            char pat = pattern[i];

            if (p[pat - 'a'] == 0)
            {
                p[pat - 'a'] = wo;
            }
            if (q[wo - 'a'] == 0)
            {
                q[wo - 'a'] = pat;
            }

            if (q[wo - 'a'] != pat || p[pat - 'a'] != wo)
                return false;
        }

        return true;
    }
};