// Given a string s, find the length of the longest substring without duplicate characters.

int lengthOfLongestSubstring(char* s) {

    int subs[256] = {0};

    int l = 0;
    int max = 0;

    for(int r=0; s[r]!='\0'; r++){
        subs[(unsigned char) s[r]]++;

        while(subs[(unsigned char)s[r]] > 1){
            subs[(unsigned char)s[l]]--;
            l++;
        }

        int currLen = r - l + 1;

        if(currLen > max){
            max = currLen;
        }  
    }
    return max;
}
