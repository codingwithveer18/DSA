#include <iostream>
using namespace std;

// initializing an array of alphabets
char getmaxoccur(string s)
{
    int arr[26] = {0};

    // Created and array of count of characters
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        // lowercase
        int index = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            index = ch - 'a';
        }
        // Uppercase
        else
        {
            index = ch - 'a';
        }
        arr[index]++;
    }
    int maxi = -1, ans = 0;
    for (int i = 0; i <26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }

    return 'a' + ans;
}

int main()
{
    string s;
    cin >> s;
    cout << "max occur element : " << getmaxoccur(s);

    return 0;
}