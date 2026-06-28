class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {

            // Skip non-alphanumeric from left
            while (start < end && !isalnum(s[start]))
                start++;

            // Skip non-alphanumeric from right
            while (start < end && !isalnum(s[end]))
                end--;

            // Compare after converting to lowercase
            if (tolower(s[start]) != tolower(s[end]))
                return false;

            start++;
            end--;
        }

        return true;
    }
};