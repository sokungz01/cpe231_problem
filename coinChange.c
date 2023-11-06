#include <stdio.h>
#define INF 100000000

int min(int a, int b);
void coinChange(int N, int M, int coins[], int quantity[]);

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int coins[M];
    int quantity[M];
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &coins[i]);
    }

    coinChange(N, M, coins, quantity);

    return 0;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void coinChange(int N, int M, int coins[], int quantity[])
{
    int dp[N + 1];
    int usedCoins[N + 1];
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = INF;
        for (int j = 0; j < M; j++)
        {
            if (i >= coins[j] && dp[i - coins[j]] + 1 <= dp[i])
            {
                dp[i] = dp[i - coins[j]] + 1;
                usedCoins[i] = j;
            }
        }
    }
    for (int j = 0; j < M; j++)
    {
        int count = 0;
        for (int i = N; i > 0; i -= coins[usedCoins[i]])
        {
            if (usedCoins[i] == j)
            {
                count++;
            }
        }
        printf("%d: %d\n", coins[j], count);
    }
}
