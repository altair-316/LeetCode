#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {

        //vector<vector<string>> mapping(9);
        vector<string> mapping, ans;
        string c;
        mapping.push_back("");
        mapping.push_back("");
        mapping.push_back("abc");
        mapping.push_back("def");
        mapping.push_back("ghi");
        mapping.push_back("jkl");
        mapping.push_back("mno");
        mapping.push_back("pqrs");
        mapping.push_back("tuv");
        mapping.push_back("wxyz");

        ans_f(digits, mapping, ans, c);

        return (ans);
    }

public:
    void ans_f(string digits, vector<string> &mapping, vector<string> &ans, string c)
    {
        if (digits.size() == 0)
        {
            ans.push_back(c);
            return;
        }

        int x = digits[0] - 48;
        for (int i = 0; i < mapping[x].size(); i++)
        {
            c = c + mapping[x][i];
            ans_f(digits.substr(1), mapping, ans, c);
            c.pop_back();
        }
    }
};

int main()
{
    Solution phone;
    vector<string> ans1 = phone.letterCombinations("23");

    cout << "Input = 23\n [ ";
    string ans2[ans1.size()];

    for (auto i : ans1)
    {
        cout<<i<<" ";
    }
    cout<<"]"<<endl;

    return (0);
}