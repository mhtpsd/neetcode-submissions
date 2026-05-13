class MedianFinder {
public:

    // Max heap
    priority_queue<int> leftHeap;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> rightHeap;

    MedianFinder() {

    }

    void addNum(int num) {

        if (leftHeap.empty() || num <= leftHeap.top()) {
            leftHeap.push(num);
        } else {
            rightHeap.push(num);
        }

        // Balance heaps
        if (leftHeap.size() > rightHeap.size() + 1) {

            rightHeap.push(leftHeap.top());
            leftHeap.pop();
        }

        else if (rightHeap.size() > leftHeap.size() + 1) {

            leftHeap.push(rightHeap.top());
            rightHeap.pop();
        }
    }

    double findMedian() {

        if (leftHeap.size() > rightHeap.size()) {
            return leftHeap.top();
        }

        if (rightHeap.size() > leftHeap.size()) {
            return rightHeap.top();
        }

        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */