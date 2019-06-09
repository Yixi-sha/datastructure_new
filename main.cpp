#include <iostream>



#include "./dataStructureLib/inc/duallinklist.h"
#include "./dataStructureLib/inc/sort.h"
#include "./dataStructureLib/inc/dynamicarray.h"
#include "./dataStructureLib/inc/gtree.h"
#include "./dataStructureLib/inc/avl.h"

using namespace std;
using namespace yixi;

class Test
{
public:
    int i;
    Test(int e = 0) : i(e)
    {
        cout << "Test(int e = 0)" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};



int main()
{
    cout << "yixi-test begin" << endl;
    Avl<int> t;
    LinkList<int> ll;

    ITNode<int>* obj = new ITNode<int>();
    obj->value = 4;

    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = 2;
    t.insert(obj);

    

    obj = new ITNode<int>();
    obj->value = 7;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = -1;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = 22;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = 100;
    t.insert(obj);

    obj = new ITNode<int>(); 
    obj->value = 101;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = 102;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = -2;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = -3;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = -10;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = -4;
    t.insert(obj);

    obj = new ITNode<int>();
    obj->value = 3;
    t.insert(obj);


    t.getLinkList(&ll);

    for(ll.moveTo(0); !ll.end(); ll.next(1))
    {
        cout << ll.current() << endl;
    }

    cout << "yixi-test end" << endl;

    return 0;
}
