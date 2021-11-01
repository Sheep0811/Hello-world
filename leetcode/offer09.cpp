class CQueue {
    stack <int> stack1,stack2;
public:
    CQueue() {
        while ( !stack1.empty())stack1.pop();
        while (!stack2.empty()) stack2.pop();
   } 
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(!stack2.empty())
        {
            int ans=stack2.top();
            stack2.pop();
            return ans;
        }
        else if(!stack1.empty())
        {
            return -1;
        }
        else
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            int ans=stack2.top();
            stack2.pop();
            return ans;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */