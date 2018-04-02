#include <iostream>
#include <string>
#include "ADTs\BinaryHeap.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

int main(void)
{
    BinaryHeap<int> pq{};
    RandomNumberGenerator rng{};
    
    for (int i = 0; i < 10; i++)
    {
        pq.enqueue(rng.getRandomNumber(0, 25));
    }

    while (pq.isEmpty() == false)
    {
        cout << pq.dequeue() << endl;
    }

    return 0;
}