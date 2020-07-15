#include <bits/stdc++.h>

using namespace std;

void InsertSort(int *array, int n) { // array待排序数组,n:数组元素数量
    int i, j;                        //循环变量
    int temp;                        //存储待排序元素
    for (i = 0; i < n; i++) {
        j = i;
        temp = array[i]; //待排序元素赋值给临时变量
        while (j > 0 && temp < array[j - 1]) {
            array[j] = array[j - 1]; //就将该元素后移
            j--;                     //下标减一，继续比较
        }
        array[j] = temp; //插入位置已经找到，立即插入
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}

void combine(stack a, stack b) {
    stack c;
    while (!b.empty()) {
        c.push(b.pop());
    }
    while (!c.empty()) {
        a.push(c.pop());
    }
}

void insert(list &l, int elem) {
    l.length++;
    for (int i = l.length - 1; i->0; i--) {
        if (l.data[i] >= elem) {
            l.data[i + 1] = l.data[i];
        } else {
            l.data[i + 1] = elem;
            break;
        }
    }
}
int main() {
    int arr[10] = {42, 84, 18, 50, 14, 26, 48, 38, 86, 65};
    InsertSort(arr, 10);
}