#include <vector>
#include <unordered_map>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;
/*
一个有序数组，且数组中的每个数字唯一，但是数组中有缺失的数字，找出从数组最左边开始的第K个缺失数字。
示例1：
输入：A = [1,2,3,4], K=1
输出：5
示例2：
输入：A=[4,7,9,10], K=3
输出：8
*/
int SearchNumber(std::vector<int> &array, int index)
{
    int start = array[0];
    std::vector<int> result;

    for (size_t i = 1; i < array.size(); i++)
    {
        for (int n = start + 1; n < array[i]; n++)
        {
            result.push_back(n);
        }
        start = array[i];
    }
    
    if (index <= result.size())
    {
        return result[index - 1];
    }
    else
    {
        return start + (index - result.size());
    }
}

/*
设计一个排名系统
示例：
votes = ["ABC", "ACB", "ABC", "ACB", "ACB"]
输出："ACB"
*/
using voteInfo = pair<char, vector<int>>;
bool CompareVote(const voteInfo &lf, const voteInfo &rf)
{
    for (size_t i = 0; i < lf.second.size(); i++)
    {
        if (lf.second[i] > rf.second[i])
        {
            return true;
        }
        else if (lf.second[i] < rf.second[i])
        {
            return false;
        }
    }
    
    return false;
}

string GetVoteRank(const vector<string> &votes)
{
    size_t sz = votes.size();
    if (sz == 0)
    {
        return "";
    }
    if (sz == 1)
    {
        return votes[0];
    }

    size_t len = votes[0].length();
    unordered_map<char, vector<int>> voteMap;
    for (auto &&str : votes)
    {
        for (size_t i = 0; i < len; i++)
        {
            char k = str[i];
            if (voteMap.find(k) == voteMap.end())
            {
                voteMap[k] = vector<int> (len, 0);
            }
            voteMap[k][i] += 1;
        }
    }
    
    vector<voteInfo> scores(voteMap.begin(), voteMap.end());
    sort(scores.begin(), scores.end(), CompareVote);
    string ret;
    for (auto &&p : scores)
    {
        ret += p.first;
    }
    
    return ret;
}

int main()
{
    //
    vector<string> votes{"ABC", "ACB", "ABC", "ACB", "ACB"};
    cout << "vote rank " << GetVoteRank(votes).c_str() << endl;

    //vector<int> array{1, 2, 4};
    //cout << "ret num " << SearchNumber(array, 3) << endl;

    std::cout << "main enter" << std::endl;
    while(true);
    return 0;
}















