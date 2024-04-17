#pragma once
template<typename T>
struct element
{
    T value;
    int priority;
    element(T val, int prio) : value(val), priority(prio) {};
    element() : value(T()), priority(0) {};
};
