#include <iostream>

using namespace std;

int getMax(int val1, int val2) {
    return val1 > val2 ? val1 : val2;
}

int main()
{
    int n[] = {1, 2, 3, 4, 5};
    int size = sizeof(n) / sizeof(n[0]);

    int backtrack[size];

    int maxVal;

    for (int i = 0; i < size; i++)
        backtrack[i] = 0;

    for (int i = 0; i < size; i++)
    {
        long total = 0;
        int startJ = size-1;
        int j = startJ;
        for (; j >= 0 ;j--)
        {
            // cout << "[" << j << "] = " << n[j] << " + " << "total:" << total << endl;
            if (!i) {
                // cout << "startJ:" << startJ << endl;
                if(startJ == size-1) {
                    total += n[j];
                    if (i == j) {
                        if (startJ) {
                            j = startJ--;
                            if (!i) {
                                // cout << "COLLECT VALUE:" << total << endl;
                                // cout << "J:" << j << " I:" << i << endl;
                                // cout << "size - j:" << size - j -1 << endl;
                                backtrack[size - j - 1] = total;
                                // cout << "backtrack[0]:" << backtrack[0] << endl;
                                maxVal = total;
                            }
                        }
                    }
                } 

                if (startJ < size-1) {
                    if(j <= 1) break;
                    // cout << "J:" << j << " I:" << i << endl;
                    total += (n[j] * -1); 
                    backtrack[size - j -(i ? +1 : 0)] = total;
                    // cout << "saving at:" << size - j -(i ? +1 : 0) << endl;
                    // cout << "COLLECT VALUE:" << total << endl;
                    maxVal = getMax(maxVal, total);
                }
            } else {
                
                // cout << "J:" << j << " I:" << i << endl;
                // for (int w = 0; w < size; w++) {
                //     cout << backtrack[w] << " ";
                // }
                // cout << endl;
                total = backtrack[size - 1 - j] + (n[i - 1] * -1);
                // cout << "COLLECT VALUE:" << total << endl;
                backtrack[size - 1 - j] = total;
                maxVal = getMax(maxVal, total);
                // break;
            }
            // cout << "[" << i << "]" << " a " << "[" << j << "] = " << total << endl;
        }
    }
    cout << maxVal << endl;
}