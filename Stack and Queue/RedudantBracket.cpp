/*
  Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.
Note :
A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.
For Example :
((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
While (a + (b*c)) does not have any pair of redundant brackets. 
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

The first line of each test case contains a string denoting the expression.
Output Format :
For each test case, print “Yes” if the given expression contains at least one pair of redundant brackets, else print “No”.
Note :
You don’t need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 50
3 <= |S| <= 10^4

Where ‘T’ denotes the number of test cases, ‘|S|’ denotes the length of the given expression.

Time Limit: 1 sec
Sample Input 1 :
2
(a+b)
(a+c*b)+(c))
Sample Output 1 :
No
Yes
Explanation Of Sample Input 1 :
In the first test case, there are no redundant brackets. Hence, the output is “No”. 


In the second test case, the brackets around the alphabet ‘c’( index 8 and index 10) are redundant. Hence the output is “Yes”.
Sample Input 2 :
2
(a*b+(c/d))
((a/b))
Sample Output 2 :
No
Yes
Explanation Of Sample Input 2 :
In the first test case, there are no redundant brackets. Hence, the output is “No”. 


In the second test case, the brackets around the subexpression “(a+b)” ( index 0 and index 6) are redundant. Hence the output is “Yes”.
*/

#include<stack>
bool findRedundantBrackets(string &A)
{
    //    Write your code here
   stack<char> s;
    auto size = A.length();
    auto i = 0;
    while(i<size)
    {
        char c = A[i];
        if (c == '(' || c == '+' || c == '*' || c == '-' || c == '/')
            s.push(c);
        else if (c == ')')
        {
            if (s.top() == '(')
                return 1;
            else
            {
                while (!s.empty() && s.top() != '(')
                    s.pop();
                s.pop();
            }
        }
        ++i;
    }
    return 0;
}

