#include <iostream>
#include "lal.hpp"

int main(){

    double* dizi;
    double dizi2[] = {1,2,3,4,1,1,1,1,2,2,2,2,3,3,3,3};

    dizi = dizi2;

    Matrix v1(dizi,4,4);

    double dizi3[] = {1,2,3,4};

    dizi = dizi3;

    Vector v2(dizi,4);

    Vector v3 = v1 * v2;

    v3.print();

    return 0;
}
