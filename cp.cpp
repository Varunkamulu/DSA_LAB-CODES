/*
//question-1
#include <iostream>
using namespace std;
void printNumber(int n)
{
    if(n==0)
    {
        return;
    }
    printNumber(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    printNumber(n);
    return 0;
}*/
/*
question-2
#include <iostream>
using namespace std;
int printSum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+printSum(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<printSum(n);
    return 0;
}*/
/*
question-3
#include <iostream>
using namespace std;
int printFib(int n)
{
    if(n<=1)
    {
        return n;
    }
    return printFib(n-1)+printFib(n-2);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cout<<printFib(i)<<" ";
    return 0;
}
*/
/*
question-4
#include <iostream>
using namespace std;
void printArr(int n,int arr[])
{
    if(n==0)
    {
        return;
    }
    printArr(n-1,arr);
    cout<<arr[n-1]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    printArr(n,arr);
    return 0;
}
*/
/*
question-5
#include <iostream>
using namespace std;
int countDigits(int n)
{
    if(n==0)return 0;
    return 1+countDigits(n/10);
}
int main()
{
    int n;
    cin>>n;
    cout<<countDigits(n);
    return 0;
}
*/
/*
question-6
#include <iostream>
using namespace std;
int sumDigits(int n)
{
    if(n==0)return 0;
    return ((n%10)+sumDigits(n/10));
}
int main()
{
    int n;
    cin>>n;
    cout<<sumDigits(n);
    return 0;
}
*/
/*
question-7
#include <iostream>
using namespace std;
int printGCD(int a,int b)
{
    if(b==0)return a;
    return printGCD(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<printGCD(a,b);
    return 0;
}
*/
/*
question-8
#include <iostream>
using namespace std;
int printMax(int n,int arr[])
{
    if(n==0)return 0;
    return max(arr[n-1],printMax(n-1,arr));
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<printMax(n,arr);
    return 0;
}
*/
/*
question-9
#include <iostream>
using namespace std;
int printFac(int n)
{
    if(n==0)return 1;
    return n*printFac(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<printFac(n);
    return 0;
}
*/
/*
question-10
#include <iostream>
using namespace std;
int printBinary(int n)
{
    if(n==0)return 0;
    printBinary(n>>1);
    cout<<n%2;
}
int main()
{
    int n;
    cin>>n;
    printBinary(n);
    return 0;
}
*/
/*
question-11
#include <iostream>
#include<cmath>
using namespace std;
bool printPrime(int n,int i=2)
{
    if(n%i==0)return false;
    if(i*i>n)return true;
    return printPrime(n,i+1);
}
int main()
{
    int n;
    cin>>n;
    cout<<((printPrime(n))?"it is prime":"it is not prime");
    return 0;
}
*/
/*
question-12
#include <iostream>
using namespace std;
int printGCD(int a,int b)
{
    if(b==0)return a;
    return printGCD(b,a%b);
}
int printLCM(int a,int b)
{
    return ((a*b)/printGCD(a,b));
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<printLCM(a,b);
    return 0;
}
*/
/*
question-13
#include <iostream>
using namespace std;
void printEven(int n)
{
    if(n==0)return;
    printEven(n-1);
    if(n%2==0)
    {
        cout<<n<<" ";
    }
}
void printOdd(int n)
{
    if(n==0)return ;
    printOdd(n-1);
    if(n%2==1)
    {
        cout<<n<<" ";
    }

}
int main()
{
    int n;
    cin>>n;
    cout<<"The even numbers are : ";
    printEven(n);
    cout<<endl;
    cout<<"The Odd numbers are : ";
    printOdd(n);
    return 0;
}
*/
/*
question-14
#include <iostream>
using namespace std;
const int MAX = 100;
void multiplyMatrixRec(int row1, int col1, int A[][MAX],
                       int row2, int col2, int B[][MAX],
                       int C[][MAX])
{
    static int i = 0, j = 0, k = 0;
    if (i >= row1)
        return;
    if (j < col2) {
        if (k < col1) {
            C[i][j] += A[i][k] * B[k][j];
            k++;
 
            multiplyMatrixRec(row1, col1, A, row2, col2, B,
                              C);
        }
 
        k = 0;
        j++;
        multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
    }
 
    j = 0;
    i++;
    multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
} 
void multiplyMatrix(int row1, int col1, int A[][MAX],
                    int row2, int col2, int B[][MAX])
{
    if (row2 != col1) {
        cout<<"Not Possible\n";
        return;
    }
 
    int C[MAX][MAX] = { 0 };
 
    multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
 
    cout<<"the final matrix is :"<<endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++)
            cout<< C[i][j]<<" ";
 
        cout<<endl;
    }
}
int main()
{
    int n1,m1,n2,m2;
    cin>>n1>>m1>>n2>>m2;
    int A[n1][MAX],B[n2][MAX];
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<m1;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n2;i++)
    {
        for(int j=0;j<m2;j++)
        {
            cin>>B[i][j];
        }
    }
    multiplyMatrix(n1, m1, A, n2, m2, B);
    return 0;
}
*/
/*
question-15
#include <iostream>
using namespace std;
int calPower(int n,int m)
{
    if(m==0)return 1;
    if(m%2)
    {
    int oddpow=calPower(n,m-1);
        return n*oddpow;
    }
    else 
    {
        int evepow=calPower(n,m/2);
        return evepow*evepow;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<calPower(n,m);
    return 0;
}*/
/*
question-16
#include <iostream>
using namespace std;
void HailStone(int n)
{
    if(n==1)
    {
        // cout<<1<<" ";
        return;}
    if(n%2==1)
    {
        n=3*n+1;
        cout<<n<<" ";
        HailStone(n);
    }
    else{
        n=n/2;
        cout<<n<<" ";
        HailStone(n);
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    cout<<"the hailstone sequence is : ";
    cout<<n<<" ";
    HailStone(n);
    return 0;
}
*/
/*
question-17
#include <iostream>
using namespace std;
bool BinarySearch(int i,int n,int arr[],int x)
{
    if(i>n)return false;
    int mid=(i+n)/2;
    if(arr[mid]==x)return true;
    return (BinarySearch(i,mid-1,arr,x)|BinarySearch(mid+1,n,arr,x));
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int x;
    cin>>x;
    cout<<(BinarySearch(0,n-1,arr,x)?"The element is found in the array":"the element is not found in the array");
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int cnt=0;
// int func(int a,int x,int arr[])
// {
//     if(x==0)
//     {
//         return arr[x]=a;
//     }
//     (func(0.8*(a-1),x-1,arr));
//     return arr[x]=0.2*(a-1);
// }
// int main()
// {
//     int arr[6];
//     func(3121,5,arr);
//     for(int i=5;i>=0;i--)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }
// for A,B,C--->THINK BRUTEFORCE APPROACH WITH SLIGHT OBSERVATION
/*
1)define a problem
2)see constraints and think of an algo
3)try to code 
4)orelse move on and upsolve it later
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define long long int;
// int mod = 1e9 + 7;
// #define all(v) v.begin(),v.end()
// #define rall(v) v.rbegin(),v.rend()
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define vll vector<int>
// #define vvll vector<vll>
// #define pb push_back
// #define yes cout<<"YES"<<endl;
// #define no cout<<"NO"<<endl;
// #define pll pair<int, int>
// #define vll vector<int>
// #define vpll vector<pll>
// #define vb vector<bool>
// #define vvll vector<vll>
// const int pi = 3.14159265358979323846;
// vb primes(100007, false);
// set<int> primes1;
// void seive()
// {
//     primes[1] = true;
//    for (int i = 2; i < 1000000; i++)
//     {
//        for (int j = 2 * i; j < 1000000; j += i)
//         {
//             primes[j] = true;
//         }
//     }
//     for (int i = 1; i < 1000000; i++)
//     {
//         if (primes[i] == false)
//         {
//             primes1.insert(i);
//         }
//     }
// }
// int power(int a, int b)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     if (b % 2)
//     {
//         return a * power(a, b / 2 )* power(a, b / 2 );
//     }
//     else
//         return power(a, b / 2) * power(a, b / 2);
// }
// int inv(int a, int b)
// {
//     return power(a, mod - 1);
// }
// void solve()
// {
//      multiset<int> s;
//      int n;cin>>n;
//      int res;
//      cin>>res;
//      vector<int> v(n);
//      for(int i=0;i<n;i++){cin>>v[i];s.insert(v[i]);}
//      sort(all(v));
//      int ans=0;
//      for(int i=n-1;i>=0;i--)
//      {
//         if(((v[i]%res)==0))
//         {
//             int cnt=0;
//             while(s.find(v[i])!=s.end())
//             {
//                 s.erase(s.find(v[i]));
//                 v[i]/=res;
//                 cnt++;
//             }
//             ans+=(cnt*(cnt-1)/2);
//         }
//      }
//      cout<<ans<<endl;

// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//    while (t--)
//     {
//         solve();
//     }
//     return 0;
// }