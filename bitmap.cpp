#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 500
int output[200][200];
class p
{
public:
    int x, y, data;
    p(){};
    p(int x, int y, int data)
    {
        this->x = x;
        this->y = y;
        this->data = data;
    }
};

string s;
int n, m;
queue<p> que;

void mbfs()
{
    while (!que.empty())
    {
        p temp = que.front();
        que.pop();

        int tempx = temp.x;
        int tempy = temp.y;
        int tempd = temp.data;

        if (tempx < 0)
            continue;
        if (tempy < 0)
            continue;
        if (tempx >= n)
            continue;
        if (tempy >= m)
            continue;

        if (output[tempx][tempy] != 500)
            continue;

        output[tempx][tempy] = tempd;
        que.push(p(tempx + 1, tempy, tempd + 1));
        que.push(p(tempx, tempy + 1, tempd + 1));
        que.push(p(tempx - 1, tempy, tempd + 1));
        que.push(p(tempx, tempy - 1, tempd + 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                output[i][j] = MAX;
                if (s[j] == '1')
                {
                    que.push(p(i, j, 0));
                }
            }
        }

        mbfs();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << output[i][j] << " ";
            cout << endl;
        }

        cout << endl;
    }
    return 0;
}

/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
            {
                output[i][j] = MAX;
            }
        } 

        int row, col;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == '1')
                {
                    output[i][j] = 0;
                    row = i; col = j;
                }
            }
        }

        queue<pi> q;
        q.push({row, col});

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++)
            {
                visited[i][j] = false;
            }
        }

        while(!q.empty())
        {
            pi temp = q.front();
            q.pop();

            int temp_row = temp.first;
            int temp_col = temp.second;    

            visited[temp_row][temp_col] = true;

            if(output[temp_row][temp_col] == MAX)
            {
                for(int i = 0; i < 4; i++) check[i] = MAX;
                if(temp_row-1 >= 0) check[0] = output[temp_row-1][temp_col];
                if(temp_row+1 < n) check[1] = output[temp_row+1][temp_col];
                if(temp_col-1 >= 0) check[2] = output[temp_row][temp_col-1];
                if(temp_col+1 < m) check[3] = output[temp_row][temp_col+1];
                int ans = *min_element(check, check+4);
                output[temp_row][temp_col] = ans + 1;
            }

            if(temp_row-1 >= 0 && !visited[temp_row-1][temp_col])
            {
                pi x({temp_row-1, temp_col});
                q.push(x);
            }

            if(temp_col-1 >= 0 && !visited[temp_row][temp_col-1])
            {
                pi x({temp_row, temp_col-1});
                q.push(x);
            }

            if(temp_col+1 < m && !visited[temp_row][temp_col+1])
            {
                pi x({temp_row, temp_col+1});
                q.push(x);
            }

            if(temp_row+1 < n && !visited[temp_row+1][temp_col])
            {
                pi x({temp_row+1, temp_col+1});
                q.push(x);
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << output[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
*/