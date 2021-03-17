#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Item
{
    int w,v,label;
};
bool cmp(struct Item x, struct Item y)
{
    double r1 = (double)x.v / x.w;
    double r2 = (double)y.v / y.w;
    return r1 > r2;
}
void Knapsack(int capacity,Item arr[],int n)
{
    sort(arr,arr+n,cmp);
    double profit=0.0;
    for(int i=0; i<n; i++)

    {
        if(capacity >= arr[i].w)
        {
            capacity -= arr[i].w;
            profit += arr[i].v ;
            cout<<"item "<<arr[i].label<<": "<<arr[i].w<<" kg"<<endl;
        }
        else if(capacity >0 && capacity < arr[i].w)
        {
            cout<<"item "<<arr[i].label<<": "<<capacity<<" kg"<<endl;
            profit+=arr[i].v*((double)capacity/arr[i].w);
            break;
        }
    }
    cout<< "Total value gained "<<": "<<profit<<endl;
}
int main()
{
    int n, capacity;
    cout<<"Numbers of items:";
    cin>>n;
    Item arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i].label=i+1;
        cout<<"Weight of item "<<i+1<<": ";
        cin>>arr[i].w;
        cout<<"Value of item "<<i+1<<": ";
        cin>>arr[i].v;
    }
    cout<<"Maximum,capacity : ";
    cin>>capacity;
    cout<<endl;
    Knapsack(capacity,arr,n);
    return 0;
}
