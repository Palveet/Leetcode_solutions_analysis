class MovingAverage {
public:
queue<int>q;
double sum =0;
int s = 0;
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        if(q.size()<s){
            q.push(val);
            sum+=val;
        } else if(q.size()==s){
            int front = q.front();
            q.pop();
            q.push(val);
            sum+=val-front;
        }
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

//TC:O(1)
//SC:O(size)