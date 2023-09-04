#include <iostream>

using namespace std;

int getMax(int val1, int val2) {
    return val1 > val2 ? val1 : val2;
}

int main()
{
    int n[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int size = sizeof(n) / sizeof(n[0]);

    int backtrack[size];

    int maxVal;

    for (int i = 0; i < size; i++)
        backtrack[i] = 0;

    for (int i = 0; i < size; i++) {
        backtrack[0] += n[size - 1 - i];
    }

    maxVal = backtrack[0];

    for (int i = 0; i < size - 2; i++) {
        backtrack[i + 1] = backtrack[i] + (n[size - i - 1] * -1);
        maxVal = getMax(maxVal, backtrack[i + 1]);
    }

    long j = 0;
    for (int i = 0; i < size - 1; i++) {
        backtrack[i] = backtrack[i] + (n[j] * -1);
        maxVal = getMax(backtrack[i], maxVal);
        if (i == (size - 3 - j)) {
            j++;
            i = -1;
            if (j == (size - 2)) break;
            continue;
        }
    }

    cout << maxVal << endl;
}