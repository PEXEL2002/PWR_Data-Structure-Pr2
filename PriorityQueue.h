#pragma once
template<typename T>
class PriorityQueue{
    public:
        virtual void insert(T e, int p) = 0;
        virtual T extractMax() = 0;
        virtual T findMax() = 0;
        virtual int modyfiKey(T e, int p) = 0;
        virtual int getSize() = 0;
};