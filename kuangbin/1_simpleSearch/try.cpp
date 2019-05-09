# include <iostream>

using namespace std;

int x[3] = {1, 1, 1};
int prime[10000];

int main()
{
    for(int i = 0; i < 10000; i++)
        prime[i] = i;
    for(int i = 2; i < 10000; i++)
    {
        for(int j = i * 2; j < 10000; j++)
        {
            if(j % i == 0)
                prime[j] = 0;
        }
    }
    for (int i = 0; i < 100000; i++)
        cout << prime[i] << ' ';
}