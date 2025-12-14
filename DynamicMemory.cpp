#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int* arr = new int[n]; // dynamic alloc

    for (int i = 0; i < n; i++)
        arr[i] = i * 10;

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
}
