#include <iostream>
#include <vector>
#include <map>

// Given an array of integers, find the one that appears an odd number of times.

// There will always be only one integer that appears an odd number of times.

// Examples
// [7] should return 7, because it occurs 1 time (which is odd).
// [0] should return 0, because it occurs 1 time (which is odd).
// [1,1,2] should return 2, because it occurs 1 time (which is odd).
// [0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
// [1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).

int findOdd(const std::vector<int> &numbers)
{
    std::vector<int> v(numbers);
    std::map<int, int> oddmap;

    for (auto pair : numbers)
    oddmap[pair]++;

    for(auto pair:oddmap)
    if(pair.second%2)
    return pair.first;

    return 0;
};

int main()
{
    std::vector <int> vec = {3,3,2,1,5,5,2};
    std::cout<<findOdd(vec);
}