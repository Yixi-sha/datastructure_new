#include "../inc/numericalAnalysis.h"

#include <iostream>

namespace yixi{

using namespace std;

double NumericalAnalysis::multinomial_nest(int order, Array<double>& coefficients, double x, Array<double>& bases){
    if(coefficients.size() != (order + 1) || bases.size() != order){
        THROW_EXCEPTION(InvalidParameterException, "NumericalAnalysis::multinomial_nest");
    }

    double ret = coefficients[order];
    for(int i = order - 1; i >= 0; --i){ 
        ret = (x - bases[i]) * ret + coefficients[i];
    }

    return ret;
}

}