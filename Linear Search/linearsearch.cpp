#include <iostream>
using namespace std;
int instructions = 0;
int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        instructions++;
        if (arr[i] == x)
        {
            instructions++;
            return i;
        }
    }

    instructions++;
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);

    int result = search(arr, N, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result << endl;

    cout << "Number of instructions execured: " << instructions << endl;
    return 0;
}
