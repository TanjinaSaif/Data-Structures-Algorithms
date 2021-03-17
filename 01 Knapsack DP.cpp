#include<iostream>
using namespace std;

int knapsack(int M, int wt[], int v[], int n)
{
    int dp[n + 1][M + 1];

    for (int i = 0; i <= n; i++)  //Columns with values//
    {
        for (int w = 0; w <= M; w++) //Row with weights//
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max( dp[i-1][M], dp[i-1][w-wt[i-1]]+v[i -1] );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][M];
}
int main()
{
    int n;
    cout<<"Enter no. of items :";
    cin>>n;
    int v[10],wt[10];
    cout<<"Enter weights of items :";
    for(int i=0 ; i<n ; i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter values of items :";
    for(int i=0 ; i<n ; i++)
    {
        cin>>v[i];
    }
    int M;
    cout<<"Maximum Capacity of Knapsack :";
    cin>>M;
    int result = knapsack(M, wt, v, n);
    cout<<result<<endl;
    return 0;
}

