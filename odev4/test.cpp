#include <iostream>
#include "lal.hpp"

using namespace std;

int main(){

    double* entries;
    
    double data[] = {1,2,3,4,1,1,1,1,2,2,2,2,3,3,3,3};

    entries = data;
    
    Matrix m1(entries,4,4);

    double data2[] = {1,2,3,4};

    entries = data2;

    Matrix m2(entries,2,2);

    m1.print();
    m2.print();

    m1.transpose();
    m1.print();

    Matrix m3 = m1 + m2;

    m3.print();

    double data3[] = {4,4,4,4};

    entries = data3;

    Matrix m4(entries,2,2);

    Matrix m5 = m2 * m4;

    m5.print();


    Vector *vectors = vectorArrayOlustur(2,3);
    
    vectors[0].print();
    
    vectors[1].print();

    cout << "l2norm : " << vectors[0].l2norm << endl; 

    cout<< "vector0 + vector1n\n";
    (vectors[0] + vectors[1]).print();

    cout<< "vector0 - vector1\n";
    (vectors[0] - vectors[1]).print();
    
    cout<< "vector0 * vector1\n";
    (vectors[0] * vectors[1]).print();
    

    Matrix v2m = vectorArray2Matrix(vectors,2,3);

    v2m.print();



    return 0;
}
