//AC
//简单的队列bfs，但是遇到了RuntimeError的小问题，是由于数组越界引起的
//要注意在check函数中要先判断x是否在范围内，再判断vis[x]，否则会导致vis数组越界引起RuntimeError
//此外，在第24行中，必须要>=maxn，>maxn都会RuntimeError，可见有的时候用例给的是非常苛刻的

# include <cstdio>
# include <iostream>
# include <cstring>
# include <queue>

using namespace std;

const int maxn = 1e5 + 5;
int n, k;
int vis[maxn];

struct pos
{
    int x, step;
};

int check(int x)
{
    if(x < 0 || x >= maxn)
        return 0;
    else if(vis[x])
        return 0;
    else
        return 1;
}

int bfs(int s, int e)
{
    queue<pos> que;
    pos now, nxt;
    now.x = s, now.step = 0;
    vis[now.x] = 1;
    que.push(now);
    while(!que.empty())
    {
        now = que.front();
        if(now.x == e)
            return now.step;
        que.pop();
        if(check(now.x - 1))
        {
            nxt = now;
            nxt.x--;
            nxt.step++;
            que.push(nxt);
            vis[nxt.x] = 1;
        }
        if(check(now.x + 1))
        {
            nxt = now;
            nxt.x++;
            nxt.step++;
            que.push(nxt);
            vis[nxt.x] = 1;
        }
        if(check(now.x * 2))
        {
            nxt = now;
            nxt.x *= 2;
            nxt.step++;
            que.push(nxt);
            vis[nxt.x] = 1;
        }
    }
}

int main()
{
    while(scanf("%d %d", &n, &k) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        cout << bfs(n, k) << endl;
    }
}