#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <random>

#include "dataStructureLib/inc/numericalAnalysis.h"
#include "dataStructureLib/inc/staticarray.h"
#include "dataStructureLib/inc/dynamicarray.h"
#include "dataStructureLib/inc/sort.h"
using namespace std;
using namespace yixi;


int main()
{

    cout << "yixi-test begin" << endl;
    DynamicArray<int> array;
    uniform_int_distribution<int> u(-100,100);
    default_random_engine e;
    array.reSize(1000);
    for(int i = 0; i < 1000; ++i){
        array[i] = u(e);
    }
    Sort<int>::heap(array);
    for(int i = 0; i < 1000; ++i){
        cout << array[i] << "\t";
    }
    cout << endl;
    cout << Sort<int>::judge(array) << endl;
    cout << "yixi-test end" << endl;

    return 0;
}
