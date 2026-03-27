/*
 * Дан массив различных целых чисел, в котором требуется найти определённый элемент.
 * Если элемент принадлежит массиву, необходимо вернуть его индекс.
 * Если же элемент не принадлежит массиву, необходимо вернуть индекс той позиции,
 * на которую он должен быть поставлен.
 *
 * LeetCode: https://leetcode.com/problems/search-insert-position/description/
 */

#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;

int searchInsert(const vector<int>& v, int target) {

    // Проверяем, придётся ли вставлять элемент за границы массива
    if (target < v[0]) {
        return 0;
    }
    else if (target > v[v.size() - 1]) {
        return static_cast<int>(v.size());
    }

    int L = 0, R = static_cast<int>(v.size()) - 1;

    while (L <= R) {

        int mid = L + (R - L) / 2;
        if (v[mid] == target) {
            return mid;
        }
        // Если находим позицию для элемента, возвращаем индекс позиции
        else if (target > v[mid] && target < v[mid + 1]) {
            return mid + 1;
        }
        else if (target < v[mid]) {
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v = {1, 3, 5, 7, 10, 12};
    cout << searchInsert(v, 2) << endl;
    cout << searchInsert(v, 8) << endl;
    cout << searchInsert(v, 22) << endl;

    v = {1, 4};
    cout << searchInsert(v, 5) << endl;

    v = {3, 3, 5, 5, 6};
    cout << searchInsert(v, 4) << endl;
    cout << searchInsert(v, 3) << endl;
    cout << searchInsert(v, 5) << endl;
    return 0;
}
