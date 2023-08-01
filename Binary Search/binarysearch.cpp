#include <iostream>
using namespace std;
int instruction = 0;

int binarySearch(int arr[], int l, int r, int x)
{
    instruction++;
    while (l <= r)
    {
        instruction++;
        int m = l + (r - l) / 2;

        instruction++;
        if (arr[m] == x)
            return m;

        instruction++;
        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
        instruction++;
    }
    instruction++;
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 40;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result << endl;

    cout << "Number of instructions executed: " << instruction << endl;
    return 0;
}
