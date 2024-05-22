#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

void allocatinator(vector<vector<int>> &customers, int &n)
{
    sort(customers.begin(), customers.end(), cmp);
    int curRoom = 0, ind = 0;
    vector<int> roomNo(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (; ind < n; ind++)
    {
        auto cus = customers[ind];
        // if a prev room is free
        if (!pq.empty() and pq.top().first < cus[0])
        {
            auto room = pq.top().second;
            pq.pop();
            pq.push({cus[1], room});
            roomNo[cus[2]] = room;
        }
        // else allocate new room
        else
        {
            pq.push({cus[1], ++curRoom});
            roomNo[cus[2]] = curRoom;
        }
    }
    cout << curRoom << endl;
    for (int i : roomNo)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> customers(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i][0] >> customers[i][1];
        customers[i][2] = i;
    }
    allocatinator(customers, n);
    return 0;
}