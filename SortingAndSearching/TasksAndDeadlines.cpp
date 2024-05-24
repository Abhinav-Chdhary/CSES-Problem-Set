#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

/*
 Intuition: Sort by duration

 Time-complexity: O(nlogn)
 Space-complexity: O(1)
*/
void allocatinator(vector<vector<ll>> &tasks, const int &n)
{
    sort(tasks.begin(), tasks.end());
    ll reward = 0, curTime = 0;
    for (auto task : tasks)
    {
        int duration = task[0];
        int deadline = task[1];
        reward += deadline - (curTime + duration);
        curTime += duration;
    }
    cout << reward << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<ll>> arr(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    allocatinator(arr, n);
    return 0;
}