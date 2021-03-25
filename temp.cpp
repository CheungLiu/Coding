#include <iostream>
#include <string>
#include <iterator>
#include <vector>

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

using namespace std;

int main()
{
    Interval val = Interval(2, 3);
    vector<Interval> intervals = {Interval(2, 3), Interval(4, 7), Interval(8, 11)};
    vector<Interval>::iterator iter;
    // intervals.
    Interval I = *iter;
    cout << iter->end << endl;
    return 0;
}