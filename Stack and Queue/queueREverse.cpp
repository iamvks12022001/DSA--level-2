// You don't need to return anything, just modify the queue
void reverse(queue<int> &q)
{

    // Write your code here
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
   while(!s.empty()){
       q.push(s.top());
       s.pop();
   }
}