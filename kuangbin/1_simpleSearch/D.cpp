//AC
//首先本题应该算是二进制暴力搜索，用到了二进制遍历的技巧
//此外这题大部分事件都花在了代码细节上，有一个可以注意的地方是，带表示数组的时候不要用x，y来表示了，用r和w来表示更加清晰明了
# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

const int maxn = 20;
const int INF = 0x3f3f3f3f;
int m, n;
int Map1[maxn][maxn], Map2[maxn][maxn], ans[maxn][maxn], flipMap[maxn][maxn];
int dir[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int check(int x, int y)
{
    if(x >= 0 && x < m && y >= 0 && y < n)
        return 1;
    else
        return 0;
}

void flip(int x, int y)
{
    flipMap[x][y] = 1;
    int nx, ny;
    for(int i = 0; i < 5; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if(check(nx, ny))
            Map2[nx][ny] ^= 1;
    }
}

int work(int l)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(l >> i & 1)
        {
            flip(0, i);
            cnt++;
        }
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(Map2[i-1][j])
            {
                flip(i, j);
                cnt++;
            }
        }
    }

    int i = 0;
    for(i; i < n; i++)
    {
        if(Map2[m-1][i] == 1)
            break;
    }

    if(i == n)
        return cnt;
    else
        return INF;
}

int main()
{
    while(scanf("%d %d", &m, &n) != EOF)
    {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &Map1[i][j]);
        
        int ansCnt = INF;
        for(int l = 0; l < 1<<n; l++)
        {
            memset(flipMap, 0, sizeof(flipMap));
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    Map2[i][j] = Map1[i][j];

            int tmp = work(l);
            if(tmp < ansCnt)
            {
                ansCnt = tmp;
                for(int i = 0; i < m; i++)
                    for(int j = 0; j < n; j++)
                        ans[i][j] = flipMap[i][j];
            }
        }
        if(ansCnt == INF)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                    cout << ans[i][j] << ' ';
                cout << endl;
            }
        }
    }
}