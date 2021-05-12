#include <stack>
void fillstack(stack<int> &st,stack<int> &s2)
{
    if(st.empty())
    {
        return;
    }
    s2.push(st.top());
    st.pop();
    fillstack(st,s2);
}

void printstack(stack<int> &s2)
{
    if(s2.empty())
    {
        return;
    }
    cout<<s2.top()<<" ";
    s2.pop();
    printstack(s2);
}
void reverseStack(stack<int> &st) {
    // Write your code here
    stack<int> s2;
    fillstack(st,s2);
    printstack(s2);
}