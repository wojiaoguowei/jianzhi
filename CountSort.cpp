#include<iostream>
#include<stdlib.h>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *c = new int[n];
    memset(a, 0, n*sizeof(int));
    memset(c, 0, n*sizeof(int));
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        max = a[i]>max ? a[i] : max;
    }
    int *b = new int[max+1];
    memset(b, 0, (max+1)*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    for (int i = 1; i < max + 1; i++)
    {
        b[i] = b[i] + b[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]--;
        c[b[a[i]]] = a[i];
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << endl;
    delete[]a;
    delete[]b;
    delete[]c;

    return 0;
}
