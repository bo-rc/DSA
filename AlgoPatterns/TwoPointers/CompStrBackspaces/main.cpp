/**
 * 
Comparing Strings containing Backspaces (medium) #
Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
Example 2:

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
Example 3:

Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x" respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
Example 4:

Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
 */

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>

class BackspaceCompare
{
public:
    static bool compare(const string &str1, const string &str2)
    {
        int ptr1 = str1.size() - 1;
        int ptr2 = str2.size() - 1;

        for (; ptr1 > 1 and ptr2 > 1;)
        {
            //
            auto ch1 = str1.at(ptr1);
            auto ch2 = str2.at(ptr2);

            if (ch1 == '#')
            {
                int num_backspace = count('#', str1, ptr1);
                ptr1 -= 2 * num_backspace;
                ch1 = str1.at(ptr1);
            }

            if (ch2 == '#')
            {
                int num_backspace = count('#', str2, ptr2);
                ptr2 -= 2 * num_backspace;
                ch2 = str2.at(ptr2);
            }

            // do comparison last
            if (ch1 == ch2)
            {
                --ptr1;
                --ptr2;
                continue;
            }
            else
                return false;
        }

        return true;
    }

private:
    static int count(char c, const string &str, int pos)
    {
        int counter = 0;
        while (str[pos--] == c)
        {
            ++counter;
        }
        return counter;
    }
};

int main(int argc, char *argv[])
{
    cout << boolalpha << BackspaceCompare::compare("xy#z", "xzz#") << endl;
    cout << boolalpha << BackspaceCompare::compare("xy#z", "xyz#") << endl;
    cout << boolalpha << BackspaceCompare::compare("xp#", "xyz##") << endl;
    cout << boolalpha << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}
