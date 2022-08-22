// https://leetcode.cn/problems/design-circular-queue/
// 题解：循环队列，先进先出，超出队尾则回到前面。
class MyCircularQueue {
private:
    vector<int> nums;
    int head, tail, capacity;
public:
    MyCircularQueue(int k) {
        capacity = k+1;
        head = tail = 0;
        nums = vector<int>(k+1,0);
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        nums[tail % capacity] = value;
        tail = (tail + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;
        head = (head + 1) % capacity;
        return true;
    }

    int Front() {
        if(isEmpty()) return -1;
        return nums[head];
    }

    int Rear() {
        if(isEmpty()) return -1;
        return nums[(tail - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return (head == tail);
    }

    bool isFull() {
        return abs(tail - head + 1) % capacity == 0;
    }
};

/*
["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]
[[3],[1],[2],[3],[4],[],[],[],[4],[]]

[null,true,true,true,false,3,true,true,true,4]
*/

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
