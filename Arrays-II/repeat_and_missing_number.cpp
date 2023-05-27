#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int len = a.size();
    vector<int> hash(len + 1, 0);

    for (int i = 0; i < len; i++) {
        hash[a[i]]++;
    }

    int repeating, missing;
    for (int i = 1; i <= len; i++) {
        if (hash[i] == 2) {
            repeating = i;
        }
        else if (hash[i] == 0) {
            missing = i;
        }
    }
    return {repeating, missing};
}