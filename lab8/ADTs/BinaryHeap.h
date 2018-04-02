
#ifndef HEAP_H
#define HEAP_H

#include "Vector.h"
#include "Queue.h"
using namespace std;

template<typename T>
class BinaryHeap : Queue<T>
{
private:
    Vector<T> _items;

    void buildHeap()
    {
        for (int i = _items.getSize() / 2; i >= 0; i--)
        {
            adjustHeap(i);
        }
    }

    //Percolates the item specified at by index down into its proper location within a heap.  Used
    //for dequeue operations and array to heap conversions
    void adjustHeap(int index)
    {
        //Grab a copy of whatever we're examining.
        T item = _items[index];

        //First leaf node is size / 2.
        int first_leaf_location = _items.getSize() / 2;

        //Base case, cannot go any further.
        while (index < first_leaf_location)
        {

            //Variables that help us track children.
            //This is potenially dangerous as either or both left child and right child may be beyond array bounds.
            int left_child_index = index * 2 + 1;
            int right_child_index = index * 2 + 2;
            int most_important_index = left_child_index;

            //If we have a right child, we may need to swap most_important_index
            if (index < first_leaf_location - 1)
            {
                if (_items[right_child_index] < _items[left_child_index])
                {
                    most_important_index = right_child_index;
                }
            }

            if (item > _items[most_important_index])
            {
                //Swap elements.
                _items[index] = _items[most_important_index];
                _items[most_important_index] = item;

                //Update index.
                index = most_important_index;
            }
            else
            {
                //No swap needed. Done with process.
                return;
            }
        }
    }

public:
    BinaryHeap()
    {
    }

    BinaryHeap(const Vector<T> &unsorted)
    {
        for (int i = 0; i < unsorted.getSize(); i++)
        {
            _items.addElement(unsorted.getElementAt(i));
        }
        buildHeap();
    }

    bool isEmpty()
    {
        return _items.getSize() == 0;
    }

    virtual int getSize() const
    {
        return _items.getSize();
    }

    //enqueue item into tree.
    virtual void enqueue(const T &item)
    {
        //Code written in Lab 8
        
        //Adding item to the tree such that completeness rule is maintained.
        _items.addElement(item);

        //At this point we cannot guarantee that the importance rule is true.
        //We must adjust the heap until the newly placed item is in the correct location.
        int current_index = _items.getSize() - 1;
        
        //Tracks location of new item's parent.
        int parent_index = (current_index - 1) / 2;

        //Keep going until new item is in the correct location
        while (parent_index > -1 && _items[parent_index] > item)
        {
            //swap parent and child, and update indecies.
            _items[current_index] = _items[parent_index];
            _items[parent_index] = item;
            current_index = parent_index;
            parent_index = (current_index - 1) / 2;
        }
    }

    virtual T& getFirst()
    {
        return _items[0];
    }

    virtual const T& getFirst() const
    {
        return _items[0];
    }

    virtual T dequeue()
    {
        //We will return the top element to the user.
        T first_item = _items[0];

        //replace top with last element.
        int last_position = _items.getSize() - 1;
        _items[0] = _items[last_position];
        _items.removeElementAt(last_position);

        //If size is greater than 1, then we need to have the item percolate down until it finds proper place.
        if (_items.getSize() > 1)
        {
            adjustHeap(0);
        }

        return first_item;
    }

};

#endif