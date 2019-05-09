//AC
//2019-5-5
//开始刷题，复习了一下c++的一些写法和dfs
//首先是递归的边界问题要注意，其次是有放回的递归要注意下一次的递归要放在哪里

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n, k;
char Map[10][10];
int total, ans;
int vis[10];

void dfs(int curpos)
{
    if(total == k)
    {
        ans++;
        return;
    }
    if(curpos >= n)
        return;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i] && Map[curpos][i] == '#')
        {
            vis[i] = 1;
            total++;
            dfs(curpos + 1);
            vis[i] = 0;
            total--;
        }
    }
    dfs(curpos + 1);
}
int main()
{
    while(cin >> n >> k)
    {
        if(n == -1 && k == -1)
            break;  
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> Map[i][j];
        memset(vis, 0, sizeof(vis));
        total = 0;
        ans = 0;
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}