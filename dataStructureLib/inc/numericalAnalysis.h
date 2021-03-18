#ifndef NUMERICAL_ANALYSIS_H
#define NUMERICAL_ANALYSIS_H

#include "object.h"
#include "array.h"

namespace yixi{

class NumericalAnalysis : public Object{
private:
    NumericalAnalysis();

    NumericalAnalysis(const NumericalAnalysis& obj);
    NumericalAnalysis& operator =(const NumericalAnalysis& obj);

public:
    static double multinomial_nest(int order, Array<double>& coefficients, double x, Array<double>& bases);
};

}

#endif