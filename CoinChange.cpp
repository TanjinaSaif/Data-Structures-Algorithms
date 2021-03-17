#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int coins[10] = {10,2,5,100,1000,500,200,20,50,1};
    int s = sizeof(coins)/sizeof(int);
    sort(coins,coins+s);
    int taka = 1230;
    for(int i = s-1 ; i>=0 ; i-- ) /*Traversing from last*/
    {
        int note = coins[i];
        while (taka>=note)
        {
            taka -= note;
            cout<<note<<" ";
        }


    }
}
