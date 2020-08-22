//
//  main.cpp
//  DSA
//
//  Created by Anurag Gupta on 16/08/20.
//  Copyright © 2020 Anurag Gupta. All rights reserved.
//

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int BS(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + ((r - l) / 2);
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            return BS(arr, l, mid - 1, x);
        }
        else
        {
            return BS(arr, mid + 1, r, x);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    cout << endl
         << "Enter no. in array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cout << "Enter No. to find in array : ";
    cin >> x;
    int p = BS(arr, 0, n - 1, x);
    cout << endl
         << p << endl;
    return 0;
}
