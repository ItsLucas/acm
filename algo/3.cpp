#include <bits/stdc++.h>

using namespace std;

void InsertSort(int *array, int n) { // array����������,n:����Ԫ������
    int i, j;                        //ѭ������
    int temp;                        //�洢������Ԫ��
    for (i = 0; i < n; i++) {
        j = i;
        temp = array[i]; //������Ԫ�ظ�ֵ����ʱ����
        while (j > 0 && temp < array[j - 1]) {
            array[j] = array[j - 1]; //�ͽ���Ԫ�غ���
            j--;                     //�±��һ�������Ƚ�
        }
        array[j] = temp; //����λ���Ѿ��ҵ�����������
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