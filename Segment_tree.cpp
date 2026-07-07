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


// Use point update

#include <bits/stdc++.h>
using namespace std;

// Build Segment Tree
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

// Point Update
void update(int index, int val, int low, int high, int idx, vector<int> &segment)
{
    if (low == high)
    {
        segment[idx] = val;
        return;
    }

    int mid = (low + high) / 2;

    if (index <= mid)
        update(index, val, low, mid, 2 * idx + 1, segment);
    else
        update(index, val, mid + 1, high, 2 * idx + 2, segment);

    segment[idx] = min(segment[2 * idx + 1], segment[2 * idx + 2]);
}

// Range Minimum Query
int query(int l, int r, int low, int high, int idx, vector<int> &segment)
{
    // Complete overlap
    if (low >= l && high <= r)
        return segment[idx];

    // No overlap
    if (high < l || low > r)
        return INT_MAX;

    // Partial overlap
    int mid = (low + high) / 2;

    int left = query(l, r, low, mid, 2 * idx + 1, segment);
    int right = query(l, r, mid + 1, high, 2 * idx + 2, segment);

    return min(left, right);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> segment(4 * n);

    // Build Tree
    Built(arr, 0, n - 1, 0, segment);

    cout << "Segment Tree after Build:\n";
    for (int i = 0; i < segment.size(); i++)
    {
        cout << i << " : " << segment[i] << endl;
    }

    // Query before update
    cout << "\nMinimum in range [1, 4] = "
         << query(1, 4, 0, n - 1, 0, segment) << endl;

    // Update index 2 from 5 to 6
    update(2, 6, 0, n - 1, 0, segment);

    cout << "\nSegment Tree after Update:\n";
    for (int i = 0; i < segment.size(); i++)
    {
        cout << i << " : " << segment[i] << endl;
    }

    // Query after update
    cout << "\nMinimum in range [1, 4] = "
         << query(1, 4, 0, n - 1, 0, segment) << endl;

    return 0;
}
