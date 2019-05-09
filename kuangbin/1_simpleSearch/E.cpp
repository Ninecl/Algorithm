//AC
//本题并不复杂，其实只是bfs的水题，并不涉及到大数
//但是有一个玄学问题。。。24行的printf，如果放到main里面printf就会报错。。。真、玄学

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n;

void cal(int x)
{
    long long n1 = 1;
    queue<long long> que;
    que.push(n1);
    while(!que.empty())
    {
        n1 = que.front();
        que.pop();
        if(n1 % (long long)x == 0)
        {
            printf("%lld\n", n1);
            return;
        }
        else
        {
            que.push(n1 * 10);
            que.push(n1 * 10 + 1);
        }
        
    }
}

int main()
{
    while(scanf("%d", &n) && n != 0)
    {
        cal(n);
    }
    return 0;
}