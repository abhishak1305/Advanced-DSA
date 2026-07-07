#include <bits/stdc++.h>
using namespace std;

void Built(int arr[], int low, int high, int idx, vector<int> &segment)
{
    if (low == high)
    {
        segment[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    Built(arr, low, mid, 2 * idx + 1, segment);
    Built(arr, mid + 1, high, 2 * idx + 2, segment);

    segment[idx] = min(segment[2 * idx + 1], segment[2 * idx + 2]);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> segment(4 * n, -1);

    Built(arr, 0, n - 1, 0, segment);

    cout << "Segment Tree:\n";
    for (int i = 0; i < segment.size(); i++)
    {
        cout << i <<":"<<segment[i] <<endl;
    }

    return 0;
}
