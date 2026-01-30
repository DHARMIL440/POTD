class Solution {
  public:
    void rearrangeQueue(queue<int> &q) 
    {
        queue <int> q1, q2;
        int n = q.size()*0.5;
        while(q1.size() != n)
        {
            q1.push(q.front());
            q.pop();
        }
        while(q2.size() != n)
        {
            q2.push(q.front());
            q.pop();
        }
        
        while(n--)
        {
            q.push(q1.front());
            q.push(q2.front());
            q1.pop();
            q2.pop();
        }
        return ;
    }
};