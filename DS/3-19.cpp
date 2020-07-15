#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 4096;

template <class T> class stack {
  public:
    stack();
    ~stack();
    void push(T x);
    void pop();
    T top();
    bool isEmpty();

  private:
    T *data;
    int size;
};

template <class T> stack<T>::stack() {
    size = 0;
    data = new T[maxn];
}

template <class T> stack<T>::~stack() { delete[] data; }

template <class T> void stack<T>::push(T x) {
    size++;
    data[size - 1] = x;
}

template <class T> void stack<T>::pop() { size--; }

template <class T> T stack<T>::top() { return data[size - 1]; }

template <class T> bool stack<T>::isEmpty() { return size == 0; }

bool match(char c[], int n) {
    if (n < 0)
        return false;
    stack<char> s;
    for (int i = 1; i <= n; i++) {
        if (c[i] == '{' || c[i] == '[' || c[i] == '(') {
            s.push(c[i]);
        } else if (c[i] == ')') {
            if (s.top() == '(')
                s.pop();
            else {
                return false;
            }
        } else if (c[i] == '}') {
            if (s.top() == '{')
                s.pop();
            else {

                return false;
            }
        } else if (c[i] == ']') {
            if (s.top() == '[')
                s.pop();
            else {
                return false;
            }
        }
    }
    return s.isEmpty() ? true : false;
}

int main() {
    cout << "Input the sequence:" << endl;
    char seq[maxn];
    scanf("%s", seq + 1);
    if (match(seq, strlen(seq))) {
        cout << "Success!" << endl;
    } else {
        cout << "Failed!" << endl;
    }
    return 0;
}
