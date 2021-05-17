class Solution {
public:
    int secondHighest(string s) {
        set<int> digits;
	    copy_if(begin(s), end(s), inserter(digits, begin(digits)), ::isdigit);
        return digits.size() > 1 ? *next(rbegin(d)) - '0' : -1;
    }
}
