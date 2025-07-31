
class SmallestInfiniteSet {
private:
    int current;
    set<int> addedBackSet;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            addedBackSet.erase(smallest);
            return smallest;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current && addedBackSet.find(num) == addedBackSet.end()) {
            addedBackSet.insert(num);
            minHeap.push(num);
        }
    }
};


/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */