/*
 * Дан упорядоченный массив целых чисел. Необходимо вывести максимум из числа положительных и
 * отрицательных чисел. 0 не относится ни к тем, ни к другим.
 *
 * Требуется решить задачу за log(n)
 *
 * LeetCode: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/
 */

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

// Ищем самое левое вхождение нуля в массив и возвращаем индекс вхождения.
// Если 0 не входит, возвращаем -1
int findLeftmostZero(const vector<int>& v) {
    int L = 0, R = static_cast<int>(v.size() - 1), index = -1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (v[mid] > 0) {
            R = mid - 1;
        }
        else if (v[mid] < 0) {
            L = mid + 1;
        }
        else {
            index = mid;
            R = mid - 1;
        }
    }
    return index;
}


// Ищем самое правое вхождение нуля в массив и возвращаем индекс вхождения.
// Если 0 не входит, возвращаем -1
int findRightmostZero(const vector<int>& v) {
    int L = 0, R = static_cast<int>(v.size() - 1), index = -1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (v[mid] > 0) {
            R = mid - 1;
        }
        else if (v[mid] < 0) {
            L = mid + 1;
        }
        else {
            index = mid;
            L = mid + 1;
        }
    }
    return index;
}

// В упорядоченном массиве, который не содержит 0, возвращает позицию, куда должен был бы быть вставлен 0
int zeroBetween(const vector<int>& v) {
    if (v[0] > 0) {
        return 0;
    }
    else if (v[v.size() - 1] < 0) {
        return static_cast<int>(v.size());
    }
    int L = 0, R = static_cast<int>(v.size() - 1), index = -1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (mid < v.size() - 1 && v[mid] < 0 and v[mid + 1] > 0) {
            return mid + 1;
        }
        else if (v[mid] > 0) {
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    return index;
}

// Подсчитываем, сколько в упорядоченном массиве отрицательных и положительных чисел
int maximumCount(vector<int>& v) {
    const int leftZero = findLeftmostZero(v);
    const int rightZero = findRightmostZero(v);

    if (leftZero != -1) {

        // в массиве все числа - нули
        if (leftZero == 0 && rightZero == v.size() - 1) {
            return 0;
        }
        return std::max(leftZero, static_cast<int>(v.size()) - rightZero - 1);
    }
    else {
        int zeroPos = zeroBetween(v);
        return std::max(zeroPos, static_cast<int>(v.size()) - zeroPos);
    }

}

int main() {
    vector<int> v;

    v = { -2,-1,-1, 1, 2, 3 };
    cout << maximumCount(v) << endl;

    v = { -3,-2,-1, 0, 0, 1, 2 };
    cout << maximumCount(v) << endl;

    v = { 5, 20, 66, 1314 };
    cout << maximumCount(v) << endl;

    v = { 0, 0 };
    cout << maximumCount(v) << endl;

    v = {-4, -3, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    cout << maximumCount(v) << endl;
    return 0;
}