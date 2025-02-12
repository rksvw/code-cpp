#include <iostream>
#include <vector>
#include <string>
using namespace std;

// void printPermute(string str, int idx, vector<vector<string>>& ans) {
//     if (idx == str.length()) {
//         ans.push_back({str});
//         return;
//     }

//     for (int i = idx; i < str.length(); i++) {
//         swap(str[idx], str[i]);
//         printPermute(str, idx+1, ans);

//         // BackTracking
//         swap(str[idx], str[i]);
//     }
// }

// int main() {
//     string str = "abc";
//     vector<vector<string>> ans;
//     printPermute(str, 0, ans);

//     for (int i = 0; i < ans.size(); i++) {
//         for(int j = 0; j < ans[0].size(); j++) {
//             cout << ans[i][j] << endl;
//         }
//     }
//     return 0;
// }

void create(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited)
{
    if (arr.size() == temp.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            temp.push_back(arr[i]);
            create(arr, ans, temp, visited);
            temp.pop_back();
            visited[i] = 0;
        }
    }
}

void create(vector<int> &arr, vector<vector<int>> &ans, int idx)
{
    if (idx == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[i], arr[idx]);
        create(arr, ans, idx + 1);
        swap(arr[i], arr[idx]);
    }
}
vector<vector<int>> permute(vector<int> &arr)
{
    vector<vector<int>> ans;
    int idx = 0;
    /* vector<int>temp;
     vector<bool>visited(arr.size(),0);
     create(arr,ans,temp,visited);*/
    create(arr, ans, idx);
    return ans;
}

int main()
{
    vector<int> ans = {1, 2, 3};
    vector<vector<int>> nums;
    nums = permute(ans);

    for (auto num : nums)
    {
        for (auto n : num)
        {
            cout << n;
        }
        cout << endl;
    }

    return 0;
}