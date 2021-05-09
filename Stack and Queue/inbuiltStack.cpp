#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.empty()<<endl;

}