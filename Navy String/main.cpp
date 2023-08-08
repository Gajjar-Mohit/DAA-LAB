#include <iostream>
using namespace std;

void search(char *pattern, char *txt)
{
    int M = strlen(pattern);
    int N = strlen(txt);

    for (int i = 0; i <= N - M; i++)
    {
        int j;

        for (j = 0; j < M; j++)
            if (txt[i + j] != pattern[j])
                break;

        if (j == M)
            cout << "Found at index " << i << endl;
    }
}


int main()
{
    char string[] = "aaaaab";
    char pattern[] = "aab";

    
    search(pattern, string);
    return 0;
}