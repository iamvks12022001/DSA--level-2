#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    
    queue<char> q;
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.push('e');
    q.push('f');

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

   while(!q.empty()){
       cout<<q.front()<<endl;
       q.pop();
   }
}