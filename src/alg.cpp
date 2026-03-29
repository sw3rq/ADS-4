// Copyright 2025 NNTU-CS
#include "alg.h"

int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k = k + 1;
            }
        }
    }
    return k;
}

int countPairs2(int* arr, int len, int value) {
    int l = 0;
    int r = len - 1;
    int k = 0;
    while (l < r) {
        int suma = arr[l] + arr[r];
        if (suma == value) {
            if (arr[l] == arr[r]) {
                int n = r - l + 1;
                k = k + n * (n - 1) / 2;
                break;
            }
            int ld = arr[l];
            int rd = arr[r];
            int indl = l;
            int lcount = 0;
            while (indl <= r && arr[indl] == ld) {
                lcount++;
                indl++;
            }
            int indr = r;
            int rcount = 0;
            while (indr >= l && arr[indr] == rd) {
                rcount++;
                indr--;
            }
            k = k + lcount * rcount;
            l = l + lcount;
            r = r - rcount;
        } else if (suma < value) {
            l++;
        } else {
            r--;
        }
    }
    return k;
}

int countPairs3(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int target = value - arr[i];
        if (target < arr[i]) {
            break;
        }
        int l = i + 1;
        int r = len - 1;
        int first = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                first = mid;
                r = mid - 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (first == -1) {
            continue;
        }
        l = first;
        r = len - 1;
        int last = first;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) {
                last = mid;
                l = mid + 1;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (arr[i] == target) {
            int n = last - i + 1;
            k = k + n * (n - 1) / 2;
            break;
        }
        int leftCount = 1;
        while (i + leftCount < len && arr[i + leftCount] == arr[i]) {
            leftCount++;
        }
        k = k + leftCount * (last - first + 1);
    }
    return k;
}
