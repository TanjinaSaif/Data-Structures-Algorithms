#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
/* Checking if no. is prime or not */
bool primeNaive(int n){

    if( n == 1)
        return false;

    for(int i = 2; i <= sqrt( n ); i++){
        if( n % i == 0 ){
            return false;
        }
    }
    return true;
}
/* To print 1-nth prime numbers */
void printPrimes(int n){
    for(int i = 1; i <= n; i++){
        if( primeNaive( i ) == true ){  /*calling primeNaive() to check prime*/
            cout << i << " ";
        }
    }
    cout<<endl;
}
/* Sieve of Eratosthenes Algorithm for prime no. */
void primeSieve(int n){
    bool arr[ n + 1 ];
    for(int i = 1; i < n; i++)
        arr[i] = 1;

    for(int i = 2; i * i <= n; i++){
        if( arr[ i ] == 1){
            for(int j = i * i; j <= n; j += i){
                arr[ j ] = 0;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(arr[ i ] == 1){
            cout<< i <<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin >> n;
    auto start = high_resolution_clock::now();
    printPrimes( n );
    auto stop = high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    start = high_resolution_clock::now();
    primeSieve( n );
    stop = high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << setprecision( 10 ) << "prime_Naive - " << duration.count() << '\n';
    cout << setprecision( 10 ) << "prime_Sieve - " << duration1.count() << '\n';
    return 0;
}
