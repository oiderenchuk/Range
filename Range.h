#ifndef __RANGE_H__
#define __RANGE_H__

#include <iostream>
#include <vector>

#define noop (void)0
//if (condition) noop; else do_something();

// A Range Module is a module that tracks ranges of numbers.
// Your task is to design and implement an efficient version of
// this module that has less space and time complexity. Yes,
// of course, there can multiple implementations of this, but we
// are not looking at a single one. Make sure you choose the right
// data­structures so that your implementation is efficient.

class RangeModule
{
    
public:
    struct RangeData{
        int lower;
        int upper;
    };

    std::vector<RangeData> listRange;
    void GetListRange();
    void SortRanges();

    // AddRange: Given an input range it starts tracking the range.
    // Eg: AddRange(10, 200) – starts tracking range 10 – 200
    // AddRange(150, 180) – starts tracking range 150 – 180.
    // AddRange(250, 500) – starts tracking range 250 – 500.
    // Make sure that you efficiently track overlapping ranges.
    void AddRange(int lower, int upper);

    // QueryRange: Given an input range, this returns whether the range
    // is being tracked or not. Eg: QueryRange(50, 100) –
    // Returns TRUE as this is being tracked
    // QueryRange(180, 300) – Returns False as only a partial of this range
    // is being tracked QueryRange(600, 1000) – Returns False as this range is not tracked
    bool QueryRange(int lower, int upper);

    // DeleteRange: Given input range is untracked after this call has been made.
    // If the range does not exists then it is a no­op.
    // Eg: DeleteRange(50, 150) – stops tracking range 50 – 150
    void RemoveRange(int lower, int upper);

    // You do NOT need to make Range module persistent (writable/readable on disk).

    // In­memory implementation is fine.
    // You do NOT need to submit a test program that uses these APIs . However, feel free
    // to do so if it would be helpful to you in designing or debugging the API.

    // Make sure the work that you submit compiles. It is NOT mandatory that you implement
    // all the interfaces. But make sure that your design and choice of data structure is
    // good enough to implement all interfaces if you had considerably more time.

    // You may use the C standard library, but no other libraries.
    // All source code must be your own.
    // Please strive for:
    // 1. Clean design—Make your code readable and reuseable where possible; give thought
    // to your interface
    // 2. Efficiency—Try to make each functionality as fast as possible
    // 3. Robustness—Handle error sensibly; handle large or unusual sets of words.

    // Please briefly explain your design choices in your comments.

};

#endif
