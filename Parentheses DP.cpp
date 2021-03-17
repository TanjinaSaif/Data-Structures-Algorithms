#include<bits/stdc++.h>
using namespace std;

int num[100];
char op[99];

int p_recursion(int i, int j )
{
    //Base Case
    if( i == j ) return num[ i ];
    else
    {
        int maximum = -99999;
        for(int k = i; k < j; k++)
        {
            int value;
            if( op[ k ] == '+' )
            {
                value = p_recursion( i, k ) + p_recursion( k + 1, j );
            }
            else if(op[k] == '-' )
            {
                value = p_recursion( i, k ) - p_recursion( k + 1, j);
            }
            else
            {
                value = p_recursion( i, k ) * p_recursion( k  + 1, j );
            }
            if( value > maximum)
                maximum = value;
        }
        return maximum;
    }
}

int parentheses_dp(int num[],char op[],int n)
{
    int dp[n][n];
    int ans = -1;

    //For Base case
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = -1;

            if(i==j) dp[i][j] = num[i];
        }
    }

    //Values Outside DP Array Diagonal
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j) //setting values outside diagonal
            {
                int result, temp = -99999;

                if(i < j) //Right Side of Diagonal
                {
                    for(int k=i; k<j; k++)
                    {
                        if(op[k] == '+')
                        {
                            result = dp[i][k] + dp[k+1][j];
                        }
                        else if(op[k] == '-')
                        {
                            result = dp[i][k] - dp[k+1][j];
                        }
                        else
                        {
                            result = dp[i][k] * dp[k+1][j];
                        }

                        if(result > temp)
                            temp = result;
                    }

                    dp[i][j] = temp;
                }

                else if(i > j) //Left Side of Diagonal
                {
                    for(int k=j; k<i; k++)
                    {
                        if(op[k] == '+')
                        {
                            result = dp[j][k] + dp[k+1][i];
                        }
                        else if(op[k] == '-')
                        {
                            result = dp[j][k] - dp[k+1][i];
                        }
                        else
                        {
                            result = dp[j][k] * dp[k+1][i];
                        }

                        if(result > temp)
                            temp = result;
                    }

                    dp[i][j] = temp;
                }
            }
        }
    }

     for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {

            {
                cout<<dp[i][j]<<"    ";
            }
        }
    }
    //Searching maximum from 2D DP array
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(dp[i][j] > ans)
            {
                ans = dp[i][j];
            }
        }
    }
    return ans;
}
//Main Function
int main()
{
    int n;
    cout<<"Enter total digits : ";
    cin>>n;

    cout<<"Enter the numbers : ";
    for(int i=0; i<n; i++)
    {
        cin>>num[i];
    }

    cout<<"Enter Operators: ";
    for(int i=0; i<n-1; i++)
    {
        cin>>op[i];
    }

    int max1 = p_recursion(0,n-1);
    cout<<endl<<"Maximum in Recursion :"<<max1<<endl;

    int max2 = parentheses_dp(num,op,n);
    cout<<endl<<"Maximum in DP :"<<max2<<endl;



    return 0;
}
