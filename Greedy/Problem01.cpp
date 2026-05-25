// Leetcode 1005. Maximize Sum Of Array After K Negations
// Given an integer array nums and an integer k, modify the array in the following way:
// - choose an index i and replace nums[i] with -nums[i].
// You should apply this process exactly k times. You may choose the same index i multiple times. Return the largest possible sum of the array after modifying it in this way.

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int i, sum = 0;
        for (i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        while (k--)
        {
            int element = pq.top();
            if (element == 0)
            {
                break;
            }
            pq.pop();
            sum = sum - element;
            pq.push(-1 * element);
            sum = sum + (-1 * element);
        }
        return sum;
    }
};

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int &x : nums)
    {
        cin >> x;
    }
    cout << "Enter value of k: ";
    cin >> k;
    Solution s;
    int result = s.largestSumAfterKNegations(nums, k);
    cout << "Maximum sum after " << k << " negations is: " << result;

    return 0;
}