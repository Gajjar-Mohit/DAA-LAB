#include <iostream>

using namespace std;
void bubbleshort(int arr[], int n)
{
    int instruction = 0;
    for (int i = 0; i < n - 1; i++)
    {
        instruction++;
        for (int j = 0; j < n - i - 1; j++)
        {
            instruction++;
            if (arr[j] > arr[j + 1])
            {
                instruction++;
                int temp = arr[j];
                instruction++;
                arr[j] = arr[j + 1];
                instruction++;
                arr[j + 1] = temp;
                instruction++;
            } 
            instruction++;
        }
        instruction++;
    }
    instruction++;
    cout << "Number of instructions executed: " << instruction << endl;
    cout << "Number of input: " << n << endl;
}
int main(void)
{
    // worst case
    cout << "=================================" << endl;
    cout << "Worst case" << endl;
    cout << "Input: 5 4 3 2 1" << endl;
    cout << "---------------------------------" << endl;
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleshort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "=================================" << endl;

    // best case
    cout << "=================================" << endl;
    cout << "Best case" << endl;
    cout << "Input: 1 2 3 4 5" << endl;
    cout << "---------------------------------" << endl;
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleshort(arr1, n1);
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "=================================" << endl;

    cout << "=================================" << endl;
    cout << "Average case" << endl;
    cout << "Input: 1 2 3 5 4" << endl;
    cout << "---------------------------------" << endl;
    int arr2[] = {1, 2, 3, 5, 4};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    bubbleshort(arr2, n2);
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "=================================" << endl;
    return 0;
}