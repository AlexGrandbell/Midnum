#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 找到两个有序数组的中位数
void findMedian(vector<int>& X, vector<int>& Y, int n) {
    int lowX = 0, highX = n - 1; // X数组的边界
    int lowY = 0, highY = n - 1; // Y数组的边界

    while (true) {
        int midX = (lowX + highX) / 2;
        int midY = (lowY + highY) / 2;

        // 边界条件
        if (lowX == highX || lowY == highY) {
            cout<< min(X[lowX], Y[lowY])<<endl;
            return;
        }
        if (highX - lowX == 1 || highY - lowY == 1) {
            cout<< (max(X[lowX], Y[lowY]) + min(X[highX], Y[highY])) / 2.0<<endl;
            return;
        }

        // 中位数比较
        if (X[midX] == Y[midY]) {
            cout<< X[midX] <<endl;
            return;
        } else if (X[midX] < Y[midY]) {
            if ((highX - lowX + 1) % 2 == 0) {
                lowX = midX + 1;
            } else {
                lowX = midX;
            }
            highY = midY;
        } else {
            if ((highX - lowX + 1) % 2 == 0) {
                highX = midX - 1;
            } else {
                highX = midX;
            }
            lowY = midY;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> X(n);
    vector<int> Y(n);

    for (int i = 0; i < n; ++i)
        cin >> X[i];

    for (int i = 0; i < n; ++i)
        cin >> Y[i];

    findMedian(X, Y, n);

    return 0;
}
