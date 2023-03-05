class Solution{
public:	
	int maxSubstring(string s) {
	    int maxVal = 0, contSum = 0;
	    for(int i = 0; i < s.length() ; i++) {
	        contSum += ((s[i] - '0') == 0)  ? 1 : -1;
	        if(contSum < 0) contSum = 0;
	        maxVal = max(maxVal, contSum);
	    }
	    return maxVal == 0 ? -1 : maxVal;
	}
};