#include <iostream>
#include <string>
#include <stack>
#include <array>
using namespace std;
/*
按word为单位反正字符串
*/
string ReverseWords(string &s)
{
    stack<string> words;
    string word;
    for (auto ch : s)
    {
        if (ch != ' ')
        {
            word += ch;
        }
        else
        {
            if (word.length() > 0)
            {
                words.push(word);
                word = "";
            }
        }
    }
    if (word.length() > 0)
    {
        words.push(word);
    }    

    string ret;
    size_t sz = words.size();
    for (size_t i = 0; i < sz; i++)
    {
        ret += words.top();
        if (i < sz - 1)
        {
            ret += " ";
        }
        words.pop();
    }

    return ret;
}

/*
使用HH:MM格式标示某一个时刻，比如12:08，利用出现过的数字(1,2,0,8)构造下一个距离最近的时刻12:10
*/
string GetNextTime(const string& timeStr)
{
    string ret{"0000"};
    array<int, 4> ms{600, 60, 10, 1};
    int cur = ms[0] * (timeStr[0] - '0') + 
              ms[1] * (timeStr[1] - '0') +
              ms[2] * (timeStr[3] - '0') +              ms[3] * (timeStr[4] - '0');
    int maxMs = 60 * 24; // 最大时间
    int next = cur; // 下个时间
    for (int i = 1; i <= maxMs; i++)
    {
        next = cur + i;
        // 判断是否存在
        for (int j=0; j<ms.size(); j++)
        {
            char ch = '0' + (next / ms[j]);
            if (timeStr.find(ch) == string::npos)
            {
                break;
            }
            else
            {
                ret[j] = ch;
                if (j == ms.size() - 1)
                {
                    return ret.substr(0, 2) + ':' + ret.substr(2);
                }
                next %= ms[j];
            }
        }
    }
    
    return ret;
}


int main()
{
    //string msg{"   a formal test"};
    //cout << ReverseWords(msg) << endl;

    string msg{"12:08"};
    cout << GetNextTime(msg) << endl;

    cout << "main enter" << endl;
    while(true);
    return 0;
}















