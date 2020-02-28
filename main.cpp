#include <iostream>
#include <cstdlib>
#include <ctime>

#include "./dataStructureLib/inc/duallinklist.h"
#include "./dataStructureLib/inc/sort.h"
#include "./dataStructureLib/inc/dynamicarray.h"
#include "./dataStructureLib/inc/gtree.h"
#include "./dataStructureLib/inc/avl.h"
#include "./dataStructureLib/inc/myVector.h"

using namespace std;
using namespace yixi;

class Test
{
public:
    int i;
    Test(int e = 10) : i(e)
    {
        cout << "Test(int e = 0)" << endl;
    }
    Test(const Test& obj){
        i  = obj.i;
        cout << "Test(const Test&)" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};




int main()
{
    cout << "yixi-test begin" << endl;
    MyVector<Test> v;
    Test t;
    v.push_back(t);
    v.push_back(t);
    v.push_back(t);
    v.push_back(t);
    v.push_back(t);
    cout << "yixi-test end" << endl;

    return 0;
}
