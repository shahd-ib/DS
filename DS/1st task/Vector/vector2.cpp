#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;        
        for (int i = s.length() - 1; i >= 0; i--) {            
            if (s[i] == ' ' && length == 0)
                continue;
            else if(s[i] != ' ')
                length++;            
            else
                break;
        }
        return length;
    }
};
int main()
{
    Solution S;
    cout<<S.lengthOfLastWord("luffy is still joyboy ");
}