#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(args...)  cout << #args << " = " << args << endl;

string binary_add(string ans, string seg_str) {
    string result = "";
    int temp = 0;
    int n = ans.size() - 1;
    int m = seg_str.size() - 1;
    while (n >= 0 || m >= 0 || temp == 1) {
        temp += ((n >= 0) ? ans[n] - '0' : 0);
        temp += ((m >= 0) ? seg_str[m] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        n--;
        m--;
    }
    return result;
}

string binary_fun(ll num) {
    if (num == 0) return "0";

    string binary = "";
    while (num > 0) {
        binary += (num % 2) + '0';
        num /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

bool isValidBCD(string& s) {
    if (s.size() % 4 != 0) return false;
    
    for (int i = 0; i < s.size(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; j++) {
            if (s[i+j] != '0' && s[i+j] != '1') return false;
            value = value * 2 + (s[i+j] - '0');
        }
        if (value > 9) return false;
    }
    return true;
}

int32_t main()
{
    cout << "\nEnter the BCD Number: ";
    string bcd;
    cin >> bcd;
    
    if(!isValidBCD(bcd)) {
        cout << "Invalid BCD number.";
        return 1;
    }
    
    string ans = "";
    ll total_seg = bcd.size()/4;

    for(int i = 0; i < bcd.size(); i+=4) {
        ll seg = 0;
        for(int j = 0; j < 4; j++) {
            seg += (1<<(3-j)) * (bcd[i+j]-'0');
        }

        ll mul = 1;
        for(int j = 0; j < total_seg-1; j++) 
            mul *= 10;
        total_seg--;
        seg *= mul;

        string seg_str = binary_fun(seg);
        ans = binary_add(ans, seg_str);
    }

    cout << "Binary Number: " << ans << endl;

    return 0;
}
