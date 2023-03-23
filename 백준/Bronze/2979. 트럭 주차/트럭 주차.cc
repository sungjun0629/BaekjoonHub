#include<iostream>
#include<vector>
using namespace std;

int total_cost = 0;

int main()
{
    int pay[3] = {0, };
    vector<int> time(101);

    for (int i = 0; i < 3; i++)
    {
        cin >> pay[i];
    }

    for (int i = 1; i <= 3; i++)
    {
        int start;
        int end;

        cin >> start;
        cin >> end;

        for (int j = start; j < end; j++)
        {
            time[j] += 1;
        }
    }

    for (int cost : time)
    {
       
        if (cost == 1) {
            total_cost += cost * pay[0];
        }
        else if (cost == 2)
        {
            total_cost += cost * pay[1];
        }
        else if (cost == 3)
        {
            total_cost += cost * pay[2];
        }
    }

    cout << total_cost;
}