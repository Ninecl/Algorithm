//AC
//思路其实是很清晰的，队列bfs即可，但是有很多代码实现的细节问题需要注意
//首先是超时超内存的问题，这个问题的起因是vis设置为1的位置，应该在check某个节点之后立刻置1，否则之后这个节点在因为在队列尾部，被访问的晚，仍然会被访问很多次
//第二个是队列创建的位置，要在bfs里创建，不能创建为全局变量，否则会有很多垃圾数据在里面

# include <cstdio>
# include <iostream>
# include <queue>
# include <cstring>

using namespace std;

int l, r, c;
char Map[31][31][31];
int vis[31][31][31];
int sx, sy, sz, ex, ey, ez;
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

struct node
{
    int x, y, z;
    int step;
};

int check(node n)
{
    if(vis[n.z][n.y][n.x])
        return 0;
    else if (!(n.x >= 0 && n.x < c && n.y >= 0 && n.y < r && n.z >= 0 && n.z < l))
        return 0;
    else if (Map[n.z][n.y][n.x] == '#')
        return 0;
    else
        return 1;
}

int bfs()
{
    queue<node> nodes;
    node n1, n2;
    n1.x = sx, n1.y = sy, n1.z = sz, n1.step = 0;
    vis[n1.z][n1.y][n1.x] = 1;
    nodes.push(n1);
    while(!nodes.empty())
    {
        n1 = nodes.front();
        nodes.pop();
        if(n1.x == ex && n1.y == ey && n1.z == ez)
            return n1.step;
        for(int i = 0; i < 6; i++)
        {
            n2 = n1;
            n2.x += dir[i][0];
            n2.y += dir[i][1];
            n2.z += dir[i][2];
            n2.step++;
            if(check(n2))
            {
                nodes.push(n2);
                vis[n2.z][n2.y][n2.x] = 1;
            }
        }
    }
    return 0;

}

int main()
{
    while(cin >> l >> r >> c)
    {
        if(l == 0 && r == 0 && c == 0)
            break;
        for(int i = 0; i < l; i++)
        {
            for(int j = 0; j < r; j++)
            {
                scanf("%s", Map[i][j]);
                for(int k = 0; k < c; k++)
                {
                    if(Map[i][j][k] == 'S')
                    {
                        sx = k;
                        sy = j;
                        sz = i;
                    }
                    else if(Map[i][j][k] == 'E')
                    {
                        ex = k;
                        ey = j;
                        ez = i;
                    }
                }
            }
        }

        memset(vis, 0, sizeof(vis));
        int ans = bfs();
        if (ans)
            cout << "Escaped in " << ans << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
        
    }
    return 0;
}
