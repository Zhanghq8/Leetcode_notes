#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder()
        : left_(data_.end())
        , right_(data_.end()) {
    }
    
    void addNum(int num) {
        if (data_.empty()) {
            data_.insert(num);
            left_ = data_.begin();
            right_ = data_.begin();
            return;
        }
        data_.insert(num);
        if (!(data_.size() % 2)) {
            if (num >= *right_) {
                right_++;
            } else {
                left_--;
            }
        } else {
            if (num >= *right_) {
                left_ = right_;
            } else {
                right_--;
                left_ = right_;
            }
        }
        
    }
    
    double findMedian() {
        return (static_cast<double> (*left_) + *right_)/2;
    }
private:
    multiset<int> data_;
    multiset<int>::iterator left_;
    multiset<int>::iterator right_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */