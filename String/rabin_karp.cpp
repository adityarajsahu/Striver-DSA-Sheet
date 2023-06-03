#include <bits/stdc++.h>
using namespace std;

bool areEqual(const string& str1, const string& str2, int start1, int start2, int length) {
    for (int i = 0; i < length; i++) {
        if (str1[start1 + i] != str2[start2 + i])
            return false;
    }
    return true;
}

void rabinKarp(const string& text, const string& pattern) {
    int textSize = text.size();
    int patternSize = pattern.size();
    int prime = 101;
    int textHash = 0; 
    int patternHash = 0;
    int h = 1;

    for (int i = 0; i < patternSize - 1; i++) {
        h = (h * 256) % prime;
    }

    for (int i = 0; i < patternSize; i++) {
        textHash = (256 * textHash + text[i]) % prime;
        patternHash = (256 * patternHash + pattern[i]) % prime;
    }

    for (int i = 0; i <= textSize - patternSize; i++) {
        if (textHash == patternHash && areEqual(text, pattern, i, 0, patternSize)) {
            cout << "Pattern found at: " << i << endl;
        }

        if (i < textSize - patternSize) {
            textHash = (256 * (textHash - text[i] * h) + text[i + patternSize]) % prime;

            if (textHash < 0)
                textHash += prime;
        }
    }
}

int main() {
    string text = "ababcababcabc";
    string pattern = "abc";
    rabinKarp(text, pattern);
    return 0;
}
