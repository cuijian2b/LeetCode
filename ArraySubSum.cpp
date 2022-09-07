#include <vector>
#include <iostream>
#include <algorithm>

/*
假设有一个整数组array和一个整数num，设计一个算分判断这个数组分成num个分空子集，其总和相等。
*/
bool dfs(std::vector<int> &array, int cur, 
         std::vector<int> &sums, int k)
{
    if (cur < 0)
    {
        return true;
    }

    for (int i = 0; i < k; i++)
    {
        if (sums[i] == array[cur] || 
            sums[i] - array[cur] >= array[0])
        {
            sums[i] -= array[cur];
            if (dfs(array, cur - 1, sums, k))
            {
                return true;
            }

            sums[i] += array[cur];
        }
    }
    
    return false;
}

bool IsPartitionArray(std::vector<int> &array, int k)
{
    int sum = 0;
    std::vector<int> temps;
    for (auto v : array)
    {
        temps.push_back(v);
        sum += v;
    }
    if (sum % k != 0)
    {
        return false;
    }

    std::vector<int> sums(k, sum / k);
    std::sort(temps.begin(), temps.end());

    return dfs(temps, temps.size() - 1, sums, k);
}

int main()
{
    std::vector<int> array{4, 3, 2, 3, 5, 2, 1};
    std::cout << "ret value " << (IsPartitionArray(array, 4) ? "true" : "false") << std::endl;

    std::cout << "main enter" << std::endl;
    while(true);
    return 0;
}