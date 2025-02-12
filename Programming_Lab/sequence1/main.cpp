#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include "print.h"
using namespace std;
class IntSequence
{
private:
    int value;
public:
    IntSequence (int initialValue) // constructor
        : value(initialValue)
    {
    }
    int operator() ()
    {
        return ++value;
    }
};
int main()
{
    list<int> coll;
    generate_n (back_inserter(coll), // start
                9, // number of elements
                IntSequence(1)); // generates values, starting with 1
    PRINT_ELEMENTS(coll);
// replace second to last element but one with values starting at 42
    generate (next(coll.begin()), // start
              prev(coll.end()), // end
              IntSequence(42)); // generates values, starting with 42
    PRINT_ELEMENTS(coll);
}
