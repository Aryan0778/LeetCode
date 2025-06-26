class Solution {
public:
    bool isPossible(const string& s, int m, int k) {
        int n = s.size();
        int a = k, b = k, c = k;
        int tail = n - m;

        // Initial window: last m characters
        for (int i = n - m; i < n; ++i) {
            if (s[i] == 'a') a--;
            else if (s[i] == 'b') b--;
            else c--;
        }

        if (a <= 0 && b <= 0 && c <= 0) return true;

        for (int i = n; i < n + m; ++i) {
            // Add new character from the front (circularly)
            if (s[i % n] == 'a') a--;
            else if (s[i % n] == 'b') b--;
            else c--;

            // Remove old character from tail
            if (s[tail % n] == 'a') a++;
            else if (s[tail % n] == 'b') b++;
            else c++;
            tail++;

            if (a <= 0 && b <= 0 && c <= 0) return true;
        }

        return false;
    }

    int takeCharacters(string str, int k) {
        int n = str.size();

        // ✅ Check if it is even possible to take k of each character
        int ca = count(str.begin(), str.end(), 'a');
        int cb = count(str.begin(), str.end(), 'b');
        int cc = count(str.begin(), str.end(), 'c');
        if (ca < k || cb < k || cc < k) return -1;

        int s = 0, e = n, ans = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (isPossible(str, m, k)) {
                ans = m;
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return ans;
    }
};
