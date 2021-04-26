# Binary_Search
- 오름차순으로 정렬된 리스트에서 특정한 위치를 찾는 알고리즘.
- 오름차순으로 정렬된 리시트의 중간 값으로 선택하여, 찾고자 하는 Key 값과 비교하는 방식으로 돌아가는 알고리즘.
- 단점: 정렬된 리스트에서만 사용할 수 있음.
- 장점: 빠르다.

## 구현방법 1) 직접 구현

```js:binary_search.cpp
bool binarySearch(int *arr, int len, int key) {
    int start = 0;
    int end = len - 1;
    int mid;
    while(end - start >= 0) {
        mid = (start + end) / 2; 
        if(arr[mid] == key) {
            return true;
        }
        else if(arr[mid] > key) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
}
```

## 구현방법 2) 재귀

```js:Recursion
bool binarySearch(int *arr, int start, int end, int key) {
    if(start > end) return false;
    int mid = (start+end) / 2;

    if(arr[mid] == key) {
            return true;
    } else if (arr[mid] > key) {
            return binary
    } else {
            return binarySearch(arr, mid + 1, end, key);
    }
}
```

## 구현방법 3) STL
- `<Algorithm>의 binary_search() 함수 이용`
#### `template <class ForwardIterator, class T>` 
#### `bool binary_search(ForwardIterator first, ForwardIterator last, const T& val)`
```js:STL
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 100;
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
        cout << "exist : " << binary_search(arr, arr+n, 70) << endl;
    return 0;
}
```