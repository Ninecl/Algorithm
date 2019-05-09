//AC
//bfs，加上素数判断，通过打表来判断素数
//本来应该直接过的，但是居然忘了设置vis=1，导致一直t，要记得设置vis啊...

#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct num
{
    int x, step;
};

int n;
int n1, n2;
int vis[10000], prime[10000];

int check(int x)
{
    if(vis[x])
        return 0;
    else if(!prime[x])
        return 0;
    else
        return 1;
    
}
int bfs(int n1, int n2)
{
    num num1, num2;
    num1.x = n1, num1.step = 0;
    vis[n1] = 1;
    queue<num> que;
    que.push(num1);
    while(!que.empty())
    {
        num1 = que.front();
        que.pop();
        if(num1.x == n2)
            return num1.step;
        for(int i = 0; i < 10; i++)
        {
            int a = num1.x / 10;
            num2.x = a * 10 + i;
            num2.step = num1.step + 1;
            if(check(num2.x))
            {
                que.push(num2);
                vis[num2.x] = 1;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            int a = num1.x / 100;
            int b = num1.x % 10;
            num2.x = a * 100 + i * 10 + b;
            num2.step = num1.step + 1;
            if(check(num2.x))
            {
                que.push(num2);
                vis[num2.x] = 1;
            }
        }
        for(int i = 0; i < 10; i++)
        {
            int a = num1.x / 1000;
            int b = num1.x % 100;
            num2.x = a * 1000 + i * 100 + b;
            num2.step = num1.step + 1;
            if(check(num2.x))
            {
                que.push(num2);
                vis[num2.x] = 1;
            }
        }
        for(int i = 1; i < 10; i++)
        {
            int b = num1.x % 1000;
            num2.x = i * 1000 + b;
            num2.step = num1.step + 1;
            if(check(num2.x))
            {
                que.push(num2);
                vis[num2.x] = 1;
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 10000; i++)
        prime[i] = i;
    for(int i = 2; i < 10000; i++)
    {
        for(int j = i * 2; j < 10000; j++)
        {
            if(prime[j] == 0)
                continue;
            if(j % i == 0)
                prime[j] = 0;
        }
    }
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &n1, &n2);
            memset(vis, 0, sizeof(vis));
            cout << bfs(n1, n2) << endl;
        }
    }
}
