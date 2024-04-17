#pragma once
template<typename T>
class PriorityQueue{
    public:
        virtual void insert(T e, int p);
        virtual T extractMax();
        virtual T findMax();
        virtual int modyfiKey(T e, int p);
        virtual int getSize();
};