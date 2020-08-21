/*************************************************************************
    > File Name: shared_ptr.h
    > Author: lixutong
    > Created Time: 2020-08-20 20:41:53
 ************************************************************************/

#ifndef SHARED_PTR_H
#define SHARED_PTR_H 

#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Shared_ptr
{
private:
    T *ptr;
    int *count;
public:
    Shared_ptr() : ptr(nullptr), count(nullptr) {}
    Shared_ptr(T *_ptr) : ptr(_ptr), count(new int(1)) {}
    Shared_ptr(Shared_ptr<T> &others) : ptr(others.ptr), count(&(++ *others.count)) {}

    Shared_ptr<T> &operator=(Shared_ptr<T> &others) {
        if (&others == this)
            return *this;
        ++ *others.count;
        if (ptr && -- *count == 0) {
            delete ptr;
            delete count;
            cout << "delete" << endl;
        }
        this->ptr = others.ptr;
        this->count = others.count;
        return *this;
    }

    int use_count() { return *count; }
    T *operator->() { return ptr; }
    T &operator*()  { return *ptr; }

    ~Shared_ptr() {
        if (ptr && -- *count == 0) {
            delete ptr;
            delete count;
            cout << "delete" << endl;
        }
    }
};



#endif /* SHARED_PTR_H */
