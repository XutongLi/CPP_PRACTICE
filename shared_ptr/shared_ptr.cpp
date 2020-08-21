/*************************************************************************
    > File Name: shared_ptr.cpp
    > Author: lixutong
    > Created Time: 2020-08-20 11:26:16
    > Description: 
 ************************************************************************/

#include <iostream>
#include <string>
#include "shared_ptr.h"
using namespace std;

int main() {
    cout << "p1(new string(\"abc\"))" << endl;
    Shared_ptr<string> p1(new string("abc"));
    cout << "p1: " << *p1 << " " << p1.use_count() << endl;

    cout << "p2(new string(\"efg\"))" << endl;
    Shared_ptr<string> p2(new string("efg"));
    cout << "p2: " << *p2 << " " << p2.use_count() << endl;

    cout << "p3(p2)" << endl;
    Shared_ptr<string> p3(p2);
    cout << "p1: " << *p1 << " " << p1.use_count() << endl;
    cout << "p2: " << *p2 << " " << p2.use_count() << endl;
    cout << "p3: " << *p3 << " " << p3.use_count() << endl;

    cout << "p1 = p3" << endl;
    p1 = p3;
    cout << "p1: " << *p1 << " " << p1.use_count() << endl;
    cout << "p2: " << *p2 << " " << p2.use_count() << endl;
    cout << "p3: " << *p3 << " " << p3.use_count() << endl;

    return 0;
}



