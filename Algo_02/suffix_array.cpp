#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(const string& text) {
    int n = text.size();
    vector<int> p(n), c(n), cnt(max(256, n), 0);

    for (int i = 0; i < n; i++)
        cnt[text[i]]++;
    for (int i = 1; i < 256; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--)
        p[--cnt[text[i]]] = i;

    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (text[p[i]] != text[p[i - 1]])
            classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int k = 0; (1 << k) < n; k++) {
        for (int i = 0; i < n; i++) {
            pn[i] = (p[i] - (1 << k) + n) % n;
        }

        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            int mid1 = (p[i] + (1 << k)) % n;
            int mid2 = (p[i - 1] + (1 << k)) % n;
            if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2])
                classes++;
            cn[p[i]] = classes - 1;
        }
        c = cn;
    }

    return p;
}

int binary_search(const string& text, const vector<int>& suffix_arr, const string& pattern) {
    int left = 0, right = text.size();
    int n = pattern.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (text.substr(suffix_arr[mid], n) < pattern) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    int start = left;
    if (start < text.size() && text.substr(suffix_arr[start], n) == pattern) {
        left = start;
        right = text.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (text.substr(suffix_arr[mid], n) <= pattern) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - start;
    }

    return 0;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> suffix_arr = suffix_array(text);

    cout << binary_search(text, suffix_arr, pattern) << endl;

    return 0;
}
