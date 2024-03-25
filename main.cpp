#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>

using namespace std;

double findMedian(vector<int>& X, vector<int>& Y, int n) {
    //边界条件
    if (n == 1) {
        return (X[0] + Y[0]) / 2.0;
    } else if(n == 2){
        int low = max(X[0],Y[0]);
        int max = min(X[1],Y[1]);
        return (low + max)/2.0;
    }

    int mid1 = (n-1) / 2;
    int mid2 = mid1 + 1;
    double midx, midy;
    if (n % 2 == 0) {
        midx = (X[mid1] + X[mid2]) / 2.0;
        midy = (Y[mid1] + Y[mid2]) / 2.0;
        if (fabs(midx-midy)<1e-9) {
            return midx;
        } else if (midx > midy) {
            vector<int> XX;
            for(int i = 0;i<=mid2;i++){
                XX.push_back(X[i]);
            }
            vector<int> YY;
            for(int i = mid1;i<n;i++){
                YY.push_back(Y[i]);
            }
            n = YY.size();
            return findMedian(XX,YY,n);
        } else if (midx < midy) {
            vector<int> XX;
            for(int i = mid1;i<n;i++){
                XX.push_back(X[i]);
            }
            vector<int> YY;
            for(int i = 0;i<=mid2;i++){
                YY.push_back(Y[i]);
            }
            n = YY.size();
            return findMedian(XX,YY,n);
        }
    } else {
        midx = X[mid1];
        midy = Y[mid1];
        if (midx == midy) {
            return midx;
        } else if (midx > midy) {
            vector<int> XX;
            for(int i = 0;i<=mid1;i++){
                XX.push_back(X[i]);
            }
            vector<int> YY;
            for(int i = mid1;i<n;i++){
                YY.push_back(Y[i]);
            }
            n = YY.size();
            return findMedian(XX,YY,n);
        } else if (midx < midy) {
            vector<int> XX;
            for(int i = mid1;i<n;i++){
                XX.push_back(X[i]);
            }
            vector<int> YY;
            for(int i = 0;i<=mid1;i++){
                YY.push_back(Y[i]);
            }
            n = YY.size();
            return findMedian(XX,YY,n);
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> X;
    vector<int> Y;

    int num;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        X.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        cin >> num;
        Y.push_back(num);
    }

    cout<<findMedian(X, Y, n);

    return 0;
}