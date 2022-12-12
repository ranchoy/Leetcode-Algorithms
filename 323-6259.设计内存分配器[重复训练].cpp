// https://leetcode.cn/contest/weekly-contest-323/problems/design-memory-allocator/
// 题解：模拟+优先队列priority_queue+结构体重载+静态函数，注意内存起始位置存在空闲空间的情况。
class Allocator {
private:
    int mem_total, mem_use;
    typedef struct Node{
        int mID, left, right;
        Node(int x, int y, int z): mID(x), left(y), right(z){};
        bool operator < (const Node &b) const {
            if(left == b.left) return right >= b.right; // sort as asc.
                return left >= b.left;
        }
    } MemNode;
    priority_queue<MemNode> pri_que;
public:
    Allocator(int n) {
        mem_total = n; mem_use = 0;
    }

    int allocate(int size, int mID) {
        if(mem_total - mem_use < size) return -1;
        if(pri_que.empty() && mem_total >= size) {
            MemNode node_new(mID, 0, size - 1);
            pri_que.push(node_new);
            return 0;
        }

        priority_queue<MemNode> pri_temp = pri_que;
        MemNode node_pre = pri_temp.top(); pri_temp.pop();
        if(node_pre.left >= size) {
            MemNode node_new(mID, 0, size - 1); // imporant, free size in [0,node_pre.left-1].
            pri_que.push(node_new);
            return 0;
        }

        while(!pri_temp.empty()) {
            MemNode node = pri_temp.top(); pri_temp.pop();

            if(node.left - node_pre.right - 1 >= size) {
                MemNode node_new(mID, node_pre.right + 1, node_pre.right + size);
                pri_que.push(node_new);
                return node_pre.right + 1;
            }
            node_pre = node; // update
        }

        if(mem_total - 1 - node_pre.right >= size) {
            MemNode node_new(mID, node_pre.right + 1, node_pre.right + size);
            pri_que.push(node_new);
            return node_pre.right + 1;
        }

        return -1;
    }

    int free(int mID) {
        int release_mem_size = 0;
        priority_queue<MemNode> pri_temp = pri_que, pri_bak;

        while(!pri_temp.empty()) {
            MemNode node = pri_temp.top(); pri_temp.pop();

            if(node.mID == mID) {
                release_mem_size += node.right - node.left + 1;
            } else {
                pri_bak.push(node);
            }
        }
        pri_que = pri_bak;

        return release_mem_size;
    }
};

/*
["Allocator","allocate","allocate","free","free"]
[[7],[3,1],[5,2],[1],[3]]
["Allocator", "allocate", "allocate", "allocate", "free", "allocate", "allocate", "allocate", "free", "allocate", "free"]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
["Allocator","allocate","allocate","allocate","allocate","free","free","free","allocate","allocate","allocate","allocate","free","free","free","free","free","free","free","allocate","free","free","allocate","free","allocate","allocate","free","free","free","allocate","allocate","allocate","allocate","free","allocate","free","free","allocate","allocate","allocate","allocate","allocate","allocate","allocate","free","free","free","free"]
[[50],[12,6],[28,16],[17,23],[50,23],[6],[10],[10],[16,8],[17,41],[44,27],[12,45],[33],[8],[16],[23],[23],[23],[29],[38,32],[29],[6],[40,11],[16],[22,33],[27,5],[3],[10],[29],[16,14],[46,47],[48,9],[36,17],[33],[14,24],[16],[8],[2,50],[31,36],[17,45],[46,31],[2,6],[16,2],[39,30],[33],[45],[30],[27]]

[null,0,-1,3,0]
[null,0,1,2,1,3,1,6,3,-1,0]
[null,0,12,-1,-1,12,0,0,-1,-1,-1,0,0,0,28,0,0,0,0,12,0,0,-1,0,-1,-1,0,0,0,-1,-1,-1,-1,0,-1,0,0,-1,-1,-1,-1,-1,-1,-1,0,12,0,0]
*/

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
