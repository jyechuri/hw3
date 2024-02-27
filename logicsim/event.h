#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    // write the operator() required to make this a functor that compares Events by time
    /* The operator() will take two Event*'s as it’s input and needs to sort them using 
     the Event::time data member in such a way that your heap will be a min-heap. */
    bool operator()(Event* one, Event* two)
    {
        // true if one is greater than two and false otherwise
        return (one-> time < two ->time);
    }
} EventLess;
	
#endif
