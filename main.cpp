#include <iostream>
#include <cstdlib>
#include<ctime>


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
    clock_t startTime,endTime;
    
    DynamicArray<int> test1(5000);
    DynamicArray<int> test2(5000);
    for(int i = 0; i < test1.size(); i++)
    {
        test1[i] = rand() % 1000 -  500;
        test2[i] = rand() % 1000 -  500;
    }
    startTime = clock();
    Sort<int>::merge(test1);
    endTime = clock();
    cout << "merge() is " << Sort<int>::judge(test1);
    cout << "The run time is: " <<(double)(endTime - startTime) / 1000 << "ms" << endl;

    startTime = clock();
    Sort<int>::shell_insert(test2);
    endTime = clock();
    cout << "shell_insert() is " << Sort<int>::judge(test2);
    cout << "The run time is: " <<(double)(endTime - startTime) / 1000 << "ms" << endl;

    cout << "yixi-test end" << endl;

    return 0;
}
