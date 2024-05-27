#include<bits/stdc++.h>
using namespace std;

int * sort_it(int n) {
    int *arr = new int[n]; 
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    return arr;
}

int main() {
    int a;
    cin >> a;
    int *sorted_arr = sort_it(a);
    for(int i = 0; i < a; ++i) {
        cout << sorted_arr[i] << " ";
    }
    return 0;
}
