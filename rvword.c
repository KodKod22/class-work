// Recitation #11
// Recursion

#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define TRUE 1
#define FALSE 0
// Functions Declarations

// find array's max value
int max_arr(int arr[], int len);
////////////////////////////////////////////////////////////////////////////////////

// Calc x to the power of n
// Example: pow(2, 10) => 1024
int rec_pow(int x, int n);
////////////////////////////////////////////////////////////////////////////////////

// reverse number digits
// Example: 12345 => 54321
int reverse(int n);
////////////////////////////////////////////////////////////////////////////////////

// Remove all vowels in a string
// Example: Hello World! => Hll Wrld!
char *unvowel(char *s);
////////////////////////////////////////////////////////////////////////////////////

// Determine whether a string is a palindrome
// Example: "racecar" => true
int is_palindrome(char *s);
////////////////////////////////////////////////////////////////////////////////////

// Binary search for a value in an array and return its index if found. Else return -1
int binary_search(char *arr[], int start, int end, char *word);
////////////////////////////////////////////////////////////////////////////////////

// Moed A 2019
int is_geometric_arr(int arr[], int n);
////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int arr[] = {12, 65, -3, 124, 67, 92, -13, 10, 0, 32};
    // int arr[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int len = sizeof(arr) / sizeof(arr[0]);
    char str2[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};

    char str[MAX_LEN] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};

    return 0;
}

// Implementation
int max_arr(int arr[], int len)
{
    if (len == 1)
        return arr[0];

    int max = max_arr(arr + 1, len - 1);

    return arr[0] > max ? arr[0] : max;
}

int rec_pow(int x, int n)
{
    if (n == 0)
        return 1;

    return x * rec_pow(x, n - 1);
}

int reverse(int n)
{
    if (n < 10)
        return n;

    return n % 10 + reverse(n / 10) * 10;
}

char *unvowel(char *s)
{
    if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
    {
        int i = 0;
        while (s[i])
        {
            s[i] = s[i + 1];
            i++;
        }
        unvowel(s);
    }
    else if (*s)
    {
        unvowel(s + 1);
    }

    return s;
}

int is_palindrome(char *s)
{
    int rc = 0;
    int len = strlen(s);
    if (len == 0)
        return 1;

    char last = *(s + len - 1);
    if (*s == last)
    {
        // replace last char with '\0' so that we can short the string
        // Example: "racecar"
        // 1st call (s = "racecar")
        // 2nd call (s = "aceca") => We removed the first char and the last char
        // ...
        *(s + len - 1) = '\0';
        rc = is_palindrome(s + 1);
        // Here we restore the last char
        *(s + len - 1) = last;
        return rc;
    }
    else
        return 0;
}

int binary_search(char *arr[], int start, int end, char *word)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;
    if (strcmp(arr[mid], word) == 0)
        return mid;

    if (strcmp(arr[mid], word) > 0)
        return binary_search(arr, start, mid - 1, word);
    else
        return binary_search(arr, mid + 1, end, word);
}

int is_geometric_arr(int arr[], int n)
{
    if (n < 3)
        return TRUE;

    if ((float)arr[0] / arr[1] == (float)arr[1] / arr[2])
        return is_geometric_arr(arr + 1, n - 1);

    return FALSE;
}